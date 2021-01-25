#include "SFPlot/PieData.hpp"
#include "SFPlot/Utility.hpp"

namespace sf
{

/**
 * Constructor for PieData class
 *
 * Construct RadarData class. Initialize color with random color
 * @see sf::getRandomColor() function
 *
 */
PieData::PieData()
    : color(getRandomColor()), value(0.f)
{
}

};