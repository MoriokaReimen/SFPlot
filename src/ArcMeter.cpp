#include "SFPlot/ArcMeter.hpp"
#include <sstream>
#include <numeric>
#include "SFPlot/FanShape.hpp"
#include "SFPlot/PlotConfig.hpp"

static constexpr double ARC_MAX_ANGLE = 360.0;
namespace sf
{

/**
 * Drawing function derived from sf::Drawable
 *
 * @param target       Render Target
 * @param states       Render States
 *
 */
void ArcMeter::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    double radius = 30.0 + data_set_.size() * 20.0;
    for (const auto& data : data_set_) {
        sf::CircleShape circ(radius);
        circ.setOrigin(radius, radius);
        circ.setPosition(50.0, 50.0);
        circ.setFillColor(sf::Color::Black);
        target.draw(circ, states);

        auto angle = data->value / (range_.second - range_.first) * ARC_MAX_ANGLE;
        angle = std::min(angle, ARC_MAX_ANGLE);
        angle = std::max(angle, 0.0);
        sf::FanShape meter(radius, 0.0, angle);
        meter.setOrigin(radius, radius);
        meter.setPosition(50.0, 50.0);
        meter.setFillColor(data->color);
        target.draw(meter, states);
        radius -= 20;
    }

    sf::CircleShape circ(30.0);
    circ.setOrigin(30.0, 30.0);
    circ.setPosition(50.0, 50.0);
    circ.setFillColor(sf::Color::Black);
    target.draw(circ, states);

    if (!font_.getInfo().family.empty()) {
        const double average = std::accumulate(data_set_.begin(), data_set_.end(), 0.0,
        [](const double & a, const std::shared_ptr<ArcData>& b) {
            return a + b->value;
        })
        / data_set_.size();
        std::stringstream ss;
        ss.precision(2);
        ss << std::fixed;
        ss.width(5);
        ss << average;
        sf::Text legend;
        legend.setString(ss.str());
        legend.setFont(font_);
        legend.setFillColor(font_color_);
        legend.setCharacterSize(15);
        legend.setOrigin(legend.getGlobalBounds().width / 2, legend.getGlobalBounds().height / 2);
        legend.setPosition(50.0, 50.0);
        target.draw(legend, states);
    }
}

/**
 * \brief Constructor for ArcMeter class
 * legend font and color are initialized with default value. \n
 * Default value is specified by plot_config global bariable.
 * @see   plot_config
 * @param min_range the minimal value of ArcMeter data
 * @param max_range the max value of ArcMeter data
*/
ArcMeter::ArcMeter(const double &min_range, const double& max_range)
    : font_(plot_config.font), font_color_(plot_config.font_color), data_set_(), range_(0.0, 100.0)
{
}

/**
 * \brief Destructor for ArcMeter class
 *
*/
ArcMeter::~ArcMeter()
{
}

/**
 * \brief setter func for legend font
 * @param font font to set
 *
*/
void ArcMeter::setFont(const sf::Font &font)
{
    font_ = font;
}

/**
 * \brief setter func for legend color
 * @param font_color font color to set
 *
*/
void ArcMeter::setFontColor(const sf::Color& font_color)
{
    font_color_ = font_color;
}

/**
 * \brief set max value of plot range
 * @param max_range max value of plotting area
*/
void ArcMeter::setMaxRange(const double &max_range)
{
    range_.second = max_range;
    if (range_.first > range_.second)
        std::swap(range_.first, range_.second);
}

/**
 * \brief set min value of plot range
 * @param min_range min value of plotting area
*/
void ArcMeter::setMinRange(const double &min_range)
{
    range_.first = min_range;
    if (range_.first > range_.second)
        std::swap(range_.first, range_.second);
}

/**
 * \brief add plotting data
 * @return pointer to added data
*/
std::shared_ptr<ArcData> ArcMeter::addData()
{
    auto data = std::make_shared<ArcData>();
    data_set_.push_back(data);

    return data;
}

/**
 * \brief add plotting data
 * @param data pointer to data
*/
void ArcMeter::addData(std::shared_ptr<ArcData> data)
{
    data_set_.push_back(data);
}

/**
 * \brief get legend font
 * @return legend font
*/
sf::Font ArcMeter::getFont() const
{
    return font_;
}

/**
 * \brief get legend font color
 * @return legend font color
*/
sf::Color ArcMeter::getFontColor() const
{
    return font_color_;
}

/**
 * \brief get plotting area value range
 * @return pair of min value and max value of plotting area
*/
std::pair<double, double> ArcMeter::getRange() const
{
    return range_;
}

/**
 * \brief get plotting area max value
 * @return max value of plotting area
*/
double ArcMeter::getMaxRange() const
{
    return range_.second;
}

/**
 * get minimal value of plotting area
 * @return minimal value of plotting area
 *
*/
double ArcMeter::getMinRange() const
{
    return range_.first;
}

/**
 * get pointer to plotting data
 * @param index index of data to get
 *
*/
std::shared_ptr<ArcData> ArcMeter::getData(const std::size_t& index)
{
    return data_set_[index];
}

}; // namespace sf
