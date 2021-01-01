#include "SFPlot/CartesianChart.hpp"
#include <limits>

void CartesianChart::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(axes_, states);

    switch (data_.type)
    {
    case CartesianData::PLOT_TYPE::POINT:
        draw_point(target, states);
        break;
    case CartesianData::PLOT_TYPE::LINE:
        draw_line(target, states);
        break;
    case CartesianData::PLOT_TYPE::BAR:
        draw_bar(target, states);
        break;
    default:
        break;
    }

}

void CartesianChart::draw_point(sf::RenderTarget& target, sf::RenderStates states) const
{
    /* Extract Data*/
    auto min_x = std::numeric_limits<float>::infinity();
    auto max_x = std::numeric_limits<float>::lowest();
    auto min_y = std::numeric_limits<float>::infinity();
    auto max_y = std::numeric_limits<float>::lowest();

    for (auto data : data_.data)
    {
        min_x = std::min(min_x, data.x);
        max_x = std::max(max_x, data.x);

        min_y = std::min(min_y, data.y);
        max_y = std::max(max_y, data.y);
    }

    /* draw data */
    for (auto it = data_.data.cbegin(); it != data_.data.cend(); it++)
    {
            constexpr float POINT_RADIUS = 5.f;
            const auto x = (it->x - min_x) / (max_x - min_x) * (axes_.DIMENSION.x - axes_.MARGIN.x) + axes_.MARGIN.x;
            const auto y = (axes_.DIMENSION.y - axes_.MARGIN.y) - (it->y - min_y) / (max_y - min_y) * (axes_.DIMENSION.y - axes_.MARGIN.y);

            sf::CircleShape point(POINT_RADIUS);
            point.setFillColor(data_.color);
            point.setPosition(x - POINT_RADIUS, y- POINT_RADIUS);

            target.draw(point, states);
    }

}

void CartesianChart::draw_line(sf::RenderTarget& target, sf::RenderStates states) const
{
    /* Extract Data*/
    auto min_x = std::numeric_limits<float>::infinity();
    auto max_x = std::numeric_limits<float>::lowest();
    auto min_y = std::numeric_limits<float>::infinity();
    auto max_y = std::numeric_limits<float>::lowest();

    for (auto data : data_.data)
    {
        min_x = std::min(min_x, data.x);
        max_x = std::max(max_x, data.x);

        min_y = std::min(min_y, data.y);
        max_y = std::max(max_y, data.y);
    }

    /* draw data */
    for (auto it = data_.data.cbegin(); it != data_.data.cend(); it++)
    {
        if (std::next(it) != data_.data.cend())
        {
            auto line_start = *it;
            auto line_end = *std::next(it);

            line_start.x = (line_start.x - min_x) / (max_x - min_x) * (axes_.DIMENSION.x - axes_.MARGIN.x) + axes_.MARGIN.x;
            line_start.y = (axes_.DIMENSION.y -axes_.MARGIN.y) - (line_start.y - min_y) / (max_y - min_y) * (axes_.DIMENSION.y - axes_.MARGIN.y);

            line_end.x = (line_end.x - min_x) / (max_x - min_x) * (axes_.DIMENSION.x - axes_.MARGIN.x) + axes_.MARGIN.x;
            line_end.y = (axes_.DIMENSION.y - axes_.MARGIN.y)- (line_end.y - min_y) / (max_y - min_y) * (axes_.DIMENSION.y -axes_.MARGIN.y);

            sf::Vertex line[] =
            {
                sf::Vertex(line_start, data_.color),
                sf::Vertex(line_end, data_.color)
            };
            target.draw(line, 2, sf::Lines, states);
        }
    }

}

void CartesianChart::draw_curve(sf::RenderTarget& target, sf::RenderStates states) const
{

}

void CartesianChart::draw_bar(sf::RenderTarget& target, sf::RenderStates states) const
{

}

CartesianChart::CartesianChart(const std::string& title)
    : title_(title), font_(), data_(), axes_()
{
}

CartesianChart::~CartesianChart()
{

}

/* setter functions */
void CartesianChart::set_data(const CartesianData& data)
{
    data_ = data;
}

void CartesianChart::set_font(const sf::Font& font)
{
    font_ = font;
}

void CartesianChart::set_axes(const CartesianAxes& axes)
{
    axes_ = axes;
}

/* getter functions */
CartesianData CartesianChart::get_data() const
{
    return data_;

}

sf::Font CartesianChart::get_font() const
{
    return font_;
}

CartesianAxes CartesianChart::get_axes() const
{
    return axes_;
}
