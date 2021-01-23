#include <cstdlib>
#include <exception>

#include <SFPlot/CartesianChart.hpp>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <SFPlot/SFPlot.hpp>

int main()
{
    sf::ContextSettings settings;

    sf::RenderWindow window(sf::VideoMode(1600, 1200), "SFPlot-Sample", sf::Style::Default, settings);

    sf::Font font;
    if (!font.loadFromFile("resource/ipaexm.ttf"))
    {
        throw std::runtime_error("Failed to load resource/ipaexm.ttf");
    }

    sf::CartesianChart chart;
    auto data1 = chart.add_data();
    data1->data = {{1.0, 2.0}, {2.0, 3.0}, {3.0, 2.0}, {4.0, -1.0}};
    data1->type = sf::CartesianData::PLOT_TYPE::POINT;
    auto data2 = chart.add_data();
    data2->data = {{1.0, 4.0}, {1.0, 3.0}, {3.0, 5.0}, {4.0, 5.0}};
    data2->type = sf::CartesianData::PLOT_TYPE::LINE;
    chart.set_font(font);
    chart.setPosition(50, 50);
    chart.auto_range();

    sf::PieChart pie;
    auto pie_data1 = pie.add_data();
    auto pie_data2 = pie.add_data();
    pie_data1->color = sf::Color::Blue;
    pie_data1->value = 500.f;
    pie_data1->title = "fuga";
    pie_data2->color = sf::Color::Red;
    pie_data2->value = 300.f;
    pie_data2->title = "hoge";

    pie.move(1000.f, 0.f);
    pie.setScale(0.5f, 0.5f);

    sf::RaderChart rader_chart;
    auto rader_data1 = rader_chart.add_data();
    rader_data1->data = {{0.f, 100.f}, {45.f, 200.f}, {45.f, 50.f}, {120.f, 200.f}, {90.f, 120.f}};
    rader_data1->color = sf::Color::Cyan;
    rader_chart.auto_range();
    rader_chart.move(1000.f, 400.f);
    rader_chart.set_font(font);

    sf::BarMeter bar_meter;
    bar_meter.set_font(font);
    bar_meter.set_min_range(0.f);
    bar_meter.set_max_range(100.f);
    bar_meter.set_value(45);

    while (window.isOpen())
    {
        sf::Event event;
        if (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear(sf::Color(30, 30, 30));
        window.draw(chart);
        window.draw(pie);
        window.draw(rader_chart);
        window.draw(bar_meter);
        window.display();
    }

    return EXIT_SUCCESS;
}
