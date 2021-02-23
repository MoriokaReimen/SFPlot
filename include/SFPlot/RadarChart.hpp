#pragma once
#include "SFPlot/RadarData.hpp"
#include "SFPlot/RadarAxes.hpp"
#include <vector>
#include <memory>
#include <utility>

namespace sf
{
/**
 * Radar Chart
 *
*/
class RadarChart : virtual public sf::Drawable, virtual public sf::Transformable
{
    sf::Font font_;

    std::vector<std::shared_ptr<RadarData>> data_set_;
    mutable RadarAxes axes_;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void drawPoint(sf::RenderTarget& target, sf::RenderStates states, const RadarData& data, const double& max_value) const;
    double getMaxValue() const;
public:
    RadarChart();
    virtual ~RadarChart();

    /* setter functions */
    std::shared_ptr<RadarData> addData();
    void addData(std::shared_ptr<RadarData> data);
    void setFont(const sf::Font& font);
    void setFontColor(const sf::Color& font_color);
    void setAxesColor(const sf::Color& axes_color);
    void setScaleColor(const sf::Color& scale_color);
    void autoRange();
    void setMaxValue(const double& max);

    /* getter functions */
    sf::Font getFont() const;
    sf::Color getFontColor() const;
    std::shared_ptr<RadarData> getData(const std::size_t& index);
    sf::Color getAxesColor() const;
    sf::Color getScaleColor() const;
};
};
