#pragma once
#include "SFPlot/RaderData.hpp"
#include "SFPlot/RaderAxes.hpp"
#include <vector>
#include <memory>
#include <utility>

namespace sf
{
class RaderChart : virtual public sf::Drawable, virtual public sf::Transformable
{
    sf::Font font_;

    std::vector<std::shared_ptr<RaderData>> data_set_;
    mutable RaderAxes axes_;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void drawPoint(sf::RenderTarget& target, sf::RenderStates states, const RaderData& data, const float& max_value) const;
    float getMaxValue() const;
public:
    RaderChart();
    virtual ~RaderChart();

    /* setter functions */
    std::shared_ptr<RaderData> addData();
    void addData(std::shared_ptr<RaderData> data);
    void setFont(const sf::Font& font);
    void setAxes(const RaderAxes& axes);
    void autoRange();
    void setMaxValue(const float& max);

    /* getter functions */
    sf::Font getFont() const;
    RaderAxes getAxes() const;
    std::shared_ptr<RaderData> getData(const std::size_t& index);
};
};
