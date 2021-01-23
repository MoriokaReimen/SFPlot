#include "SFPlot/Utility.hpp"
#include <cstdlib>
#include <limits>
#include <ctime>

namespace sf
{
sf::Color getRandomColor()
{
    sf::Uint8 red = std::rand() % std::numeric_limits<sf::Uint8>::max();
    sf::Uint8 green = std::rand() % std::numeric_limits<sf::Uint8>::max();
    sf::Uint8 blue = std::rand() % std::numeric_limits<sf::Uint8>::max();
    sf::Color color(red, green, blue);

    return color;
}

};