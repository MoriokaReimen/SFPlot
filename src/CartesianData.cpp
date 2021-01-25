#include "SFPlot/CartesianData.hpp"
#include "SFPlot/Utility.hpp"

namespace sf
{

/**
 * Constructor for CartesianData class
 *
 * Construct CartesianData class. Initialize color with random color
 * @see sf::getRandomColor() function
 *
 */
CartesianData::CartesianData()
    : data(), color(getRandomColor()), type(CartesianData::PLOT_TYPE::LINE)
{
}

/**
 * Constructor for CartesianData class
 *
*/
CartesianData::~CartesianData()
{
}

/**
 * get X value range of data
 * @return min, max pair of X value range
 *
*/
std::pair<float, float> CartesianData::getRangeX() const
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

/**
 * get Y value range of data
 * @return min, max pair of Y value range
 *
*/
std::pair<float, float> CartesianData::getRangeY() const
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
};
