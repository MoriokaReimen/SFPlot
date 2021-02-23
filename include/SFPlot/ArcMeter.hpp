#pragma once
#include <SFML/Graphics.hpp>
#include "SFPlot/ArcData.hpp"
#include <string>
#include <utility>
#include <memory>

namespace sf
{

/**
 * @relates ArcData
 * Arc meter chart
 *
*/
class ArcMeter : virtual public sf::Drawable, virtual public sf::Transformable
{
    sf::Font font_;
    sf::Color font_color_;
    std::vector<std::shared_ptr<ArcData>> data_set_;
    std::pair<double, double> range_;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
public:
    ArcMeter(const double& min_range = 0.f, const double& max_range = 0.f);
    virtual ~ArcMeter();

    /* setter functions */
    void setFont(const sf::Font& font);
    void setFontColor(const sf::Color& color);
    void setMaxRange(const double& max_range);
    void setMinRange(const double& min_range);
    std::shared_ptr<ArcData> addData();
    void addData(std::shared_ptr<ArcData> data);

    /* getter functions */
    sf::Font getFont() const;
    sf::Color getFontColor() const;
    std::pair<double, double> getRange() const;
    double getMaxRange() const;
    double getMinRange() const;
    std::shared_ptr<ArcData> getData(const std::size_t& index);
};
};
