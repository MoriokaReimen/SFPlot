#pragma once
#include <SFML/Graphics.hpp>

class FanShape : public sf::Drawable, public sf::Transformable
{
    float radius_;
    float start_angle_;
    float end_angle_;
    sf::Color color_;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
public:
    FanShape(const float& radius = 50.f, const float& start_angle = 0.f, const float& end_angle = 360.f);
    virtual ~FanShape();

    /* setter function */
    void set_radius(const float& radius);
    void set_start_angle(const float& start_angle);
    void set_end_angle(const float& end_angle);
    void setColor(const sf::Color& color);

    /* getter function */
    float get_radius() const;
    float get_start_angle() const;
    float get_end_angle() const;
    sf::Color getColor() const;
};