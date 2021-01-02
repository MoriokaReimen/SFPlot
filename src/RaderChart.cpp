#include "SFPlot/RaderChart.hpp"
#include <cmath>
#include <limits>

void RaderChart::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    target.draw(axes_, states);

    float max_value = std::numeric_limits<float>::lowest();
    for(const auto& element : data_.data) {
        max_value = std::max(element.value, max_value);
    }

    draw_point(target, states, max_value);
}

void RaderChart::draw_point(sf::RenderTarget& target, sf::RenderStates states, const float& max_value) const
{
    constexpr float POINT_RADIUS(5.f);

    for(const auto& element : data_.data) {
        const float radius = element.value / max_value * axes_.RADIUS;
        sf::Vector2f position(axes_.RADIUS + radius * std::sin(element.angle / 180.f * M_PI) - POINT_RADIUS,
                              axes_.RADIUS - radius * std::cos(element.angle / 180.f * M_PI) - POINT_RADIUS);
        sf::CircleShape point(POINT_RADIUS);
        point.setPosition(position);
        point.setFillColor(data_.color);
        target.draw(point, states);
    }
}

RaderChart::RaderChart(const std::string& title)
    : title_(title), font_(), data_(), axes_()
{
}

RaderChart::~RaderChart()
{
}

/* setter functions */
void RaderChart::set_data(const RaderData& data)
{
    data_ = data;
}

void RaderChart::set_font(const sf::Font& font)
{
    font_ = font;
}

void RaderChart::set_axes(const RaderAxes& axes)
{
    axes_ = axes;
}

/* getter functions */
RaderData RaderChart::get_data() const
{
    return data_;
}

sf::Font RaderChart::get_font() const
{
    return font_;
}

RaderAxes RaderChart::get_axes() const
{
    return axes_;
}