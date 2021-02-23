#include "SFPlot/BarMeter.hpp"
#include <sstream>
#include "SFPlot/PlotConfig.hpp"

static constexpr double BAR_MAX_WIDTH = 100.0;
namespace sf
{
/**
 * Drawing function derived from sf::Drawable
 *
 * @param target       Render Target
 * @param states       Render States
 *
 */
void BarMeter::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    double offset_y = 0.0;
    for (auto data : data_set_) {
        auto width = data->value / (range_.second - range_.first) * BAR_MAX_WIDTH;
        width = std::min(width, BAR_MAX_WIDTH);
        width = std::max(width, 0.0);

        sf::RectangleShape meter(sf::Vector2f(width, 30));
        meter.setFillColor(data->color);
        meter.setPosition(0.0, offset_y);
        target.draw(meter, states);
        if (!font_.getInfo().family.empty()) {
            std::stringstream ss;
            ss.precision(3);
            ss << std::fixed;
            ss.width(5);
            ss << data->value;
            sf::Text legend;
            legend.setString(ss.str());
            legend.setFont(font_);
            legend.setFillColor(font_color_);
            legend.setCharacterSize(15);
            legend.setOrigin(0, legend.getGlobalBounds().height / 2);
            legend.setPosition(120.0, offset_y + 10.0);
            target.draw(legend, states);
        }

        offset_y += 30.0;
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
BarMeter::BarMeter(const double &min_range, const double &max_range)
    : font_(plot_config.font), font_color_(plot_config.font_color), data_set_(), range_(min_range, max_range)
{
}

/**
 * \brief Destructor for ArcMeter class
 *
*/
BarMeter::~BarMeter()
{
}

/**
 * \brief setter func for legend font
 * @param font font to set
 *
*/
void BarMeter::setFont(const sf::Font &font)
{
    font_ = font;
}

/**
 * \brief setter func for legend color
 * @param font_color font color to set
 *
*/
void BarMeter::setFontColor(const sf::Color& font_color)
{
    font_color_ = font_color;
}


/**
 * \brief add plotting data
 * @return pointer to added data
*/
std::shared_ptr<BarData> BarMeter::addData()
{
    auto data = std::make_shared<BarData>();
    data_set_.push_back(data);
    return data;
}

/**
 * \brief add plotting data
 * @return pointer to added data
*/
void BarMeter::addData(std::shared_ptr<BarData> data)
{
    data_set_.push_back(data);
}

/**
 * \brief set max value of plot range
 * @param max_range max value of plotting area
*/
void BarMeter::setMaxRange(const double &max_range)
{
    range_.second = max_range;
    if (range_.first > range_.second)
        std::swap(range_.first, range_.second);
}

/**
 * \brief set min value of plot range
 * @param min_range min value of plotting area
*/
void BarMeter::setMinRange(const double &min_range)
{
    range_.first = min_range;
    if (range_.first > range_.second)
        std::swap(range_.first, range_.second);
}

/* getter functions */
/**
 * \brief get legend font
 * @return legend font
*/
sf::Font BarMeter::getFont() const
{
    return font_;
}

/**
 * \brief get legend font color
 * @return legend font color
*/
sf::Color BarMeter::getFontColor() const
{
    return font_color_;
}

/**
 * get pointer to plotting data
 * @param index index of data to get
 *
*/
std::shared_ptr<BarData> BarMeter::getData(const std::size_t &index)
{
    return data_set_[index];
}

/**
 * \brief get plotting area value range
 * @return pair of min value and max value of plotting area
*/
std::pair<double, double> BarMeter::getRange() const
{
    return range_;
}

/**
 * \brief get plotting area max value
 * @return max value of plotting area
*/
double BarMeter::getMaxRange() const
{
    return range_.second;
}

/**
 * get minimal value of plotting area
 * @return minimal value of plotting area
 *
*/
double BarMeter::getMinRange() const
{
    return range_.first;
}
}; // namespace sf
