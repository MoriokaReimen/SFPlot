#pragma once
#include <SFML/Graphics.hpp>

namespace sf
{
/**
 * @relates PieChart, ArcMeter
 * Arc shape.
 *
*/
class FanShape : public sf::Shape
{
    double radius_;
    double start_angle_;
    double end_angle_;

public:
    FanShape(const double& radius = 50.0, const double& start_angle = 0.0, const double& end_angle = 360.0);
    virtual ~FanShape() override;

    /* setter function */
    void setRadius(const double& radius);
    void setStartAngle(const double& start_angle);
    void setEndAngle(const double& end_angle);

    /* getter function */
    double getRadius() const;
    double getStartAngle() const;
    double getEndAngle() const;
    virtual std::size_t getPointCount() const override;
    virtual sf::Vector2f getPoint(std::size_t index) const override;
};
};
