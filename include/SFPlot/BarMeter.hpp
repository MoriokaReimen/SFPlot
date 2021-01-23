#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <utility>

namespace sf
{
class BarMeter : virtual public sf::Drawable, virtual public sf::Transformable
{
    sf::Font font_;
    float value_;
    std::pair<float, float> range_;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
public:
    BarMeter(const float& min_range = 0.f, const float& max_range = 0.f);
    virtual ~BarMeter();

    /* setter functions */
    void setFont(const sf::Font& font);
    void setValue(const float& value);
    void setMaxRange(const float& max_range);
    void setMinRange(const float& min_range);

    /* getter functions */
    sf::Font getFont() const;
    float get_value() const;
    std::pair<float, float> get_range() const;
    float getMaxRange() const;
    float getMinRange() const;
};
};