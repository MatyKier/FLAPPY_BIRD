#ifndef MODE_H
#define MODE_H

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "GameText.h"
#include "GameController.h"
#include "MainMenuText.h"
#include "MainMenuController.h"
#include "EndMenuText.h"
#include "EndMenuController.h"

enum GameMode { MAIN, GAME, END };

class Mode {
public:
    Mode(sf::RenderWindow &window);
    void handleEvent(sf::Event &event);
    void update(sf::RenderWindow &window);

private:
    GameMode gameMode;
    MainMenuText mainMenuText;
    MainMenuController mainMenuController;
    Game game;
    GameText gameText;
    GameController controller;
    EndMenuText endMenuText;
    EndMenuController endMenuController;
    int score;
};

#endif // MODE_H

