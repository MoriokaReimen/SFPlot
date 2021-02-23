#pragma once
#include <SFML/Graphics.hpp>
#include <utility>
namespace sf
{
/**
 * @relates CartesianChart
 * axes of Cartesian Chart.
 *
*/
class CartesianAxes : virtual public sf::Transformable, virtual public sf::Drawable
{
    std::pair<double, double> x_range_;
    std::pair<double, double> y_range_;

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

    virtual ~CartesianAxes();

    /* setter functions */
    void setRangeX(const std::pair<double, double>& x_range);
    void setRangeY(const std::pair<double, double>& y_range);
    void setFont(const sf::Font& font);
    void setFontColor(const sf::Color& font_color);
    void setAxesColor(const sf::Color& axes_color);
    void setScaleColor(const sf::Color& scale_color);

    /* getter functions */
    std::pair<double, double> getRangeX() const;
    std::pair<double, double> getRangeY() const;
    sf::Font getFont() const;
    sf::Color getFontColor() const;
    sf::Color getAxesColor() const;
    sf::Color getScaleColor() const;
};
};
