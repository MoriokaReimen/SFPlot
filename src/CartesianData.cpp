#include "SFPlot/CartesianData.hpp"

CartesianData::CartesianData()
    : name(), data(), color(sf::Color::Green), type(CartesianData::PLOT_TYPE::LINE)
{
}

CartesianData::~CartesianData()
{
}

std::pair<float, float> CartesianData::get_x_range() const
{
    /* Extract Data*/
    auto min_x = std::numeric_limits<float>::infinity();
    auto max_x = std::numeric_limits<float>::lowest();

    for (const auto& elem : data) {
        min_x = std::min(min_x, elem.x);
        max_x = std::max(max_x, elem.x);
    }

    return std::pair<float, float>(min_x, max_x);
}

std::pair<float, float> CartesianData::get_y_range() const
{
    /* Extract Data*/
    auto min_y = std::numeric_limits<float>::infinity();
    auto max_y = std::numeric_limits<float>::lowest();

    for (const auto& elem : data) {
        min_y = std::min(min_y, elem.y);
        max_y = std::max(max_y, elem.y);
    }

    return std::pair<float, float>(min_y, max_y);
}