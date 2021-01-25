#include "SFPlot/BarData.hpp"
#include "SFPlot/Utility.hpp"

namespace sf
{
/**
 * Constructor for BarData class
 *
 * Construct BarData class. Initialize color with random color
 * @see sf::getRandomColor() function
 *
 */
BarData::BarData()
    : color(getRandomColor()), value(0.f)
{

}
};