#pragma once
#include <vector>
#include <utility>
#include <SFML/Graphics.hpp>

struct CartesianData {
    enum class PLOT_TYPE {
        POINT,
        LINE
    };
    std::string name;
    std::vector<sf::Vector2f> data;
    sf::Color color;
    PLOT_TYPE type;

    CartesianData();
    virtual ~CartesianData();
    std::pair<float, float> get_x_range() const;
    std::pair<float, float> get_y_range() const;
};
