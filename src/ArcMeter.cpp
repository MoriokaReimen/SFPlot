#include "SFPlot/ArcMeter.hpp"
#include <sstream>
#include "SFPlot/FanShape.hpp"

static constexpr float ARC_MAX_ANGLE = 360.f;
namespace sf
{
void ArcMeter::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    auto angle = value_ / (range_.second - range_.first) * ARC_MAX_ANGLE;
    angle = std::min(angle, ARC_MAX_ANGLE);
    angle = std::max(angle, 0.f);

    sf::FanShape meter(50.f, 0.f, angle);
    meter.setFillColor(sf::Color::Green);
    target.draw(meter, states);

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
        ss << value_;
        sf::Text legend;
        legend.setString(ss.str());
        legend.setFont(font_);
        legend.setFillColor(sf::Color::White);
        legend.setCharacterSize(15);
        legend.setOrigin(legend.getGlobalBounds().width / 2, legend.getGlobalBounds().height / 2);
        legend.setPosition(50.f, 50.f);
        target.draw(legend, states);
    }
}

ArcMeter::ArcMeter(const float &min_range, const float& max_range)
    : font_(), value_(0.f), range_(0.f, 100.f)
{
}

ArcMeter::~ArcMeter()
{
}

/* setter functions */
void ArcMeter::setFont(const sf::Font &font)
{
    font_ = font;
}

void ArcMeter::setValue(const float &value)
{
    value_ = value;
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

/* getter functions */
sf::Font ArcMeter::getFont() const
{
    return font_;
}

float ArcMeter::getValue() const
{
    return value_;
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
}; // namespace sf
