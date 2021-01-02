#pragma once
#include <SFML/Graphics.hpp>

#include "CartesianAxes.hpp"
#include "CartesianData.hpp"

#include <vector>
#include <string>

class CartesianChart : public sf::Drawable, public sf::Transformable
{
    sf::Font font_;

    CartesianData data_;
    CartesianAxes axes_;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void draw_point(sf::RenderTarget& target, sf::RenderStates states,
                    const std::pair<float, float>& x_range, const std::pair<float, float>& y_range) const;
    void draw_line(sf::RenderTarget& target, sf::RenderStates states, const std::pair<float, float>& x_range, const std::pair<float, float>& y_range) const;
public:
    CartesianChart();
    virtual ~CartesianChart();

    /* setter functions */
    void set_data(const CartesianData& data);
    void set_font(const sf::Font& font);
    void set_axes(const CartesianAxes& axes);

    /* getter functions */
    CartesianData get_data() const;
    sf::Font get_font() const;
    CartesianAxes get_axes() const;
};
