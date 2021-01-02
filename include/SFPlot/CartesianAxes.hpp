#pragma once
#include <SFML/Graphics.hpp>
#include <utility>

class CartesianAxes : public sf::Transformable, public sf::Drawable
{
    enum class ORIGIN_TYPE
    {
        ORIGIN_ZERO,
        ORIGIN_MIDDLE
    };

    std::pair<float, float> x_range_;
    ORIGIN_TYPE x_origin_type_;

    std::pair<float, float> y_range_;
    ORIGIN_TYPE y_origin_type_;

    sf::Font font_;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void draw_axes(sf::RenderTarget& target, sf::RenderStates states) const;
    void draw_legend(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    static const sf::Vector2f DIMENSION;
    static const sf::Vector2f MARGIN;
    CartesianAxes();
    CartesianAxes& operator=(const CartesianAxes& other) = default;
    virtual ~CartesianAxes();

    /* setter functions */
    void set_x_range(const std::pair<float, float>& x_range);
    void set_y_range(const std::pair<float, float>& y_range);
    void set_x_origin_type(const ORIGIN_TYPE& origin_type);
    void set_y_origin_type(const ORIGIN_TYPE& origin_type);
    void set_font(const sf::Font& font);

    /* getter functions */
    std::pair<float, float> get_x_range() const;
    std::pair<float, float> get_y_range() const;
    ORIGIN_TYPE get_x_origin_type() const;
    ORIGIN_TYPE get_y_origin_type() const;
    sf::Font get_font() const;
};
