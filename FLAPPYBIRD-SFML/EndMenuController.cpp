#include "EndMenuController.h"

EndMenuController::EndMenuController(sf::RenderWindow& window, Game& game, EndMenuText& endMenuText) : game(game), endMenuText(endMenuText), restartRequested(false), backRequested(false)
{

}

void EndMenuController::handleEvent(sf::Event& event)
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        if (endMenuText.getButtonSprite().getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
        {
            restartRequested = true;
            backRequested = false;
        }
        else if (endMenuText.getBackButtonSprite().getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
        {
            restartRequested = false;
            backRequested = true;
        }
    }
}

bool EndMenuController::isRestartRequested() const
{
    return restartRequested;
}

bool EndMenuController::isBackRequested() const
{
    return backRequested;
}

