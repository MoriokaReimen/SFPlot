#include "SFPlot/CartesianAxes.hpp"
#include <cmath>
#include <sstream>
#include <iomanip>
#include "SFPlot/PlotConfig.hpp"

namespace sf
{
const sf::Vector2f CartesianAxes::DIMENSION{800.f, 600.f};
const sf::Vector2f CartesianAxes::MARGIN{40.f, 20.f};

void CartesianAxes::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    drawAxes(target, states);
    if (!font_.getInfo().family.empty()) {
        drawLegend(target, states);
    }

}

void CartesianAxes::drawAxes(sf::RenderTarget& target, sf::RenderStates states) const
{
    /* Draw X Axis */
    {
        sf::Vector2f x_start;
        sf::Vector2f x_end;
        x_start = sf::Vector2f(MARGIN.x, DIMENSION.y - MARGIN.y);
        x_end = sf::Vector2f(DIMENSION.x,  DIMENSION.y - MARGIN.y);

        sf::Vertex x_axes[] = {
            sf::Vertex(x_start, axes_color_),
            sf::Vertex(x_end, axes_color_)
        };
        target.draw(x_axes, 2, sf::Lines, states);
    }

    /* Draw X scale */
    for (int i = 1; i < 10; i++) {
        sf::Vector2f x_start;
        sf::Vector2f x_end;
        x_start = sf::Vector2f(MARGIN.x, DIMENSION.y - MARGIN.y - i * (DIMENSION.y - MARGIN.y ) / 9);
        x_end = sf::Vector2f(DIMENSION.x, DIMENSION.y - MARGIN.y - i * (DIMENSION.y - MARGIN.y ) / 9);

        sf::Vertex x_axes[] = {
            sf::Vertex(x_start, scale_color_),
            sf::Vertex(x_end, scale_color_)
        };
        target.draw(x_axes, 2, sf::Lines, states);
    }

    /* Draw Y Axis */
    {
        sf::Vector2f y_start;
        sf::Vector2f y_end;
        y_start = sf::Vector2f(MARGIN.x, 0);
        y_end = sf::Vector2f(MARGIN.x,  DIMENSION.y - MARGIN.y);

        sf::Vertex y_axes[] = {
            sf::Vertex(y_start, axes_color_),
            sf::Vertex(y_end, axes_color_)
        };
        target.draw(y_axes, 2, sf::Lines, states);
    }

    /* Draw Y scale */
    for (int i = 1; i < 10; i++) {
        sf::Vector2f y_start;
        sf::Vector2f y_end;
        y_start = sf::Vector2f(MARGIN.x + i * (DIMENSION.x - MARGIN.x) / 9, 0);
        y_end = sf::Vector2f(MARGIN.x + i * (DIMENSION.x - MARGIN.x) / 9,  DIMENSION.y - MARGIN.y);

        sf::Vertex y_axes[] = {
            sf::Vertex(y_start, scale_color_),
            sf::Vertex(y_end, scale_color_)
        };
        target.draw(y_axes, 2, sf::Lines, states);
    }

}

void CartesianAxes::drawLegend(sf::RenderTarget& target, sf::RenderStates states) const
{
    /* Draw x legend */
    const float x_step = (x_range_.second - x_range_.first) / 9;
    const int x_precision = std::abs(std::min(0.f, std::log10(x_step) - 2.f));

    for (int i = 0; i < 10; i++) {
        float val = x_range_.first + i * x_step;
        std::stringstream ss;
        ss.precision(x_precision);
        ss << std::fixed;
        ss << val;
        sf::Text legend;
        legend.setString(ss.str());
        legend.setFont(font_);
        legend.setFillColor(font_color_);
        legend.setCharacterSize(15);
        legend.setOrigin(legend.getGlobalBounds().width / 2.0, legend.getGlobalBounds().height / 2.0);
        legend.setPosition(MARGIN.x + i * (DIMENSION.x - MARGIN.x) / 9, DIMENSION.y - MARGIN.y + 10.f);
        target.draw(legend, states);
    }

    /* Draw y legend */
    const float y_step = (y_range_.second - y_range_.first) / 9;
    const int y_precision = std::abs(std::min(0.f, std::log10(y_step) - 2.f));

    for (int i = 0; i < 10; i++) {
        float val = y_range_.first + i * y_step;
        std::stringstream ss;
        ss.precision(y_precision);
        ss << std::fixed;
        ss.width(5);
        ss << val;
        sf::Text legend;
        legend.setString(ss.str());
        legend.setFont(font_);
        legend.setFillColor(font_color_);
        legend.setCharacterSize(15);
        legend.setOrigin(legend.getGlobalBounds().width, legend.getGlobalBounds().height);
        legend.setPosition(MARGIN.x - 10.f, DIMENSION.y - MARGIN.y - i * (DIMENSION.y - MARGIN.y ) / 9);
        target.draw(legend, states);
    }
}

CartesianAxes::CartesianAxes()
    : x_range_(), y_range_(), font_(plot_config.font), font_color_(plot_config.font_color),
      axes_color_(plot_config.axes_color), scale_color_(plot_config.scale_color)
{

}

CartesianAxes::~CartesianAxes()
{
}

/* setter functions **************************************************/
void CartesianAxes::setRangeX(const std::pair<float, float>& x_range)
{
    x_range_ = x_range;
}

void CartesianAxes::setRangeY(const std::pair<float, float>& y_range)
{
    y_range_ = y_range;
}

void CartesianAxes::setFont(const sf::Font& font)
{
    font_ = font;
}

void CartesianAxes::setAxesColor(const sf::Color& axes_color)
{
    axes_color_ = axes_color;
}

void CartesianAxes::setScaleColor(const sf::Color& scale_color)
{
    scale_color_ = scale_color;
}


void CartesianAxes::setFontColor(const sf::Color& font_color)
{
    font_color_ = font_color;
}

/* getter functions **************************************************/
std::pair<float, float> CartesianAxes::getRangeX() const
{
    return x_range_;
}

std::pair<float, float> CartesianAxes::getRangeY() const
{
    return y_range_;
}

sf::Font CartesianAxes::getFont() const
{
    return font_;
}

sf::Color CartesianAxes::getFontColor() const
{
    return font_color_;
}
sf::Color CartesianAxes::getAxesColor() const
{
    return axes_color_;
}

sf::Color CartesianAxes::getScaleColor() const
{
    return scale_color_;
}

};
