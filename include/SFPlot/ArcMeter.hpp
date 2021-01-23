#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <utility>

namespace sf
{
class ArcMeter : virtual public sf::Drawable, virtual public sf::Transformable
{
    sf::Font font_;
    float value_;
    std::pair<float, float> range_;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
public:
    ArcMeter(const float& min_range = 0.f, const float& max_range = 0.f);
    virtual ~ArcMeter();

    /* setter functions */
    void setFont(const sf::Font& font);
    void setValue(const float& value);
    void setMaxRange(const float& max_range);
    void setMinRange(const float& min_range);

    /* getter functions */
    sf::Font getFont() const;
    float getValue() const;
    std::pair<float, float> getRange() const;
    float getMaxRange() const;
    float getMinRange() const;
};
};