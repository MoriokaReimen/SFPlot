#include "SFPlot/RaderData.hpp"
#include "SFPlot/Utility.hpp"
#include <limits>

namespace sf
{
RaderData::RaderData()
    : data(), color(getRandomColor())
{

}

RaderData::~RaderData()
{
}

float RaderData::getMaxValue() const
{
    auto max = std::numeric_limits<float>::lowest();

    for(const auto& elem : data) {
        max = std::max(max, elem.value);
    }

    return max;
}
};
