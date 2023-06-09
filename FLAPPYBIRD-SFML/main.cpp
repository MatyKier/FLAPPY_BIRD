#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include "GameController.h"
#include "GameText.h"
#include "Bird.h"
#include "Pipe.h"
#include "Mode.h"

int main()
{
    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode(800, 600), "Flappy Bird");
    window.setFramerateLimit(60);

    Mode mode(window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            mode.handleEvent(event);
        }
        mode.update(window);
    }
    return 0;
}

