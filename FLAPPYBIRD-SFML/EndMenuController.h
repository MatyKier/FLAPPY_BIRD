#ifndef ENDMENUCONTROLLER_H
#define ENDMENUCONTROLLER_H

#include <SFML/Graphics.hpp>
#include "EndMenuText.h"
#include "Game.h"

class EndMenuController
{
public:
    EndMenuController(sf::RenderWindow& window, Game& game, EndMenuText& endMenuText);
    void handleEvent(sf::Event& event);
    bool isRestartRequested() const;
    bool isBackRequested() const;

private:
    Game& game;
    EndMenuText& endMenuText;
    bool restartRequested;
    bool backRequested;
};

#endif // ENDMENUCONTROLLER_H

