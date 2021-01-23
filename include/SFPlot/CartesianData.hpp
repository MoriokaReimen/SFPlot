#pragma once
#include <vector>
#include <utility>
#include <SFML/Graphics.hpp>

namespace sf
{
struct CartesianData {
    enum class PLOT_TYPE {
        POINT,
        LINE
    };
    std::vector<sf::Vector2f> data;
    sf::Color color;
    PLOT_TYPE type;

    CartesianData();
    virtual ~CartesianData();
    std::pair<float, float> getRangeX() const;
    std::pair<float, float> getRangeY() const;
};
};