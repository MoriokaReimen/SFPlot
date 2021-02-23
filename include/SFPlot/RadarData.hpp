#pragma once
#include <SFML/Graphics.hpp>
#include <utility>
#include <vector>

namespace sf
{
/**
 * @relates RadarChart
 * data class which holds data member of radar chart plot.
 *
*/
struct RadarData {
    /**
     * @relates RadarData
     * element of radar chart data
     *
     */
    struct RadarElement {
        double angle; /**< angle in degree */
        double value; /**< value (must be positive.)*/
    };

    std::vector<RadarElement> data; /**< plot data */
    sf::Color color; /**< plot color */

    RadarData();
    virtual ~RadarData();
    double getMaxValue() const;
};
};
