#include "SFPlot/CartesianAxes.hpp"
#include <cmath>
#include <sstream>
#include <iomanip>

const sf::Vector2f CartesianAxes::DIMENSION{800.f, 600.f};
const sf::Vector2f CartesianAxes::MARGIN{40.f, 20.f};

void CartesianAxes::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    draw_axes(target, states);
    if(!font_.getInfo().family.empty()) {
        draw_legend(target, states);
    }

}

void CartesianAxes::draw_axes(sf::RenderTarget& target, sf::RenderStates states) const
{
    /* Draw X Axis */
    {
        sf::Vector2f x_start;
        sf::Vector2f x_end;
        if (x_origin_type_ == ORIGIN_TYPE::ORIGIN_ZERO) {
            x_start = sf::Vector2f(MARGIN.x, DIMENSION.y - MARGIN.y);
            x_end = sf::Vector2f(DIMENSION.x,  DIMENSION.y - MARGIN.y);
        } else {
            x_start = sf::Vector2f(MARGIN.x, DIMENSION.y / 2.f);
            x_end = sf::Vector2f(DIMENSION.x,  DIMENSION.y / 2.f);
        }

        sf::Vertex x_axes[] = {
            sf::Vertex(x_start, sf::Color::White),
            sf::Vertex(x_end, sf::Color::White)
        };
        target.draw(x_axes, 2, sf::Lines, states);
    }

    /* Draw X scale */
    for(int i = 1; i < 10; i++) {
        sf::Vector2f x_start;
        sf::Vector2f x_end;
        if (x_origin_type_ == ORIGIN_TYPE::ORIGIN_ZERO) {
            x_start = sf::Vector2f(MARGIN.x, DIMENSION.y - MARGIN.y - i * (DIMENSION.y - MARGIN.y ) / 9);
            x_end = sf::Vector2f(DIMENSION.x, DIMENSION.y - MARGIN.y - i * (DIMENSION.y - MARGIN.y ) / 9);
        } else {
            x_start = sf::Vector2f(MARGIN.x, DIMENSION.y / 2.f);
            x_end = sf::Vector2f(DIMENSION.x,  DIMENSION.y / 2.f);
        }

        sf::Vertex x_axes[] = {
            sf::Vertex(x_start, sf::Color(150, 150, 150)),
            sf::Vertex(x_end, sf::Color(150, 150, 150))
        };
        target.draw(x_axes, 2, sf::Lines, states);
    }

    /* Draw Y Axis */
    {
        sf::Vector2f y_start;
        sf::Vector2f y_end;
        if (y_origin_type_ == ORIGIN_TYPE::ORIGIN_ZERO) {
            y_start = sf::Vector2f(MARGIN.x, 0);
            y_end = sf::Vector2f(MARGIN.x,  DIMENSION.y - MARGIN.y);
        } else {
            y_start = sf::Vector2f(MARGIN.x + DIMENSION.x / 2.f, 0);
            y_end = sf::Vector2f(MARGIN.x + DIMENSION.x / 2.f,  DIMENSION.y);
        }

        sf::Vertex y_axes[] = {
            sf::Vertex(y_start, sf::Color::White),
            sf::Vertex(y_end, sf::Color::White)
        };
        target.draw(y_axes, 2, sf::Lines, states);
    }

    /* Draw Y scale */
    for(int i = 1; i < 10; i++) {
        sf::Vector2f y_start;
        sf::Vector2f y_end;
        if (y_origin_type_ == ORIGIN_TYPE::ORIGIN_ZERO) {
            y_start = sf::Vector2f(MARGIN.x + i * (DIMENSION.x - MARGIN.x) / 9, 0);
            y_end = sf::Vector2f(MARGIN.x + i * (DIMENSION.x - MARGIN.x) / 9,  DIMENSION.y - MARGIN.y);
        } else {
            y_start = sf::Vector2f(MARGIN.x + DIMENSION.x / 2.f, 0);
            y_end = sf::Vector2f(MARGIN.x + DIMENSION.x / 2.f,  DIMENSION.y);
        }

        sf::Vertex y_axes[] = {
            sf::Vertex(y_start, sf::Color(150, 150, 150)),
            sf::Vertex(y_end, sf::Color(150, 150, 150))
        };
        target.draw(y_axes, 2, sf::Lines, states);
    }

}

