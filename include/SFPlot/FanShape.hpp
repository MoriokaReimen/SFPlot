#pragma once
#include <SFML/Graphics.hpp>

namespace sf
{
class FanShape : public sf::Shape
{
    float radius_;
    float start_angle_;
    float end_angle_;

public:
    FanShape(const float& radius = 50.f, const float& start_angle = 0.f, const float& end_angle = 360.f);
    virtual ~FanShape() override;

    /* setter function */
    void setRadius(const float& radius);
    void setStartAngle(const float& start_angle);
    void setEndAngle(const float& end_angle);

    /* getter function */
    float getRadius() const;
    float getStartAngle() const;
    float getEndAngle() const;
    virtual std::size_t getPointCount() const override;
    virtual sf::Vector2f getPoint(std::size_t index) const override;
};
};