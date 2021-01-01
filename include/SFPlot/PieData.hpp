#pragma once
#include <map>
#include <string>

struct PieData
{
    std::map<std::string, float> data;
    PieData();
    virtual ~PieData();
    float get_total() const;
};