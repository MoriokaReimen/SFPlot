#pragma once
#include <SFML/Graphics.hpp>

namespace sf
{
/**
 * @relates RadarChart
 * axes of Radar Chart.
 *
*/
class RadarAxes : virtual public sf::Transformable, virtual public sf::Drawable
{
    float max_value_;
    sf::Font font_;
    sf::Color font_color_;
    sf::Color axes_color_;
    sf::Color scale_color_;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void drawAxes(sf::RenderTarget& target, sf::RenderStates states) const;
    void drawLegend(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    static const float RADIUS;

    RadarAxes();
    virtual ~RadarAxes();

    /* setter functions */
    void setMaxValue(const float& max_value);
    void setFont(const sf::Font& font);
    void setFontColor(const sf::Color& font_color);
    void setAxesColor(const sf::Color& axes_color);
    void setScaleColor(const sf::Color& scale_color);

    /* getter functions */
    float getMaxValue() const;
    sf::Font getFont() const;
    sf::Color getFontColor() const;
    sf::Color getAxesColor() const;
    sf::Color getScaleColor() const;
};
};
