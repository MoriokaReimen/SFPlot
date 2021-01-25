#pragma once
#include <SFML/Graphics.hpp>

namespace sf
{
/**
 * @relates BarMeter
 * data class which holds data member of bar meter plot.
 *
*/
struct BarData {
    sf::Color color; /**< color of data */
    float value;     /**< value of data */
    BarData();
};
};