#include "SFPlot/FanShape.hpp"
#include <cmath>

namespace sf
{
/**
 * Constructor for sf::FanShape class
 *
 * @param radius        Radius of fan
 * @param start_angle   start angle of fan
 * @param end_angle     end angle of fan
 *
 */
FanShape::FanShape(const float& radius, const float& start_angle, const float& end_angle)
    : radius_(radius), start_angle_(start_angle), end_angle_(end_angle)
{
    if(end_angle_ < start_angle_) {
        std::swap(end_angle_, start_angle_);
    }

    update();
}

/**
 * Destructor for sf::FanShape class
 *
 */
FanShape::~FanShape()
{
}

/**
 * set radius of fan
 * @param radius radius of fan
 *
*/
void FanShape::setRadius(const float& radius)
{
    radius_ = radius;
    update();
}

/**
 * set start angle of fan
 * @param start_angle start angle of fan
 *
*/
void FanShape::setStartAngle(const float& start_angle)
{
    start_angle_ = start_angle;
    if(end_angle_ < start_angle_) {
        std::swap(end_angle_, start_angle_);
    }
    update();
}

/**
 * set end angle of fan
 * @param end_angle end angle of fan
 *
*/
void FanShape::setEndAngle(const float& end_angle)
{
    end_angle_ = end_angle;
    if(end_angle_ < start_angle_) {
        std::swap(end_angle_, start_angle_);
    }
    update();
}


/**
 * get radius of fan
 * @return radius of fan
 *
*/
float FanShape::getRadius() const
{
    return radius_;
}

/**
 * get start angle of fan
 * @return start angle of fan
 *
*/
float FanShape::getStartAngle() const
{
    return start_angle_;
}

/**
 * get end angle of fan
 * @return end angle of fan
 *
*/
float FanShape::getEndAngle() const
{
    return end_angle_;
}

/**
 * get count of vertex. Derived from sf::Shape.
 * @return count of vertex
 *
*/
std::size_t FanShape::getPointCount() const
{
    return 102;
}

/**
 * get  vertex. Derived from sf::Shape.
 * @param  index    index of vertex
 * @return vertex
 *
*/
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
