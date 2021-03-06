#include "SFPlot/PieChart.hpp"
#include "SFPlot/FanShape.hpp"
#include "SFPlot/PlotConfig.hpp"

#include <numeric>

namespace sf
{
static constexpr double RADIUS(250.0);

/**
 * get total value of data.
 */
double PieChart::getTotal() const
{
    double total =
        std::accumulate(data_set_.begin(), data_set_.end(), 0.0,
    [](const double & a, const std::shared_ptr<PieData>& b) {
        return a + b->value;
    } );

    return total;
}

/**
 * Drawing function derived from sf::Drawable
 *
 * @param target       Render Target
 * @param states       Render States
 *
 */
void PieChart::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    const double total = getTotal();
    double start_angle = 0U;

    for (auto const& data : data_set_) {
        double angle = 360.0 * data->value / total;
        FanShape shape(RADIUS, start_angle, start_angle + angle);
        shape.setFillColor(data->color);
        target.draw(shape, states);
        start_angle += angle;
    }
}

/**
 * Constructor for PieChart class
*/
PieChart::PieChart()
    : data_set_(), font_(plot_config.font)
{
}

/**
 * Destructor for PieChart class
*/
PieChart::~PieChart()
{
}

/* setter function */

/**
 * set font of legend
 * @param font font of legend
 *
*/
void PieChart::setFont(const sf::Font& font)
{
    font_ = font;
}

/**
 * add data of chart
 * @return pointer to added data
 *
*/
std::shared_ptr<PieData> PieChart::addData()
{
    auto data = std::make_shared<PieData>();
    data_set_.push_back(data);

    return data;
}

/**
 * add data of chart
 * @param data pointer to data
 *
*/
void PieChart::addData(std::shared_ptr<PieData> data)
{
    data_set_.push_back(data);
}

/* getter function */
/**
 * get legend font
 * @return legend font
 *
*/
sf::Font PieChart::getFont() const
{
    return font_;
}

/**
 * get pointer to chart data
 * @param index index of the data
 * @return pointer to data
 *
*/
std::shared_ptr<PieData> PieChart::getData(const std::size_t& index)
{
    return data_set_[index];
}
};
