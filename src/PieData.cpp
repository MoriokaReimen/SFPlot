#include "SFPlot/PieData.hpp"

namespace sf
{
PieData::PieElement::PieElement()
    : value(0.0), color(sf::Color::Green)
{
}

PieData::PieElement::~PieElement()
{
}

PieData::PieData()
    : data()
{

}

PieData::~PieData()
{
}

float PieData::get_total() const
{
    float total = 0.f;

    for(const auto& elem : data) {
        total += elem.second.value;
    }

    return total;
}
};
