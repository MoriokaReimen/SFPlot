#pragma once
#include <SFML/Graphics.hpp>

#include "CartesianAxes.hpp"
#include "CartesianData.hpp"

#include <vector>
#include <memory>
#include <string>
#include <utility>

namespace sf
{
class CartesianChart : virtual public sf::Drawable, virtual public sf::Transformable
{
    sf::Font font_;

    std::vector<std::shared_ptr<CartesianData>> data_set_;
    CartesianAxes axes_;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void draw_point(const CartesianData& elem, sf::RenderTarget& target, sf::RenderStates states,
                    const std::pair<float, float>& x_range, const std::pair<float, float>& y_range) const;
    void draw_line(const CartesianData& elem, sf::RenderTarget& target, sf::RenderStates states, const std::pair<float, float>& x_range, const std::pair<float, float>& y_range) const;
public:
    CartesianChart();
    virtual ~CartesianChart();

    /* setter functions */
    std::shared_ptr<CartesianData> add_data();
    void add_data(std::shared_ptr<CartesianData> data);
    void set_font(const sf::Font& font);
    void auto_range();
    void set_x_range(const float& min, const float& max);
    void set_y_range(const float& min, const float& max);

    /* getter functions */
    sf::Font get_font() const;
    std::pair<float, float> get_x_range() const;
    std::pair<float, float> get_y_range() const;
    std::shared_ptr<CartesianData> get_data(const std::size_t& index);
};
};