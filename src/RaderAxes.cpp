#include "SFPlot/RaderAxes.hpp"
#include <vector>
#include <cmath>
#include <sstream>
#include "SFPlot/PlotConfig.hpp"

namespace sf
{
const float RaderAxes::RADIUS(250.f);

void RaderAxes::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    drawAxes(target, states);
    if(!font_.getInfo().family.empty()) {
        drawLegend(target, states);
    }
}

void RaderAxes::drawAxes(sf::RenderTarget& target, sf::RenderStates states) const
{
    /* Draw outer circle*/
    {
        std::vector<sf::Vertex> vertices;
        for (std::size_t index = 0; index < 31; index++) {
            sf::Vector2f point(RADIUS + RADIUS * std::sin(M_PI / 15 * index),
                               RADIUS + RADIUS * std::cos(M_PI / 15 * index));
            sf::Vertex vertex(point, sf::Color::White);
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
            sf::Vertex vertex(point, sf::Color(150.f, 150.f, 150.f));
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
            vertices[0] = sf::Vertex(start_point, sf::Color::White);

            sf::Vector2f end_point(RADIUS + RADIUS * std::sin(M_PI / 4 * index + M_PI),
                                   RADIUS + RADIUS * std::cos(M_PI / 4 * index + M_PI));
            vertices[1] = sf::Vertex(end_point, sf::Color::White);

            target.draw(vertices, 2, sf::Lines, states);
        }
    }
}

void RaderAxes::drawLegend(sf::RenderTarget& target, sf::RenderStates states) const
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
        legend.setFillColor(sf::Color::White);
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
        legend.setFillColor(sf::Color::White);
        legend.setCharacterSize(15);
        legend.setOrigin(legend.getGlobalBounds().width / 2.0, legend.getGlobalBounds().height / 2.0);
        sf::Vector2f position(RADIUS - X_MARGIN, RADIUS - RADIUS / 5 * i - Y_MARGIN);
        legend.setPosition(position);
        target.draw(legend, states);
    }
}

RaderAxes::RaderAxes()
    : max_value_(0.0), font_(plot_config.font)
{
}

RaderAxes::~RaderAxes()
{
}

/* setter functions ***************************************************/
void RaderAxes::setMaxValue(const float& max_value)
{
    max_value_ = max_value;
}

void RaderAxes::setFont(const sf::Font& font)
{
    font_ = font;
}

/* getter functions ***************************************************/
float RaderAxes::getMaxValue() const
{
    return max_value_;
}

sf::Font RaderAxes::getFont() const
{
    return font_;
}
};
