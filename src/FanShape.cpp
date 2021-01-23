#include "SFPlot/FanShape.hpp"
#include <cmath>

namespace sf
{
FanShape::FanShape(const float& radius, const float& start_angle, const float& end_angle)
    : radius_(radius), start_angle_(start_angle), end_angle_(end_angle)
{
    if(end_angle_ < start_angle_) {
        std::swap(end_angle_, start_angle_);
    }

    update();
}

FanShape::~FanShape()
{
}

/* setter function */
void FanShape::setRadius(const float& radius)
{
    radius_ = radius;
    update();
}

void FanShape::setStartAngle(const float& start_angle)
{
    start_angle_ = start_angle;
    if(end_angle_ < start_angle_) {
        std::swap(end_angle_, start_angle_);
    }
    update();
}

void FanShape::setEndAngle(const float& end_angle)
{
    end_angle_ = end_angle;
    if(end_angle_ < start_angle_) {
        std::swap(end_angle_, start_angle_);
    }
    update();
}

/* getter function */
float FanShape::getRadius() const
{
    return radius_;
}

float FanShape::getStartAngle() const
{
    return start_angle_;
}

float FanShape::getEndAngle() const
{
    return end_angle_;
}

std::size_t FanShape::getPointCount() const
{
    return 102;
}

sf::Vector2f FanShape::getPoint(std::size_t index) const
{
    if(index == 0) return sf::Vector2f(radius_, radius_);

    index -= 1;
    const float angle = (end_angle_ - start_angle_) * 0.01;
    sf::Vector2f point(radius_ + radius_ * std::cos(start_angle_ / 180.f * M_PI + angle * index / 180.f * M_PI - M_PI_2),
                       radius_ + radius_ *  std::sin(start_angle_ / 180.f * M_PI + angle * index / 180.f * M_PI - M_PI_2));

    return point;
}
};
