#include "SFPlot/PieChart.hpp"
#include "SFPlot/FanShape.hpp"

static constexpr float RADIUS(250.f);

void PieChart::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    const float total = data_.get_total();
    float start_angle = 0U;

    for(auto const& [key, val] : data_.data) {
        float angle = 360.f * val.value / total;
        FanShape shape(RADIUS, start_angle, start_angle + angle);
        shape.setFillColor(val.color);
        target.draw(shape, states);
        start_angle += angle;
    }
}

PieChart::PieChart()
    : data_(), font_()
{
}
PieChart::~PieChart()
{
}

/* setter function */
void PieChart::set_font(const sf::Font& font)
{
    font_ = font;
}

void PieChart::set_data(const PieData& data)
{
    data_ = data;
}

/* getter function */
sf::Font PieChart::get_font() const
{
    return font_;
}

PieData PieChart::get_data() const
{
    return data_;
}