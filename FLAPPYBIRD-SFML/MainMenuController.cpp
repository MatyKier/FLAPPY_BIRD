#include "MainMenuController.h"
#include "MainMenuText.h"

MainMenuController::MainMenuController(sf::RenderWindow& window, Game& game, MainMenuText& menuText) : game(game), gameStarted(false), menuText(menuText), selectedDifficulty(Difficulty::EASY)
{

}

void MainMenuController::handleEvent(sf::Event& event)
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && event.type != sf::Event::MouseMoved)
    {
        if (menuText.getButtonSprite().getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
        {
            game.setDifficulty(selectedDifficulty);
            gameStarted = true;
            game.reset();
        }
    }

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        if (menuText.getEasyButtonSprite().getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
        {
            menuText.getEasyButtonSprite().setColor(sf::Color::Red);
            menuText.getMediumButtonSprite().setColor(sf::Color::White);
            menuText.getHardButtonSprite().setColor(sf::Color::White);
            selectedDifficulty = Difficulty::EASY;
        }

        else if (menuText.getMediumButtonSprite().getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
        {
            menuText.getEasyButtonSprite().setColor(sf::Color::White);
            menuText.getMediumButtonSprite().setColor(sf::Color::Red);
            menuText.getHardButtonSprite().setColor(sf::Color::White);
            selectedDifficulty = Difficulty::NORMAL;
        }

        else if (menuText.getHardButtonSprite().getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
        {
            menuText.getEasyButtonSprite().setColor(sf::Color::White);
            menuText.getMediumButtonSprite().setColor(sf::Color::White);
            menuText.getHardButtonSprite().setColor(sf::Color::Red);
            selectedDifficulty = Difficulty::HARD;
        }
    }
}

bool MainMenuController::isGameStarted()
{
    return gameStarted;
}

Difficulty MainMenuController::getSelectedDifficulty() const
{
    return selectedDifficulty;
}