void CartesianAxes::draw_legend(sf::RenderTarget& target, sf::RenderStates states) const
{
    /* Draw x legend */
    const float x_step = (x_range_.second - x_range_.first) / 9;
    const int x_precision = std::abs(std::min(0.f, std::log10(x_step) - 2.f));

    for(int i = 0; i < 10; i++) {
        float val = x_range_.first + i * x_step;
        std::stringstream ss;
        ss.precision(x_precision);
        ss << std::fixed;
        ss << val;
        sf::Text legend;
        legend.setString(ss.str());
        legend.setFont(font_);
        legend.setFillColor(sf::Color::White);
        legend.setCharacterSize(15);
        legend.setOrigin(legend.getGlobalBounds().width / 2.0, legend.getGlobalBounds().height / 2.0);
        legend.setPosition(MARGIN.x + i * (DIMENSION.x - MARGIN.x) / 9, DIMENSION.y - MARGIN.y + 10.f);
        target.draw(legend, states);
    }

    /* Draw y legend */
    const float y_step = (y_range_.second - y_range_.first) / 9;
    const int y_precision = std::abs(std::min(0.f, std::log10(y_step) - 2.f));

    for(int i = 0; i < 10; i++) {
        float val = y_range_.first + i * y_step;
        std::stringstream ss;
        ss.precision(y_precision);
        ss << std::fixed;
        ss.width(5);
        ss << val;
        sf::Text legend;
        legend.setString(ss.str());
        legend.setFont(font_);
        legend.setFillColor(sf::Color::White);
        legend.setCharacterSize(15);
        legend.setOrigin(legend.getGlobalBounds().width, legend.getGlobalBounds().height);
        legend.setPosition(MARGIN.x - 10.f, DIMENSION.y - MARGIN.y - i * (DIMENSION.y - MARGIN.y ) / 9);
        target.draw(legend, states);
    }
}

CartesianAxes::CartesianAxes()
    : x_range_(), x_origin_type_(CartesianAxes::ORIGIN_TYPE::ORIGIN_ZERO),
      y_range_(), y_origin_type_(CartesianAxes::ORIGIN_TYPE::ORIGIN_ZERO),
      font_()
{

}

CartesianAxes::~CartesianAxes()
{
}

/* setter functions **************************************************/
void CartesianAxes::set_x_range(const std::pair<float, float>& x_range)
{
    x_range_ = x_range;
}

void CartesianAxes::set_y_range(const std::pair<float, float>& y_range)
{
    y_range_ = y_range;
}

void CartesianAxes::set_x_origin_type(const ORIGIN_TYPE& origin_type)
{
    x_origin_type_ = origin_type;
}
void CartesianAxes::set_y_origin_type(const ORIGIN_TYPE& origin_type)
{
    y_origin_type_ = origin_type;
}

void CartesianAxes::set_font(const sf::Font& font)
{
    font_ = font;
}

/* getter functions **************************************************/
std::pair<float, float> CartesianAxes::get_x_range() const
{
    return x_range_;
}

std::pair<float, float> CartesianAxes::get_y_range() const
{
    return y_range_;
}

CartesianAxes::ORIGIN_TYPE CartesianAxes::get_x_origin_type() const
{
    return x_origin_type_;
}

CartesianAxes::ORIGIN_TYPE CartesianAxes::get_y_origin_type() const
{
    return y_origin_type_;
}

sf::Font CartesianAxes::get_font() const
{
    return font_;
}
