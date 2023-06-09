#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class GameController
{
public:
    GameController(Game& game);
    void handleEvent(sf::Event& event);
    void update();

private:
    Game& game;
    sf::SoundBuffer soundBuffer;
    sf::Sound sound;
};

#endif // GAMECONTROLLER_H

