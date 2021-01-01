#include <cstdlib>
#include <exception>

#include <SFPlot/CartesianChart.hpp>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

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
        window.display();
    }

    return EXIT_SUCCESS;
}
