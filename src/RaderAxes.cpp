#include "SFPlot/RaderAxes.hpp"
#include <vector>
#include <cmath>

const float RaderAxes::RADIUS(250.f);

void RaderAxes::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    draw_axes(target, states);
}

void RaderAxes::draw_axes(sf::RenderTarget& target, sf::RenderStates states) const
{
    const float RADIUS(250.f);
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
    for (size_t i = 1; i < 5; i++) {
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

RaderAxes::RaderAxes()
    : max_value_(0.0), font_()
{
}

RaderAxes::~RaderAxes()
{
}

/* setter functions ***************************************************/
void RaderAxes::set_max_value(const float& max_value)
{
    max_value_ = max_value;
}

void RaderAxes::set_font(const sf::Font& font)
{
    font_ = font;
}

/* getter functions ***************************************************/
float RaderAxes::get_max_value() const
{
    return max_value_;
}

sf::Font RaderAxes::get_font() const
{
    return font_;
}
