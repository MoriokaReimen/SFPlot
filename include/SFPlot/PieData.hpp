#pragma once
#include <map>
#include <string>
#include <SFML/Graphics.hpp>

namespace sf
{
struct PieData {
    struct PieElement {
        float value;
        sf::Color color;
        PieElement();
        virtual ~PieElement();
    };

    std::map<std::string, PieElement> data;
    PieData();
    virtual ~PieData();
    float get_total() const;
};
};