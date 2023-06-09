#ifndef MAINMENUCONTROLLER_H
#define MAINMENUCONTROLLER_H

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "MainMenuText.h"
#include "Pipe.h"

class MainMenuController
{
public:
    MainMenuController(sf::RenderWindow& window, Game& game, MainMenuText& menuText);
    void handleEvent(sf::Event& event);
    bool isGameStarted();
    Difficulty getSelectedDifficulty() const;


private:
    Game& game;
    bool gameStarted;
    MainMenuText& menuText;
    Difficulty selectedDifficulty;
};

#endif // MAINMENUCONTROLLER_H

