#include "SFPlot/CartesianAxes.hpp"

const sf::Vector2f CartesianAxes::DIMENSION{800.f, 600.f};
const sf::Vector2f CartesianAxes::MARGIN{30.f, 30.f};

void CartesianAxes::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    /* Draw X Axis */
    {
        sf::Vector2f x_start;
        sf::Vector2f x_end;
        if (x_origin_type_ == ORIGIN_TYPE::ORIGIN_ZERO)
        {
            x_start = sf::Vector2f(MARGIN.x, DIMENSION.y - MARGIN.y);
            x_end = sf::Vector2f(DIMENSION.x,  DIMENSION.y - MARGIN.y);
        }
        else
        {
            x_start = sf::Vector2f(MARGIN.x, DIMENSION.y / 2.f);
            x_end = sf::Vector2f(DIMENSION.x,  DIMENSION.y / 2.f);
        }

        sf::Vertex x_axes[] =
        {
            sf::Vertex(x_start, sf::Color::White),
            sf::Vertex(x_end, sf::Color::White)
        };
        target.draw(x_axes, 2, sf::Lines, states);
    }

    /* Draw Y Axis */
    {
        sf::Vector2f y_start;
        sf::Vector2f y_end;
        if (y_origin_type_ == ORIGIN_TYPE::ORIGIN_ZERO)
        {
            y_start = sf::Vector2f(MARGIN.x, 0);
            y_end = sf::Vector2f(MARGIN.x,  DIMENSION.y - MARGIN.y);
        }
        else
        {
            y_start = sf::Vector2f(MARGIN.x + DIMENSION.x / 2.f, 0);
            y_end = sf::Vector2f(MARGIN.x + DIMENSION.x / 2.f,  DIMENSION.y);
        }

        sf::Vertex y_axes[] =
        {
            sf::Vertex(y_start, sf::Color::White),
            sf::Vertex(y_end, sf::Color::White)
        };
        target.draw(y_axes, 2, sf::Lines, states);
    }

}

CartesianAxes::CartesianAxes()
    : x_min_(0.f), x_max_(100.f), x_origin_type_(CartesianAxes::ORIGIN_TYPE::ORIGIN_ZERO),
      y_min_(0.f), y_max_(0.f), y_origin_type_(CartesianAxes::ORIGIN_TYPE::ORIGIN_ZERO),
      font_()
{

}

CartesianAxes::~CartesianAxes()
{
}

/* setter functions **************************************************/
void CartesianAxes::set_x_range(const float& min, const float& max)
{
    x_min_ = min;
    x_max_ = max;
}

void CartesianAxes::set_y_range(const float& min, const float& max)
{
    y_min_ = min;
    y_max_ = max;
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
    return std::pair<float, float>(x_min_, x_max_);
}

std::pair<float, float> CartesianAxes::get_y_range() const
{
    return std::pair<float, float>(y_min_, y_max_);
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
