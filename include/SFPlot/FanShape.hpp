#pragma once
#include <SFML/Graphics.hpp>

class FanShape : public sf::Shape
{
    float radius_;
    float start_angle_;
    float end_angle_;

public:
    FanShape(const float& radius = 50.f, const float& start_angle = 0.f, const float& end_angle = 360.f);
    virtual ~FanShape() override;

    /* setter function */
    void set_radius(const float& radius);
    void set_start_angle(const float& start_angle);
    void set_end_angle(const float& end_angle);
    void setColor(const sf::Color& color);

    /* getter function */
    float get_radius() const;
    float get_start_angle() const;
    float get_end_angle() const;
    virtual std::size_t getPointCount() const override;
    virtual sf::Vector2f getPoint(std::size_t index) const override;
};