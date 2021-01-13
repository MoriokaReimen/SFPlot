#pragma once
#include <SFML/Graphics.hpp>

#include "CartesianAxes.hpp"
#include "CartesianData.hpp"

#include <vector>
#include <list>
#include <string>
#include <utility>

namespace sf
{
class CartesianChart : virtual public sf::Drawable, virtual public sf::Transformable
{
    sf::Font font_;

    std::list<CartesianData> data_set_;
    CartesianAxes axes_;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void draw_point(const CartesianData& elem, sf::RenderTarget& target, sf::RenderStates states,
                    const std::pair<float, float>& x_range, const std::pair<float, float>& y_range) const;
    void draw_line(const CartesianData& elem, sf::RenderTarget& target, sf::RenderStates states, const std::pair<float, float>& x_range, const std::pair<float, float>& y_range) const;
public:
    CartesianChart();
    virtual ~CartesianChart();

    /* setter functions */
    void push_data(const CartesianData& data);
    void set_font(const sf::Font& font);
    void set_axes(const CartesianAxes& axes);
    void auto_range();
    void set_x_range(const float& min, const float& max);
    void set_y_range(const float& min, const float& max);

    /* getter functions */
    sf::Font get_font() const;
    std::pair<float, float> get_x_range() const;
    std::pair<float, float> get_y_range() const;
};
};