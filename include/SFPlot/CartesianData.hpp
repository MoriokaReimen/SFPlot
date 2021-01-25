#pragma once
#include <vector>
#include <utility>
#include <SFML/Graphics.hpp>

namespace sf
{
/**
 * @relates CartesianChart
 * data class which holds data member of cartesian chart plot.
 *
*/
struct CartesianData {
    /**
     * @relates CartesianData
     * specifier switches plotting method of data
     */
    enum class PLOT_TYPE {
        POINT,  /**< plot data with point */
        LINE   /**< plot data with line */
    };
    std::vector<sf::Vector2f> data; /**< value of each point */
    sf::Color color;                /**< plotting color */
    PLOT_TYPE type;                 /**< type of plot */

    CartesianData();
    virtual ~CartesianData();
    std::pair<float, float> getRangeX() const;
    std::pair<float, float> getRangeY() const;
};
};