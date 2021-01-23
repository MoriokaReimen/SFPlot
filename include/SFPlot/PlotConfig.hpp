#pragma once
#include <SFML/Graphics.hpp>

namespace sf
{
struct PlotConfig {
    sf::Color back_ground_color;
    sf::Color axes_color;
    sf::Color scale_color;
    sf::Font  font;
    sf::Color font_color;
};

extern PlotConfig plot_config;

};