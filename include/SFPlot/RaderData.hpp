#pragma once
#include <SFML/Graphics.hpp>

struct RaderData
{
    struct RaderElement
    {
        float angle;
        float value;
    };

    std::vector<RaderElement> data;
    sf::Color color;

    RaderData();
    virtual ~RaderData();
};