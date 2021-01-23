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
    sf::Color font_color_;

    sf::Color axes_color_;
    sf::Color scale_color_;

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
    void setFontColor(const sf::Color& font_color);
    void setAxesColor(const sf::Color& axes_color);
    void setScaleColor(const sf::Color& scale_color);

    /* getter functions */
    std::pair<float, float> getRangeX() const;
    std::pair<float, float> getRangeY() const;
    sf::Font getFont() const;
    sf::Color getFontColor() const;
    sf::Color getAxesColor() const;
    sf::Color getScaleColor() const;
};
};