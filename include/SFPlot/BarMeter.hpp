#pragma once
#include <SFML/Graphics.hpp>
#include "SFPlot/BarData.hpp"
#include <memory>
#include <vector>
#include <utility>

namespace sf
{
/**
 * @relates BarData
 * Bar meter chart
 *
*/
class BarMeter : virtual public sf::Drawable, virtual public sf::Transformable
{
    sf::Font font_;
    sf::Color font_color_;
    std::vector<std::shared_ptr<BarData>> data_set_;
    std::pair<double, double> range_;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
public:
    BarMeter(const double& min_range = 0.0, const double& max_range = 100.0);
    virtual ~BarMeter();

    /* setter functions */
    void setFont(const sf::Font& font);
    void setFontColor(const sf::Color& color);
    std::shared_ptr<BarData> addData();
    void addData(std::shared_ptr<BarData> data);
    void setMaxRange(const double& max_range);
    void setMinRange(const double& min_range);

    /* getter functions */
    sf::Font getFont() const;
    sf::Color getFontColor() const;
    std::shared_ptr<BarData> getData(const std::size_t& index);
    std::pair<double, double> getRange() const;
    double getMaxRange() const;
    double getMinRange() const;
};
};
