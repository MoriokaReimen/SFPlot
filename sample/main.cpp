#include <cstdlib>
#include <exception>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
    sf::ContextSettings settings;

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFPlot-Sample", sf::Style::Default, settings);

    sf::Font font;
    if(!font.loadFromFile("resource/ipaexm.ttf"))
    {
        throw std::runtime_error("Failed to load resource/ipaexm.ttf");
    }

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
        window.display();
    }

    return EXIT_SUCCESS;
}
