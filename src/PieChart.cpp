#include "SFPlot/PieChart.hpp"
static constexpr size_t POINTS(1000);
static constexpr float RADIUS(250.f);

void PieChart::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    const float total = data_.get_total();
    size_t start = 0U;

    for(const auto& [key, val] : data_)
    {
        auto points = static_cast<size_t>(val.value / total) * POINTS;
        start += points
        // target.draw(, states);
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