#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "PieData.hpp"

namespace sf
{
/**
 * Pie chart class
 *
*/
class PieChart : virtual public sf::Drawable, virtual public sf::Transformable
{
    std::vector<std::shared_ptr<PieData>> data_set_;
    sf::Font font_;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    float getTotal() const;
public:
    PieChart();
    virtual ~PieChart();

    /* setter function */
    void setFont(const sf::Font& font);
    std::shared_ptr<PieData> addData();
    void addData(std::shared_ptr<PieData> data);

    /* getter function */
    sf::Font getFont() const;
    std::shared_ptr<PieData> getData(const std::size_t& index);
};
};
