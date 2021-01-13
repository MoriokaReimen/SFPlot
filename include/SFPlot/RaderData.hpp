#pragma once
#include <SFML/Graphics.hpp>
#include <utility>
#include <vector>

namespace sf
{
struct RaderData {
    struct RaderElement {
        float angle;
        float value;
    };

    std::vector<RaderElement> data;
    sf::Color color;

    RaderData();
    virtual ~RaderData();
    float get_max_value() const;
};
};
