#pragma once
#include "SFPlot/RaderData.hpp"
#include "SFPlot/RaderAxes.hpp"
#include <vector>
#include <memory>
#include <utility>

namespace sf
{
class RaderChart : virtual public sf::Drawable, virtual public sf::Transformable
{
    sf::Font font_;

    std::vector<std::shared_ptr<RaderData>> data_set_;
    mutable RaderAxes axes_;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void draw_point(sf::RenderTarget& target, sf::RenderStates states, const RaderData& data, const float& max_value) const;
    float get_max_value() const;
public:
    RaderChart();
    virtual ~RaderChart();

    /* setter functions */
    std::shared_ptr<RaderData> add_data();
    void add_data(std::shared_ptr<RaderData> data);
    void set_font(const sf::Font& font);
    void set_axes(const RaderAxes& axes);
    void auto_range();
    void set_max_value(const float& max);

    /* getter functions */
    sf::Font get_font() const;
    RaderAxes get_axes() const;
    std::shared_ptr<RaderData> get_data(const std::size_t& index);
};
};
