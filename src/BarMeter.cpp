#include "SFPlot/BarMeter.hpp"
#include <sstream>

static constexpr float BAR_MAX_WIDTH = 100.f;
namespace sf
{
    void BarMeter::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        auto width = value_ / (range_.second - range_.first) * BAR_MAX_WIDTH;
        width = std::min(width, BAR_MAX_WIDTH);
        width = std::max(width, 0.f);

        sf::RectangleShape meter(sf::Vector2f(width, 30));
        meter.setFillColor(sf::Color::Green);
        target.draw(meter, states);
        if (!font_.getInfo().family.empty())
        {
            std::stringstream ss;
            ss.precision(3);
            ss << std::fixed;
            ss.width(5);
            ss << value_;
            sf::Text legend;
            legend.setString(ss.str());
            legend.setFont(font_);
            legend.setFillColor(sf::Color::White);
            legend.setCharacterSize(15);
            legend.setOrigin(0, legend.getGlobalBounds().height / 2);
            legend.setPosition(120.f, 15.f);
            target.draw(legend, states);
        }
    }

    BarMeter::BarMeter(const float &min_range, const float& max_range)
    : font_(), value_(0.f), range_(0.f, 100.f)
    {
    }

    BarMeter::~BarMeter()
    {
    }

    /* setter functions */
    void BarMeter::set_font(const sf::Font &font)
    {
        font_ = font;
    }

    void BarMeter::set_value(const float &value)
    {
        value_ = value;
    }

    void BarMeter::set_max_range(const float &max_range)
    {
        range_.second = max_range;
        if (range_.first > range_.second)
            std::swap(range_.first, range_.second);
    }

    void BarMeter::set_min_range(const float &min_range)
    {
        range_.first = min_range;
        if (range_.first > range_.second)
            std::swap(range_.first, range_.second);
    }

    /* getter functions */
    sf::Font BarMeter::get_font() const
    {
        return font_;
    }

    float BarMeter::get_value() const
    {
        return value_;
    }

    std::pair<float, float> BarMeter::get_range() const
    {
        return range_;
    }
    float BarMeter::get_max_range() const
    {
        return range_.second;
    }
    float BarMeter::get_min_range() const
    {
        return range_.first;
    }
}; // namespace sf
