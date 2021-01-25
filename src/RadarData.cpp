#include "SFPlot/RadarData.hpp"
#include "SFPlot/Utility.hpp"
#include <limits>

namespace sf
{
/**
 * Constructor for RadarData class
 *
 * Construct RadarData class. Initialize color with random color
 * @see sf::getRandomColor() function
 *
 */
RadarData::RadarData()
    : data(), color(getRandomColor())
{

}

/**
 * Destructor for RadarData class
 *
 */
RadarData::~RadarData()
{
}

/**
 * get max value of data
 * @return max value of data
 *
 */
float RadarData::getMaxValue() const
{
    auto max = std::numeric_limits<float>::lowest();

    for(const auto& elem : data) {
        max = std::max(max, elem.value);
    }

    return max;
}
};
