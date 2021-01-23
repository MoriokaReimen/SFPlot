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
    void drawPoint(const CartesianData& elem, sf::RenderTarget& target, sf::RenderStates states,
                    const std::pair<float, float>& x_range, const std::pair<float, float>& y_range) const;
    void drawLine(const CartesianData& elem, sf::RenderTarget& target, sf::RenderStates states, const std::pair<float, float>& x_range, const std::pair<float, float>& y_range) const;
public:
    CartesianChart();
    virtual ~CartesianChart();

    /* setter functions */
    std::shared_ptr<CartesianData> addData();
    void addData(std::shared_ptr<CartesianData> data);
    void setFont(const sf::Font& font);
    void autoRange();
    void setRangeX(const float& min, const float& max);
    void setRangeY(const float& min, const float& max);

    /* getter functions */
    sf::Font getFont() const;
    std::pair<float, float> getRangeX() const;
    std::pair<float, float> getRangeY() const;
    std::shared_ptr<CartesianData> getData(const std::size_t& index);
};
};