#pragma once
#include <SFML/Graphics.hpp>

#include "PieData.hpp"

class PieChart : public sf::Drawable, public sf::Transformable
{
    PieData data_;
    sf::Font font_;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
public:
    PieChart();
    virtual ~PieChart();

    /* setter function */
    void set_font(const sf::Font& font);
    void set_data(const PieData& data);

    /* getter function */
    sf::Font get_font() const;
    PieData get_data() const;
};