#pragma once
#include "SFPlot/RaderData.hpp"
#include "SFPlot/RaderAxes.hpp"

class RaderChart : public sf::Drawable, public sf::Transformable
{
    std::string title_;
    sf::Font font_;

    RaderData data_;
    RaderAxes axes_;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void draw_point(sf::RenderTarget& target, sf::RenderStates states, const float& max_value) const;
public:
    RaderChart(const std::string& title);
    virtual ~RaderChart();

    /* setter functions */
    void set_data(const RaderData& data);
    void set_font(const sf::Font& font);
    void set_axes(const RaderAxes& axes);

    /* getter functions */
    RaderData get_data() const;
    sf::Font get_font() const;
    RaderAxes get_axes() const;

};