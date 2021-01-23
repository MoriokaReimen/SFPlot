#include "SFPlot/RaderChart.hpp"
#include <cmath>
#include <limits>
#include <algorithm>
#include "SFPlot/PlotConfig.hpp"

namespace sf
{
void RaderChart::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    target.draw(axes_, states);

    for(const auto& data : data_set_) {
        drawPoint(target, states, *data, axes_.getMaxValue());
    }
}

void RaderChart::drawPoint(sf::RenderTarget& target, sf::RenderStates states, const RaderData& data, const float& max_value) const
{
    constexpr float POINT_RADIUS(5.f);

    for(const auto& element : data.data) {
        const float radius = element.value / max_value * axes_.RADIUS;
        sf::Vector2f position(axes_.RADIUS + radius * std::sin(element.angle / 180.f * M_PI) - POINT_RADIUS,
                              axes_.RADIUS - radius * std::cos(element.angle / 180.f * M_PI) - POINT_RADIUS);
        sf::CircleShape point(POINT_RADIUS);
        point.setPosition(position);
        point.setFillColor(data.color);
        target.draw(point, states);
    }
}

float RaderChart::getMaxValue() const
{
    return axes_.getMaxValue();
}

RaderChart::RaderChart()
    : data_set_(), axes_()
{
}

RaderChart::~RaderChart()
{
}

/* setter functions */

std::shared_ptr<RaderData> RaderChart::addData()
{
    auto data = std::make_shared<RaderData>();
    data_set_.push_back(data);
    autoRange();

    return data;
}

void RaderChart::addData(std::shared_ptr<RaderData> data)
{
    data_set_.push_back(data);
    autoRange();
}

void RaderChart::setFont(const sf::Font& font)
{
    axes_.setFont(font_);
}

void RaderChart::setFontColor(const sf::Color& font_color)
{
    axes_.setFontColor(font_color);
}

void RaderChart::setAxesColor(const sf::Color& axes_color)
{
    axes_.setAxesColor(axes_color);
}

void RaderChart::setScaleColor(const sf::Color& scale_color)
{
    axes_.setScaleColor(scale_color);
}

void RaderChart::setAxes(const RaderAxes& axes)
{
    axes_ = axes;
}

void RaderChart::autoRange()
{
    auto max = std::numeric_limits<float>::lowest();
    for(const auto& elem : data_set_) {
        max = std::max(elem->getMaxValue(), max);
    }

    setMaxValue(max);
}

void RaderChart::setMaxValue(const float& max)
{
    axes_.setMaxValue(max);
}

/* getter functions */
sf::Font RaderChart::getFont() const
{
    return axes_.getFont();
}

sf::Color RaderChart::getFontColor() const
{
    return axes_.getFontColor();
}

sf::Color RaderChart::getAxesColor() const
{
    return axes_.getAxesColor();
}

sf::Color RaderChart::getScaleColor() const
{
    return axes_.getScaleColor();
}

RaderAxes RaderChart::getAxes() const
{
    return axes_;
}

std::shared_ptr<RaderData> RaderChart::getData(const std::size_t& index)
{
    return data_set_[index];
}

};
