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
    auto data1 = chart.addData();
    data1->data = {{1.0, 2.0}, {2.0, 3.0}, {3.0, 2.0}, {4.0, -1.0}};
    data1->type = sf::CartesianData::PLOT_TYPE::POINT;
    auto data2 = chart.addData();
    data2->data = {{1.0, 4.0}, {1.0, 3.0}, {3.0, 5.0}, {4.0, 5.0}};
    data2->type = sf::CartesianData::PLOT_TYPE::LINE;
    chart.setFont(font);
    chart.setPosition(50, 50);
    chart.autoRange();

    sf::PieChart pie;
    auto pie_data1 = pie.addData();
    auto pie_data2 = pie.addData();
    pie_data1->color = sf::Color::Blue;
    pie_data1->value = 500.f;
    pie_data2->color = sf::Color::Red;
    pie_data2->value = 300.f;


    pie.move(1000.f, 0.f);
    pie.setScale(0.5f, 0.5f);

    sf::RaderChart rader_chart;
    auto rader_data1 = rader_chart.addData();
    rader_data1->data = {{0.f, 100.f}, {45.f, 200.f}, {45.f, 50.f}, {120.f, 200.f}, {90.f, 120.f}};
    rader_data1->color = sf::Color::Cyan;
    rader_chart.autoRange();
    rader_chart.move(1000.f, 400.f);
    rader_chart.setFont(font);

    sf::BarMeter bar_meter;
    bar_meter.setFont(font);
    bar_meter.setMinRange(0.f);
    bar_meter.setMaxRange(100.f);
    bar_meter.setValue(45);

    sf::ArcMeter arc_meter;
    arc_meter.setFont(font);
    arc_meter.setMinRange(0.f);
    arc_meter.setMaxRange(100.f);
    auto arc_data1 = arc_meter.addData();
    arc_data1->color = sf::Color::Green;
    arc_data1->value = 50;
    auto arc_data2 = arc_meter.addData();
    arc_data2->color = sf::Color::Red;
    arc_data2->value = 70;
    auto arc_data3 = arc_meter.addData();
    arc_data3->color = sf::Color::Blue;
    arc_data3->value = 80;
    arc_meter.setScale(2.f, 2.f);

    arc_meter.setPosition(600, 600);

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
        window.draw(arc_meter);
        window.display();
    }

    return EXIT_SUCCESS;
}
