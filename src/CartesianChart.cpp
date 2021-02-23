#include "SFPlot/CartesianChart.hpp"
#include <limits>
#include "SFPlot/PlotConfig.hpp"

namespace sf
{

/**
 * Drawing function derived from sf::Drawable
 *
 * @param target       Render Target
 * @param states       Render States
 *
 */
void CartesianChart::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    target.draw(axes_, states);
    for (const auto& elem : data_set_) {
        switch (elem->type) {
        case CartesianData::PLOT_TYPE::POINT:
            drawPoint(*elem, target, states, axes_.getRangeX(), axes_.getRangeY());
            break;
        case CartesianData::PLOT_TYPE::LINE:
            drawLine(*elem, target, states, axes_.getRangeX(), axes_.getRangeY());
            break;
        default:
            break;
        }
    }
}

/**
 * Draws data with points on chart
 *
 * @param elem         Data to plot
 * @param target       Render Target
 * @param states       Render States
 * @param x_range      X range of plotting area
 * @param y_range      Y range of plotting area
 *
 */
void CartesianChart::drawPoint(const CartesianData& elem, sf::RenderTarget& target, sf::RenderStates states, const std::pair<double, double>& x_range, const std::pair<double, double>& y_range) const
{
    /* draw data */
    for (auto it = elem.data.cbegin(); it != elem.data.cend(); it++) {
        constexpr double POINT_RADIUS = 5.f;
        const auto x = (it->x - x_range.first) / (x_range.second - x_range.first) * (axes_.DIMENSION.x - axes_.MARGIN.x) + axes_.MARGIN.x;
        const auto y = (axes_.DIMENSION.y - axes_.MARGIN.y) - (it->y - y_range.first) / (y_range.second - y_range.first) * (axes_.DIMENSION.y - axes_.MARGIN.y);

        sf::CircleShape point(POINT_RADIUS);
        point.setFillColor(elem.color);
        point.setPosition(x - POINT_RADIUS, y - POINT_RADIUS);

        target.draw(point, states);
    }

}

/**
 * Draws data with lines on chart
 *
 * @param elem         Data to plot
 * @param target       Render Target
 * @param states       Render States
 * @param x_range      X range of plotting area
 * @param y_range      Y range of plotting area
 *
 */
void CartesianChart::drawLine(const CartesianData& elem, sf::RenderTarget& target, sf::RenderStates states, const std::pair<double, double>& x_range, const std::pair<double, double>& y_range) const
{
    /* draw data */
    for (auto it = elem.data.cbegin(); it != elem.data.cend(); it++) {
        if (std::next(it) != elem.data.cend()) {
            auto line_start = *it;
            auto line_end = *std::next(it);

            line_start.x = (line_start.x - x_range.first) / (x_range.second - x_range.first) * (axes_.DIMENSION.x - axes_.MARGIN.x) + axes_.MARGIN.x;
            line_start.y = (axes_.DIMENSION.y - axes_.MARGIN.y) - (line_start.y - y_range.first) / (y_range.second - y_range.first) * (axes_.DIMENSION.y - axes_.MARGIN.y);

            line_end.x = (line_end.x - x_range.first) / (x_range.second - x_range.first) * (axes_.DIMENSION.x - axes_.MARGIN.x) + axes_.MARGIN.x;
            line_end.y = (axes_.DIMENSION.y - axes_.MARGIN.y) - (line_end.y - y_range.first) / (y_range.second - y_range.first) * (axes_.DIMENSION.y - axes_.MARGIN.y);

            sf::Vertex line[] = {
                sf::Vertex(static_cast<sf::Vector2f>(line_start), elem.color),
                sf::Vertex(static_cast<sf::Vector2f>(line_end), elem.color)
            };
            target.draw(line, 2, sf::Lines, states);
        }
    }
}

/**
 * Constructor for CartesianChart class
*/
CartesianChart::CartesianChart()
    : data_set_(), axes_()
{
}

/**
 * Destructor for CartesianChart class
*/
CartesianChart::~CartesianChart()
{

}

