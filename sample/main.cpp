#include <cstdlib>
#include <exception>

#include <SFPlot/CartesianChart.hpp>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "SFPlot/PieChart.hpp"
#include "SFPlot/FanShape.hpp"

int main()
{
    sf::ContextSettings settings;

    sf::RenderWindow window(sf::VideoMode(1600, 1200), "SFPlot-Sample", sf::Style::Default, settings);

    sf::Font font;
    if (!font.loadFromFile("resource/ipaexm.ttf"))
    {
        throw std::runtime_error("Failed to load resource/ipaexm.ttf");
    }

    CartesianChart chart("Chart1");
    CartesianData data;
    data.data = {{1.0, 2.0}, {2.0, 3.0}, {3.0, 2.0}, {4.0, -1.0}};
    data.type = CartesianData::PLOT_TYPE::POINT;
    chart.set_data(data);
    chart.set_font(font);
    chart.setPosition(50, 50);

    PieData pie_data;
    PieData::PieElement hoge_element;
    hoge_element.color = sf::Color::Red;
    hoge_element.value = 500.f;

    PieData::PieElement fuga_element;
    fuga_element.color = sf::Color::Blue;
    fuga_element.value = 300.f;


    pie_data.data.insert(std::pair<std::string, PieData::PieElement>("Hoge", hoge_element));
    pie_data.data.insert(std::pair<std::string, PieData::PieElement>("Fuga", fuga_element));
    PieChart pie;
    pie.set_data(pie_data);
    pie.move(1000.f, 0.f);

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
        window.display();
    }

    return EXIT_SUCCESS;
}
