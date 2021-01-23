#pragma once
#include <SFML/Graphics.hpp>
#include <utility>
namespace sf
{
class CartesianAxes : virtual public sf::Transformable, virtual public sf::Drawable
{
    std::pair<float, float> x_range_;
    std::pair<float, float> y_range_;

    sf::Font font_;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void drawAxes(sf::RenderTarget& target, sf::RenderStates states) const;
    void drawLegend(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    static const sf::Vector2f DIMENSION;
    static const sf::Vector2f MARGIN;
    CartesianAxes();
    CartesianAxes& operator=(const CartesianAxes& other) = default;
    virtual ~CartesianAxes();

    /* setter functions */
    void setRangeX(const std::pair<float, float>& x_range);
    void setRangeY(const std::pair<float, float>& y_range);
    void setFont(const sf::Font& font);

    /* getter functions */
    std::pair<float, float> getRangeX() const;
    std::pair<float, float> getRangeY() const;
    sf::Font getFont() const;
};
};