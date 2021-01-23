#pragma once
#include <SFML/Graphics.hpp>
#include "SFPlot/BarData.hpp"
#include <memory>
#include <vector>
#include <utility>

namespace sf
{
class BarMeter : virtual public sf::Drawable, virtual public sf::Transformable
{
    sf::Font font_;
    std::vector<std::shared_ptr<BarData>> data_set_;
    std::pair<float, float> range_;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
public:
    BarMeter(const float& min_range = 0.f, const float& max_range = 100.f);
    virtual ~BarMeter();

    /* setter functions */
    void setFont(const sf::Font& font);
    std::shared_ptr<BarData> addData();
    void addData(std::shared_ptr<BarData> data);
    void setMaxRange(const float& max_range);
    void setMinRange(const float& min_range);

    /* getter functions */
    sf::Font getFont() const;
    std::shared_ptr<BarData> getData(const std::size_t& index);
    std::pair<float, float> getRange() const;
    float getMaxRange() const;
    float getMinRange() const;
};
};