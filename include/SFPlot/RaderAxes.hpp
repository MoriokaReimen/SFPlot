#pragma once
#include <SFML/Graphics.hpp>

namespace sf
{
class RaderAxes : virtual public sf::Transformable, virtual public sf::Drawable
{
    float max_value_;
    sf::Font font_;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void drawAxes(sf::RenderTarget& target, sf::RenderStates states) const;
    void drawLegend(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    static const float RADIUS;

    RaderAxes();
    virtual ~RaderAxes();
    RaderAxes& operator=(const RaderAxes& other) = default;

    /* setter functions */
    void setMaxValue(const float& max_value);
    void setFont(const sf::Font& font);

    /* getter functions */
    float getMaxValue() const;
    sf::Font getFont() const;
};
};
