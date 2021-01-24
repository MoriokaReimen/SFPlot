#include "SFPlot/ArcMeter.hpp"
#include <sstream>
#include "SFPlot/FanShape.hpp"
#include "SFPlot/PlotConfig.hpp"

static constexpr float ARC_MAX_ANGLE = 360.f;
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

    float radius = 30.f + data_set_.size() * 20.f;
    for(const auto& data : data_set_) {
        sf::CircleShape circ(radius);
        circ.setOrigin(radius, radius);
        circ.setPosition(50.f, 50.f);
        circ.setFillColor(sf::Color::Black);
        target.draw(circ, states);

        auto angle = data->value / (range_.second - range_.first) * ARC_MAX_ANGLE;
        angle = std::min(angle, ARC_MAX_ANGLE);
        angle = std::max(angle, 0.f);
        sf::FanShape meter(radius, 0.f, angle);
        meter.setOrigin(radius, radius);
        meter.setPosition(50.f, 50.f);
        meter.setFillColor(data->color);
        target.draw(meter, states);
        radius -= 20;
    }

    sf::CircleShape circ(30.f);
    circ.setOrigin(30.f, 30.f);
    circ.setPosition(50.f, 50.f);
    circ.setFillColor(sf::Color::Black);
    target.draw(circ, states);

    if (!font_.getInfo().family.empty()) {
        std::stringstream ss;
        ss.precision(2);
        ss << std::fixed;
        ss.width(5);
        ss << data_set_[0]->value;
        sf::Text legend;
        legend.setString(ss.str());
        legend.setFont(font_);
        legend.setFillColor(font_color_);
        legend.setCharacterSize(15);
        legend.setOrigin(legend.getGlobalBounds().width / 2, legend.getGlobalBounds().height / 2);
        legend.setPosition(50.f, 50.f);
        target.draw(legend, states);
    }
}

/**
 * Constructor for ArcMeter class
 * @param min_range the minimal value of ArcMeter data
 * @param max_range the max value of ArcMeter data
*/
ArcMeter::ArcMeter(const float &min_range, const float& max_range)
    : font_(plot_config.font), font_color_(plot_config.font_color), data_set_(), range_(0.f, 100.f)
{
}

/**
 * Destructor for ArcMeter class
 * 
*/
ArcMeter::~ArcMeter()
{
}

/* setter functions */
void ArcMeter::setFont(const sf::Font &font)
{
    font_ = font;
}

void ArcMeter::setFontColor(const sf::Color& font_color)
{
    font_color_ = font_color;
}

void ArcMeter::setMaxRange(const float &max_range)
{
    range_.second = max_range;
    if (range_.first > range_.second)
        std::swap(range_.first, range_.second);
}

void ArcMeter::setMinRange(const float &min_range)
{
    range_.first = min_range;
    if (range_.first > range_.second)
        std::swap(range_.first, range_.second);
}

std::shared_ptr<ArcData> ArcMeter::addData()
{
    auto data = std::make_shared<ArcData>();
    data_set_.push_back(data);

    return data;
}

void ArcMeter::addData(std::shared_ptr<ArcData> data)
{
    data_set_.push_back(data);
}

/* getter functions */
sf::Font ArcMeter::getFont() const
{
    return font_;
}

sf::Color ArcMeter::getFontColor() const
{
    return font_color_;
}

std::pair<float, float> ArcMeter::getRange() const
{
    return range_;
}
float ArcMeter::getMaxRange() const
{
    return range_.second;
}
float ArcMeter::getMinRange() const
{
    return range_.first;
}

/**
 * get pointer to data to plot
 * @param index index of data to get 
 * 
*/
std::shared_ptr<ArcData> ArcMeter::getData(const std::size_t& index)
{
    return data_set_[index];
}

}; // namespace sf
