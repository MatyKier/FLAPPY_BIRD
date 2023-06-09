#include "GameController.h"
#include "GameText.h"
#include "Game.h"

GameController::GameController(Game& game) : game(game)
{
    soundBuffer.loadFromFile("sounds/bird.wav");
    sound.setBuffer(soundBuffer);
}

void GameController::handleEvent(sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed && event.type != sf::Event::MouseMoved)
    {
        if (event.key.code == sf::Keyboard::Space)
        {
            if (game.getGameState() == WAITING)
            {
                game.reset();
            }
            else
            {
                game.fly();
                sound.play();
            }
        }
    }
}

void GameController::update()
{
    if (game.getGameState() == RUNNING || game.getGameState() == FINISHED_LOSS)
    {
        game.update();
    }
}

