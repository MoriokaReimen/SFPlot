#pragma once
#include <SFML/Graphics.hpp>

namespace sf
{
/**
 * @relates ArcChart
 * data class which holds data member of Arc chart plot.
 *
*/
struct ArcData {
    sf::Color color; /**< color of data */
    double value;     /**< value of data */
    ArcData();
};
};
