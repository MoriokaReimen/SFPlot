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

    CartesianChart chart;
    CartesianData data1, data2;
    data1.data = {{1.0, 2.0}, {2.0, 3.0}, {3.0, 2.0}, {4.0, -1.0}};
    data1.type = CartesianData::PLOT_TYPE::POINT;
    data2.data = {{1.0, 4.0}, {1.0, 3.0}, {3.0, 5.0}, {4.0, 5.0}};
    data2.type = CartesianData::PLOT_TYPE::LINE;
    chart.push_data(data1);
    chart.push_data(data2);
    chart.set_font(font);
    chart.setPosition(50, 50);
    chart.auto_range();

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
    pie.setScale(0.5f, 0.5f);

    RaderChart rader_chart;
    RaderData rader_data;
    rader_data.data = {{0.f, 100.f}, {45.f, 200.f}, {45.f, 50.f}, {120.f, 200.f}, {90.f, 120.f}};
    rader_data.color = sf::Color::Cyan;
    rader_chart.set_data(rader_data);
    rader_chart.move(1000.f, 400.f);
    rader_chart.set_font(font);

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
        window.display();
    }

    return EXIT_SUCCESS;
}
