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
    void set_font(const sf::Font& font);
    void set_value(const float& value);
    void set_max_range(const float& max_range);
    void set_min_range(const float& min_range);

    /* getter functions */
    sf::Font get_font() const;
    float get_value() const;
    std::pair<float, float> get_range() const;
    float get_max_range() const;
    float get_min_range() const;
};
};