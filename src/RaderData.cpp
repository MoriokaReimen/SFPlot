#include "SFPlot/RaderData.hpp"
#include <limits>

namespace sf
{
RaderData::RaderData()
    : data(), color(sf::Color::Green)
{

}

RaderData::~RaderData()
{
}

float RaderData::get_max_value() const
{
    auto max = std::numeric_limits<float>::lowest();

    for(const auto& elem : data) {
        max = std::max(max, elem.value);
    }

    return max;
}
};
