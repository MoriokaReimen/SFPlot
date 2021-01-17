#include "SFPlot/RaderChart.hpp"
#include <cmath>
#include <limits>
#include <algorithm>

namespace sf
{
void RaderChart::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    target.draw(axes_, states);

    for(const auto& data : data_set_) {
        draw_point(target, states, *data, axes_.get_max_value());
    }
}

void RaderChart::draw_point(sf::RenderTarget& target, sf::RenderStates states, const RaderData& data, const float& max_value) const
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

float RaderChart::get_max_value() const
{
    return axes_.get_max_value();
}

RaderChart::RaderChart()
    : font_(), data_set_(), axes_()
{
}

RaderChart::~RaderChart()
{
}

/* setter functions */

std::shared_ptr<RaderData> RaderChart::add_data()
{
    auto data = std::make_shared<RaderData>();
    data_set_.push_back(data);
    auto_range();

    return data;
}

void RaderChart::add_data(std::shared_ptr<RaderData> data)
{
    data_set_.push_back(data);
    auto_range();
}

void RaderChart::set_font(const sf::Font& font)
{
    font_ = font;
    axes_.set_font(font_);
}

void RaderChart::set_axes(const RaderAxes& axes)
{
    axes_ = axes;
}

void RaderChart::auto_range()
{
    auto max = std::numeric_limits<float>::lowest();
    for(const auto& elem : data_set_) {
        max = std::max(elem->get_max_value(), max);
    }

    set_max_value(max);
}

void RaderChart::set_max_value(const float& max)
{
    axes_.set_max_value(max);
}

/* getter functions */
sf::Font RaderChart::get_font() const
{
    return font_;
}

RaderAxes RaderChart::get_axes() const
{
    return axes_;
}

std::shared_ptr<RaderData> RaderChart::get_data(const std::size_t& index)
{
    return data_set_[index];
}

};
