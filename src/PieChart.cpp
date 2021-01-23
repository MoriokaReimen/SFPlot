#include "SFPlot/PieChart.hpp"
#include "SFPlot/FanShape.hpp"

namespace sf
{
static constexpr float RADIUS(250.f);
float PieChart::get_total() const
{
    float total = 0.f;

    for(const auto& data : data_set_) {
        total += data->value;
    }

    return total;
}

void PieChart::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    const float total = get_total();
    float start_angle = 0U;

    for(auto const& data : data_set_) {
        float angle = 360.f * data->value / total;
        FanShape shape(RADIUS, start_angle, start_angle + angle);
        shape.setFillColor(data->color);
        target.draw(shape, states);
        start_angle += angle;
    }
}

PieChart::PieChart()
    : data_set_(), font_()
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

std::shared_ptr<PieData> PieChart::add_data()
{
    auto data = std::make_shared<PieData>();
    data_set_.push_back(data);

    return data;
}

void PieChart::add_data(std::shared_ptr<PieData> data)
{
    data_set_.push_back(data);
}

/* getter function */
sf::Font PieChart::get_font() const
{
    return font_;
}

std::shared_ptr<PieData> PieChart::get_data(const std::size_t& index)
{
    return data_set_[index];
}
};
