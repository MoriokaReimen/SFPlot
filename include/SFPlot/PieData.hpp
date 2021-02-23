#pragma once
#include <map>
#include <string>
#include <SFML/Graphics.hpp>

namespace sf
{
/**
 * @relates PieChart
 * data class which holds data member of Pie chart plot.
 *
*/
struct PieData {
    double value;    /**< data value */
    sf::Color color; /**< color of the data */
    PieData();
};
};
