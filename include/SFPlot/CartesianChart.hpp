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
/**
 * Cartesian Chart(X-Y plot) class
 *
*/
class CartesianChart : virtual public sf::Drawable, virtual public sf::Transformable
{
    std::vector<std::shared_ptr<CartesianData>> data_set_;
    CartesianAxes axes_;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void drawPoint(const CartesianData& elem, sf::RenderTarget& target, sf::RenderStates states,
                   const std::pair<double, double>& x_range, const std::pair<double, double>& y_range) const;
    void drawLine(const CartesianData& elem, sf::RenderTarget& target, sf::RenderStates states, const std::pair<double, double>& x_range, const std::pair<double, double>& y_range) const;
public:
    CartesianChart();
    virtual ~CartesianChart();

    /* setter functions */
    std::shared_ptr<CartesianData> addData();
    void addData(std::shared_ptr<CartesianData> data);
    void setFont(const sf::Font& font);
    void setFontColor(const sf::Color& font_color);
    void setAxesColor(const sf::Color& axes_color);
    void setScaleColor(const sf::Color& axes_color);
    void autoRange();
    void setRangeX(const double& min, const double& max);
    void setRangeY(const double& min, const double& max);

    /* getter functions */
    sf::Font getFont() const;
    sf::Color getFontColor() const;
    sf::Color getAxesColor() const;
    sf::Color getScaleColor() const;
    std::pair<double, double> getRangeX() const;
    std::pair<double, double> getRangeY() const;
    std::shared_ptr<CartesianData> getData(const std::size_t& index);
};
};
