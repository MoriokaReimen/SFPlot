#include "SFPlot/BarMeter.hpp"
#include <sstream>
#include "SFPlot/PlotConfig.hpp"

static constexpr float BAR_MAX_WIDTH = 100.f;
namespace sf
{
void BarMeter::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    float offset_y = 0.f;
    for (auto data : data_set_) {
        auto width = data->value / (range_.second - range_.first) * BAR_MAX_WIDTH;
        width = std::min(width, BAR_MAX_WIDTH);
        width = std::max(width, 0.f);

        sf::RectangleShape meter(sf::Vector2f(width, 30));
        meter.setFillColor(data->color);
        meter.setPosition(0.f, offset_y);
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
            legend.setPosition(120.f, offset_y + 10.f);
            target.draw(legend, states);
        }

        offset_y += 30.f;
    }
}

BarMeter::BarMeter(const float &min_range, const float &max_range)
    : font_(plot_config.font), font_color_(plot_config.font_color), data_set_(), range_(min_range, max_range)
{
}

BarMeter::~BarMeter()
{
}

/* setter functions */
void BarMeter::setFont(const sf::Font &font)
{
    font_ = font;
}
std::shared_ptr<BarData> BarMeter::addData()
{
    auto data = std::make_shared<BarData>();
    data_set_.push_back(data);
    return data;
}

void BarMeter::addData(std::shared_ptr<BarData> data)
{
    data_set_.push_back(data);
}

void BarMeter::setMaxRange(const float &max_range)
{
    range_.second = max_range;
    if (range_.first > range_.second)
        std::swap(range_.first, range_.second);
}

void BarMeter::setMinRange(const float &min_range)
{
    range_.first = min_range;
    if (range_.first > range_.second)
        std::swap(range_.first, range_.second);
}

/* getter functions */
sf::Font BarMeter::getFont() const
{
    return font_;
}

sf::Color BarMeter::getFontColor() const
{
    return font_color_;
}

std::shared_ptr<BarData> BarMeter::getData(const std::size_t &index)
{
    return data_set_[index];
}

std::pair<float, float> BarMeter::getRange() const
{
    return range_;
}
float BarMeter::getMaxRange() const
{
    return range_.second;
}
float BarMeter::getMinRange() const
{
    return range_.first;
}
}; // namespace sf
