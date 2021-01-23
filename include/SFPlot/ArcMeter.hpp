#pragma once
#include <SFML/Graphics.hpp>
#include "SFPlot/ArcData.hpp"
#include <string>
#include <utility>
#include <memory>

namespace sf
{
class ArcMeter : virtual public sf::Drawable, virtual public sf::Transformable
{
    sf::Font font_;
    std::vector<std::shared_ptr<ArcData>> data_set_;
    std::pair<float, float> range_;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
public:
    ArcMeter(const float& min_range = 0.f, const float& max_range = 0.f);
    virtual ~ArcMeter();

    /* setter functions */
    void setFont(const sf::Font& font);
    void setMaxRange(const float& max_range);
    void setMinRange(const float& min_range);
    std::shared_ptr<ArcData> addData();
    void addData(std::shared_ptr<ArcData> data);

    /* getter functions */
    sf::Font getFont() const;
    float getValue() const;
    std::pair<float, float> getRange() const;
    float getMaxRange() const;
    float getMinRange() const;
    std::shared_ptr<ArcData> getData(const std::size_t& index);
};
};