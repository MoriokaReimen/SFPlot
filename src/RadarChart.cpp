#include "SFPlot/RadarChart.hpp"
#include <cmath>
#include <limits>
#include <algorithm>
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
void RadarChart::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    target.draw(axes_, states);

    for (const auto& data : data_set_) {
        drawPoint(target, states, *data, axes_.getMaxValue());
    }
}

/**
 * draw point of data
 * @param target draw target
 * @param states state of draw
 * @param data to plot
 * @param max_value max value of data
 *
 */
void RadarChart::drawPoint(sf::RenderTarget& target, sf::RenderStates states, const RadarData& data, const double& max_value) const
{
    constexpr double POINT_RADIUS(5.0);

    for (const auto& element : data.data) {
        const double radius = element.value / max_value * axes_.RADIUS;
        sf::Vector2f position(axes_.RADIUS + radius * std::sin(element.angle / 180.0 * M_PI) - POINT_RADIUS,
                              axes_.RADIUS - radius * std::cos(element.angle / 180.0 * M_PI) - POINT_RADIUS);
        sf::CircleShape point(POINT_RADIUS);
        point.setPosition(position);
        point.setFillColor(data.color);
        target.draw(point, states);
    }
}

/**
 * get max value of data
 * @return max value of data
 *
 */
double RadarChart::getMaxValue() const
{
    return axes_.getMaxValue();
}

/**
 * Constructor for Radar Chart
 *
 */
RadarChart::RadarChart()
    : data_set_(), axes_()
{
}

/**
 * Destructor for Radar Chart
 *
 */
RadarChart::~RadarChart()
{
}

/* setter functions */

/**
 * \brief add plotting data
 * @return pointer to added data
*/
std::shared_ptr<RadarData> RadarChart::addData()
{
    auto data = std::make_shared<RadarData>();
    data_set_.push_back(data);
    autoRange();

    return data;
}

/**
 * \brief add plotting data
 * @param data pointer to data
*/
void RadarChart::addData(std::shared_ptr<RadarData> data)
{
    data_set_.push_back(data);
    autoRange();
}

/**
 * \brief setter func for legend font
 * @param font font to set
 *
*/
void RadarChart::setFont(const sf::Font& font)
{
    axes_.setFont(font_);
}

/**
 * \brief setter func for legend color
 * @param font_color font color to set
 *
*/
void RadarChart::setFontColor(const sf::Color& font_color)
{
    axes_.setFontColor(font_color);
}

/**
 * \brief setter func for axes color
 * @param axes_color axes color to set
 *
*/
void RadarChart::setAxesColor(const sf::Color& axes_color)
{
    axes_.setAxesColor(axes_color);
}

/**
 * \brief setter func for scale color
 * @param scale_color scale color to set
 *
*/
void RadarChart::setScaleColor(const sf::Color& scale_color)
{
    axes_.setScaleColor(scale_color);
}

/**
 * \brief adjust plotting area value range to plotting data.
 *
*/
void RadarChart::autoRange()
{
    auto max = std::numeric_limits<double>::lowest();
    for (const auto& elem : data_set_) {
        max = std::max(elem->getMaxValue(), max);
    }

    setMaxValue(max);
}
/**
 * set max value of plotting range
 * @param max max value of plotting range
 *
*/
void RadarChart::setMaxValue(const double& max)
{
    axes_.setMaxValue(max);
}

/**
 * get font of legend
 * @return font of legend
 *
 */
sf::Font RadarChart::getFont() const
{
    return axes_.getFont();
}

/**
 * get legend font color
 * @return legend font color
 *
 */
sf::Color RadarChart::getFontColor() const
{
    return axes_.getFontColor();
}

/**
 * get axes color
 * @return axes color
 *
 */
sf::Color RadarChart::getAxesColor() const
{
    return axes_.getAxesColor();
}

/**
 * get scale color
 * @return scale color
 *
 */
sf::Color RadarChart::getScaleColor() const
{
    return axes_.getScaleColor();
}

/**
 * get pointer to plotting data
 * @param index index of data
 * @return pointer to plotting data
 *
 */
std::shared_ptr<RadarData> RadarChart::getData(const std::size_t& index)
{
    return data_set_[index];
}

};
