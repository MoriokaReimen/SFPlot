#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "PieData.hpp"

namespace sf
{
class PieChart : virtual public sf::Drawable, virtual public sf::Transformable
{
    std::vector<std::shared_ptr<PieData>> data_set_;
    sf::Font font_;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    float get_total() const;
public:
    PieChart();
    virtual ~PieChart();

    /* setter function */
    void set_font(const sf::Font& font);
    std::shared_ptr<PieData> add_data();
    void add_data(std::shared_ptr<PieData> data);

    /* getter function */
    sf::Font get_font() const;
    std::shared_ptr<PieData> get_data(const std::size_t& index);
};
};
