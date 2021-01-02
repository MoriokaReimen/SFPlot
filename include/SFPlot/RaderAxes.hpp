#pragma once
#include <SFML/Graphics.hpp>

class RaderAxes : public sf::Transformable, public sf::Drawable
{
    float max_value_;
    sf::Font font_;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void draw_axes(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    RaderAxes();
    virtual ~RaderAxes();
    RaderAxes& operator=(const RaderAxes& other) = default;

    /* setter functions */
    void set_max_value(const float& max_value);
    void set_font(const sf::Font& font);

    /* getter functions */
    float get_max_value() const;
    sf::Font get_font() const;
};
