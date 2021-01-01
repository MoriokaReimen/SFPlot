#include "SFPlot/FanShape.hpp"
#include <cmath>

void FanShape::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    std::vector<sf::Vertex> vertices;
    vertices.push_back(sf::Vertex(sf::Vector2f(radius_, radius_), color_));

    for(float angle = start_angle_; angle < end_angle_; angle += 0.01)
    {
        sf::Vector2f point(radius_ + radius_ * std::sin(angle / 180.f * M_PI), radius_ - radius_ *  std::cos(angle / 180.f * M_PI));
        sf::Vertex vertex(point, color_);
        vertices.push_back(vertex);
    }

    target.draw(&vertices[0], vertices.size(), sf::TriangleFan, states);

}

FanShape::FanShape(const float& radius, const float& start_angle, const float& end_angle)
    : radius_(radius), start_angle_(start_angle), end_angle_(end_angle), color_()
{
    if(end_angle_ < start_angle_)
    {
        std::swap(end_angle_, start_angle_);
    }
}

FanShape::~FanShape()
{
}

/* setter function */
void FanShape::set_radius(const float& radius)
{
    radius_ = radius;
}

void FanShape::set_start_angle(const float& start_angle)
{
    start_angle_ = start_angle;
}

void FanShape::set_end_angle(const float& end_angle)
{
    end_angle_ = end_angle;
}

void FanShape::setColor(const sf::Color& color)
{
    color_ = color;
}

/* getter function */
float FanShape::get_radius() const
{
    return radius_;
}

float FanShape::get_start_angle() const
{
    return start_angle_;
}

float FanShape::get_end_angle() const
{
    return end_angle_;
}

sf::Color FanShape::getColor() const
{
    return color_;
}