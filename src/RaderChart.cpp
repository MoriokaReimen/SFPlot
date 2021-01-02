#include "SFPlot/RaderChart.hpp"

void RaderChart::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
}

void RaderChart::draw_point(sf::RenderTarget& target, sf::RenderStates states, const std::pair<float, float>& angle_range, const std::pair<float, float>& value_range) const
{
}

RaderChart::RaderChart(const std::string& title)
    : title_(title), font_(), data_()
{
}
    
RaderChart::~RaderChart()
{
}

/* setter functions */
void RaderChart::set_data(const RaderData& data)
{
    data_ = data;
}

void RaderChart::set_font(const sf::Font& font)
{
    font_ = font;
}

// void RaderChart::set_axes(const RaderAxes& axes);

/* getter functions */
RaderData RaderChart::get_data() const
{
    return data_;
}

sf::Font RaderChart::get_font() const
{
    return font_;
}

// RaderAxes RaderChart::get_axes() const;