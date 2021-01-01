#include "SFPlot/CartesianChart.hpp"
#include <limits>

void CartesianChart::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    const auto x_range = data_.get_x_range();
    const auto y_range = data_.get_y_range();

    target.draw(axes_, states);
    switch (data_.type)
    {
    case CartesianData::PLOT_TYPE::POINT:
        draw_point(target, states, x_range, y_range);
        break;
    case CartesianData::PLOT_TYPE::LINE:
        draw_line(target, states, x_range, y_range);
        break;
    default:
        break;
    }

}

void CartesianChart::draw_point(sf::RenderTarget& target, sf::RenderStates states, const std::pair<float, float>& x_range, const std::pair<float, float>& y_range) const
{
    /* draw data */
    for (auto it = data_.data.cbegin(); it != data_.data.cend(); it++)
    {
            constexpr float POINT_RADIUS = 5.f;
            const auto x = (it->x - x_range.first) / (x_range.second - x_range.first) * (axes_.DIMENSION.x - axes_.MARGIN.x) + axes_.MARGIN.x;
            const auto y = (axes_.DIMENSION.y - axes_.MARGIN.y) - (it->y - y_range.first) / (y_range.second - y_range.first) * (axes_.DIMENSION.y - axes_.MARGIN.y);

            sf::CircleShape point(POINT_RADIUS);
            point.setFillColor(data_.color);
            point.setPosition(x - POINT_RADIUS, y- POINT_RADIUS);

            target.draw(point, states);
    }

}

void CartesianChart::draw_line(sf::RenderTarget& target, sf::RenderStates states, const std::pair<float, float>& x_range, const std::pair<float, float>& y_range) const
{
    /* draw data */
    for (auto it = data_.data.cbegin(); it != data_.data.cend(); it++)
    {
        if (std::next(it) != data_.data.cend())
        {
            auto line_start = *it;
            auto line_end = *std::next(it);

            line_start.x = (line_start.x - x_range.first) / (x_range.second - x_range.first) * (axes_.DIMENSION.x - axes_.MARGIN.x) + axes_.MARGIN.x;
            line_start.y = (axes_.DIMENSION.y -axes_.MARGIN.y) - (line_start.y - y_range.first) / (y_range.second - y_range.first) * (axes_.DIMENSION.y - axes_.MARGIN.y);

            line_end.x = (line_end.x - x_range.first) / (x_range.second - x_range.first) * (axes_.DIMENSION.x - axes_.MARGIN.x) + axes_.MARGIN.x;
            line_end.y = (axes_.DIMENSION.y - axes_.MARGIN.y)- (line_end.y - y_range.first) / (y_range.second - y_range.first) * (axes_.DIMENSION.y -axes_.MARGIN.y);

            sf::Vertex line[] =
            {
                sf::Vertex(line_start, data_.color),
                sf::Vertex(line_end, data_.color)
            };
            target.draw(line, 2, sf::Lines, states);
        }
    }

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
    axes_.set_x_range(data_.get_x_range());
    axes_.set_y_range(data_.get_y_range());
}

void CartesianChart::set_font(const sf::Font& font)
{
    font_ = font;
    axes_.set_font(font_);
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
