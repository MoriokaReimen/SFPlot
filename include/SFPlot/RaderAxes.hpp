#pragma once
#include <SFML/Graphics.hpp>

namespace sf
{
class RaderAxes : virtual public sf::Transformable, virtual public sf::Drawable
{
    float max_value_;
    sf::Font font_;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void draw_axes(sf::RenderTarget& target, sf::RenderStates states) const;
    void draw_legend(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    static const float RADIUS;

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
};
