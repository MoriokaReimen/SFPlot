#include "SFPlot/PieData.hpp"

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

    for(const auto& elem : data)
    {
        total += elem.second;
    }

    return total;
}
