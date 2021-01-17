#include "SFPlot/CartesianChart.hpp"
#include <limits>

namespace sf
{
void CartesianChart::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    target.draw(axes_, states);
    for (const auto& elem : data_set_) {
        switch (elem->type) {
        case CartesianData::PLOT_TYPE::POINT:
            draw_point(*elem, target, states, axes_.get_x_range(), axes_.get_y_range());
            break;
        case CartesianData::PLOT_TYPE::LINE:
            draw_line(*elem, target, states, axes_.get_x_range(), axes_.get_y_range());
            break;
        default:
            break;
        }
    }
}

void CartesianChart::draw_point(const CartesianData& elem, sf::RenderTarget& target, sf::RenderStates states, const std::pair<float, float>& x_range, const std::pair<float, float>& y_range) const
{
    /* draw data */
    for (auto it = elem.data.cbegin(); it != elem.data.cend(); it++) {
        constexpr float POINT_RADIUS = 5.f;
        const auto x = (it->x - x_range.first) / (x_range.second - x_range.first) * (axes_.DIMENSION.x - axes_.MARGIN.x) + axes_.MARGIN.x;
        const auto y = (axes_.DIMENSION.y - axes_.MARGIN.y) - (it->y - y_range.first) / (y_range.second - y_range.first) * (axes_.DIMENSION.y - axes_.MARGIN.y);

        sf::CircleShape point(POINT_RADIUS);
        point.setFillColor(elem.color);
        point.setPosition(x - POINT_RADIUS, y - POINT_RADIUS);

        target.draw(point, states);
    }

}

void CartesianChart::draw_line(const CartesianData& elem, sf::RenderTarget& target, sf::RenderStates states, const std::pair<float, float>& x_range, const std::pair<float, float>& y_range) const
{
    /* draw data */
    for (auto it = elem.data.cbegin(); it != elem.data.cend(); it++) {
        if (std::next(it) != elem.data.cend()) {
            auto line_start = *it;
            auto line_end = *std::next(it);

            line_start.x = (line_start.x - x_range.first) / (x_range.second - x_range.first) * (axes_.DIMENSION.x - axes_.MARGIN.x) + axes_.MARGIN.x;
            line_start.y = (axes_.DIMENSION.y - axes_.MARGIN.y) - (line_start.y - y_range.first) / (y_range.second - y_range.first) * (axes_.DIMENSION.y - axes_.MARGIN.y);

            line_end.x = (line_end.x - x_range.first) / (x_range.second - x_range.first) * (axes_.DIMENSION.x - axes_.MARGIN.x) + axes_.MARGIN.x;
            line_end.y = (axes_.DIMENSION.y - axes_.MARGIN.y) - (line_end.y - y_range.first) / (y_range.second - y_range.first) * (axes_.DIMENSION.y - axes_.MARGIN.y);

            sf::Vertex line[] = {
                sf::Vertex(line_start, elem.color),
                sf::Vertex(line_end, elem.color)
            };
            target.draw(line, 2, sf::Lines, states);
        }
    }
}

CartesianChart::CartesianChart()
    : font_(), data_set_(), axes_()
{
}

CartesianChart::~CartesianChart()
{

}

/* setter functions */
std::shared_ptr<CartesianData> CartesianChart::add_data()
{
    auto data = std::make_shared<CartesianData>();
    data_set_.push_back(data);
    auto_range();

    return data;
}

void CartesianChart::add_data(std::shared_ptr<CartesianData> data)
{
    data_set_.push_back(data);
    auto_range();
}

void CartesianChart::set_font(const sf::Font& font)
{
    font_ = font;
    axes_.set_font(font_);
}

void CartesianChart::auto_range()
{
    float x_min = std::numeric_limits<float>::max();
    float x_max = std::numeric_limits<float>::lowest();
    float y_min = std::numeric_limits<float>::max();
    float y_max = std::numeric_limits<float>::lowest();

    for (const auto& elem : data_set_) {
        auto x_range = elem->get_x_range();
        x_min = std::min(x_range.first, x_min);
        x_max = std::max(x_range.second, x_max);

        auto y_range = elem->get_y_range();
        y_min = std::min(y_range.first, y_min);
        y_max = std::max(y_range.second, y_max);
    }

    set_x_range(x_min, x_max);
    set_y_range(y_min, y_max);
}

void CartesianChart::set_x_range(const float& min, const float& max)
{
    std::pair<float, float> x_range;
    if (min > max) {
        x_range = std::pair<float, float>(max, min);
    } else {
        x_range = std::pair<float, float>(min, max);
    }

    axes_.set_x_range(x_range);
}

void CartesianChart::set_y_range(const float& min, const float& max)
{
    std::pair<float, float> y_range;
    if (min > max) {
        y_range = std::pair<float, float>(max, min);
    } else {
        y_range = std::pair<float, float>(min, max);
    }

    axes_.set_y_range(y_range);
}

/* getter functions */
sf::Font CartesianChart::get_font() const
{
    return font_;
}

std::pair<float, float> CartesianChart::get_x_range() const
{
    return axes_.get_x_range();
}

std::pair<float, float> CartesianChart::get_y_range() const
{
    return axes_.get_y_range();
}

std::shared_ptr<CartesianData> CartesianChart::get_data(const std::size_t& index)
{
    return data_set_[index];
}
};