/**
 * \brief add plotting data
 * @return pointer to added data
*/
std::shared_ptr<CartesianData> CartesianChart::addData()
{
    auto data = std::make_shared<CartesianData>();
    data_set_.push_back(data);
    autoRange();

    return data;
}

/**
 * \brief add plotting data
 * @param data pointer to data
*/
void CartesianChart::addData(std::shared_ptr<CartesianData> data)
{
    data_set_.push_back(data);
    autoRange();
}

/**
 * \brief setter func for legend font
 * @param font font to set
 *
*/
void CartesianChart::setFont(const sf::Font& font)
{
    axes_.setFont(font);
}

/**
 * \brief setter func for legend color
 * @param font_color font color to set
 *
*/
void CartesianChart::setFontColor(const sf::Color& font_color)
{
    axes_.setFontColor(font_color);
}

/**
 * \brief setter func for axes color
 * @param axes_color axes color to set
 *
*/
void CartesianChart::setAxesColor(const sf::Color& axes_color)
{
    axes_.setAxesColor(axes_color);
}

/**
 * \brief setter func for scale color
 * @param scale_color scale color to set
 *
*/
void CartesianChart::setScaleColor(const sf::Color& scale_color)
{
    axes_.setScaleColor(scale_color);
}

/**
 * \brief adjust plotting area value range to plotting data.
 *
*/
void CartesianChart::autoRange()
{
    double x_min = std::numeric_limits<double>::max();
    double x_max = std::numeric_limits<double>::lowest();
    double y_min = std::numeric_limits<double>::max();
    double y_max = std::numeric_limits<double>::lowest();

    for (const auto& elem : data_set_) {
        auto x_range = elem->getRangeX();
        x_min = std::min(x_range.first, x_min);
        x_max = std::max(x_range.second, x_max);

        auto y_range = elem->getRangeY();
        y_min = std::min(y_range.first, y_min);
        y_max = std::max(y_range.second, y_max);
    }

    setRangeX(x_min, x_max);
    setRangeY(y_min, y_max);
}

/**
 * \brief set plotting area X value range
 * @param min minimal value of X value range
 * @param max maximum value of X value range
*/
void CartesianChart::setRangeX(const double& min, const double& max)
{
    std::pair<double, double> x_range;
    if (min > max) {
        x_range = std::pair<double, double>(max, min);
    } else {
        x_range = std::pair<double, double>(min, max);
    }

    axes_.setRangeX(x_range);
}

/**
 * \brief set plotting area Y value range
 * @param min minimal value of Y value range
 * @param max maximum value of Y value range
*/
void CartesianChart::setRangeY(const double& min, const double& max)
{
    std::pair<double, double> y_range;
    if (min > max) {
        y_range = std::pair<double, double>(max, min);
    } else {
        y_range = std::pair<double, double>(min, max);
    }

    axes_.setRangeY(y_range);
}

/**
 * \brief get legend font
 * @return legend font
*/
sf::Font CartesianChart::getFont() const
{
    return axes_.getFont();
}

/**
 * \brief get legend font color
 * @return legend font color
*/
sf::Color CartesianChart::getFontColor() const
{
    return axes_.getFontColor();
}

/**
 * \brief getter func for axes color
 * @return axes color
 *
*/
sf::Color CartesianChart::getAxesColor() const
{
    return axes_.getAxesColor();
}

/**
 * \brief getter func for scale color
 * @return scale color
 *
*/
sf::Color CartesianChart::getScaleColor() const
{
    return axes_.getScaleColor();
}

/**
 * \brief getter func for X value range
 * @return min max value pair of X value range
 *
*/
std::pair<double, double> CartesianChart::getRangeX() const
{
    return axes_.getRangeX();
}

/**
 * \brief getter func for Y value range
 * @return min max value pair of Y value range
 *
*/
std::pair<double, double> CartesianChart::getRangeY() const
{
    return axes_.getRangeY();
}

/**
 * get pointer to plotting data
 * @param index index of data to get
 *
*/
std::shared_ptr<CartesianData> CartesianChart::getData(const std::size_t& index)
{
    return data_set_[index];
}
};
