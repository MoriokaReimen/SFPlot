#include "SFPlot/ArcData.hpp"
#include "SFPlot/Utility.hpp"

namespace sf
{

/**
 * Constructor for ArcData class
 *
 * Construct ArcData class. Initialize color with random color
 * @see sf::getRandomColor() function
 *
 */
ArcData::ArcData()
    : color(getRandomColor()), value(0.f)
{
}
};