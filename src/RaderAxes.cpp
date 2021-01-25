#include "SFPlot/RadarAxes.hpp"
#include <vector>
#include <cmath>
#include <sstream>
#include "SFPlot/PlotConfig.hpp"

namespace sf
{
const float RadarAxes::RADIUS(250.f); /**< radius of plotting area */

/**
 * Drawing function derived from sf::Drawable
 *
 * @param target       Render Target
 * @param states       Render States
 *
 */
void RadarAxes::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    drawAxes(target, states);
    if(!font_.getInfo().family.empty()) {
        drawLegend(target, states);
    }
}

/**
 * draw axes
 *
 * @param target       Render Target
 * @param states       Render States
 *
 */
void RadarAxes::drawAxes(sf::RenderTarget& target, sf::RenderStates states) const
{
    /* Draw outer circle*/
    {
        std::vector<sf::Vertex> vertices;
        for (std::size_t index = 0; index < 31; index++) {
            sf::Vector2f point(RADIUS + RADIUS * std::sin(M_PI / 15 * index),
                               RADIUS + RADIUS * std::cos(M_PI / 15 * index));
            sf::Vertex vertex(point, axes_color_);
            vertices.push_back(vertex);
        }
        target.draw(&vertices[0], vertices.size(), sf::LineStrip, states);
    }

    /* Draw inner circle*/
    for (std::size_t i = 1; i < 5; i++) {
        float radius = RADIUS / 5.f * i;
        std::vector<sf::Vertex> vertices;
        for (std::size_t index = 0; index < 31; index++) {
            sf::Vector2f point(RADIUS + radius * std::sin(M_PI / 15 * index),
                               RADIUS + radius * std::cos(M_PI / 15 * index));
            sf::Vertex vertex(point, scale_color_);
            vertices.push_back(vertex);
        }
        target.draw(&vertices[0], vertices.size(), sf::LineStrip, states);
    }

    /* Draw Line*/
    {
        for (std::size_t index = 0; index < 4; index++) {
            sf::Vertex vertices[2];

            sf::Vector2f start_point(RADIUS + RADIUS * std::sin(M_PI / 4 * index),
                                     RADIUS + RADIUS * std::cos(M_PI / 4 * index));
            vertices[0] = sf::Vertex(start_point, axes_color_);

            sf::Vector2f end_point(RADIUS + RADIUS * std::sin(M_PI / 4 * index + M_PI),
                                   RADIUS + RADIUS * std::cos(M_PI / 4 * index + M_PI));
            vertices[1] = sf::Vertex(end_point, axes_color_);

            target.draw(vertices, 2, sf::Lines, states);
        }
    }
}
/**
 * draw legend
 *
 * @param target       Render Target
 * @param states       Render States
 *
 */
void RadarAxes::drawLegend(sf::RenderTarget& target, sf::RenderStates states) const
{
    /* Draw angle legend */
    constexpr float angle_step = 45.f;
    constexpr float MARGIN = 20.f;
    for(int i = 0; i < 8; i++) {
        float angle = angle_step * i;
        std::stringstream ss;
        ss << angle;
        sf::Text legend;
        legend.setString(ss.str());
        legend.setFont(font_);
        legend.setFillColor(font_color_);
        legend.setCharacterSize(15);
        legend.setOrigin(legend.getGlobalBounds().width / 2.0, legend.getGlobalBounds().height / 2.0);
        legend.setRotation(angle);
        sf::Vector2f position(RADIUS + (RADIUS + MARGIN) * std::sin(angle / 180.f * M_PI),
                              RADIUS - (RADIUS + MARGIN) * std::cos(angle / 180.f * M_PI));
        legend.setPosition(position);
        target.draw(legend, states);
    }

    /* Draw value legend */
    constexpr float X_MARGIN(20.f);
    constexpr float Y_MARGIN(10.f);
    float value_step = max_value_ / 5;
    for(int i = 0; i < 6; i++) {
        float value = value_step * i;
        std::stringstream ss;
        ss << value;
        sf::Text legend;
        legend.setString(ss.str());
        legend.setFont(font_);
        legend.setFillColor(font_color_);
        legend.setCharacterSize(15);
        legend.setOrigin(legend.getGlobalBounds().width / 2.0, legend.getGlobalBounds().height / 2.0);
        sf::Vector2f position(RADIUS - X_MARGIN, RADIUS - RADIUS / 5 * i - Y_MARGIN);
        legend.setPosition(position);
        target.draw(legend, states);
    }
}

/**
 * Constructor for RadarAxes class
*/
RadarAxes::RadarAxes()
    : max_value_(0.0), font_(plot_config.font), font_color_(plot_config.font_color),
      axes_color_(plot_config.axes_color), scale_color_(plot_config.scale_color)
{
}

/**
 * Destructor for RadarAxes class
*/
RadarAxes::~RadarAxes()
{
}

/**
 * set max value of plot range
 * @param max_value max value of plot range
 *
 */
void RadarAxes::setMaxValue(const float& max_value)
{
    max_value_ = max_value;
}

/**
 * set font of legend
 * @param font legend font
 *
 */
void RadarAxes::setFont(const sf::Font& font)
{
    font_ = font;
}

/**
 * set font color of legend
 * @param font_color font color of legend
 *
 */
void RadarAxes::setFontColor(const sf::Color& font_color)
{
    font_color_ = font_color;
}

/**
 * set axes color
 * @param axes_color axes color
 *
 */
void RadarAxes::setAxesColor(const sf::Color& axes_color)
{
    axes_color_ = axes_color;
}

/**
 * set scale color
 * @param scale_color set scale color
 *
 */
void RadarAxes::setScaleColor(const sf::Color& scale_color)
{
    scale_color_ = scale_color;
}

/**
 * get max value of plotting range
 * @return max value of plotting range
 *
 */
float RadarAxes::getMaxValue() const
{
    return max_value_;
}

/**
 * get font of legend
 * @return font of legend
 *
 */
sf::Font RadarAxes::getFont() const
{
    return font_;
}

/**
 * get font color
 * @return font color of legend
 *
 */
sf::Color RadarAxes::getFontColor() const
{
    return font_color_;
}

/**
 * get axes color
 * @return axes color
 *
 */
sf::Color RadarAxes::getAxesColor() const
{
    return axes_color_;
}

/**
 * get scale color
 * @return scale color
 *
 */
sf::Color RadarAxes::getScaleColor() const
{
    return scale_color_;
}

};
