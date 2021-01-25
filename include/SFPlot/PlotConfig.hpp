#pragma once
#include <SFML/Graphics.hpp>

namespace sf
{
/**
 * Data class which holds default plot settings
 *
*/
struct PlotConfig {
    sf::Color back_ground_color; /**< back ground color */
    sf::Color axes_color; /**< axes color */
    sf::Color scale_color; /**< scale color */
    sf::Font  font; /**< legend font */
    sf::Color font_color; /**< legend font color */
};

extern PlotConfig plot_config;

};