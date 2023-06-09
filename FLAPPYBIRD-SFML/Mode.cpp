#include "Mode.h"

Mode::Mode(sf::RenderWindow &window) : game(800, 600), controller(game), mainMenuText(window), mainMenuController(window, game, mainMenuText), endMenuText(window), endMenuController(window, game, endMenuText)
{
    gameMode = MAIN;
    score = 0;
}

void Mode::handleEvent(sf::Event &event) {
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        if (gameMode == MAIN)
        {
            mainMenuController.handleEvent(event);
            if (mainMenuController.isGameStarted())
            {
                gameMode = GAME;
                game.setDifficulty(mainMenuController.getSelectedDifficulty());
                game.reset();
            }
        }
        else if (gameMode == END)
        {
            endMenuController.handleEvent(event);
            if (endMenuController.isRestartRequested())
            {
                gameMode = GAME;
                game.reset();
            }
            else if (endMenuController.isBackRequested())
            {
                gameMode = MAIN;
            }
        }
    }
    else if (gameMode == GAME)
    {
        controller.handleEvent(event);
        gameText.updateScore(game.getScore());

        if (game.getGameState() == FINISHED_LOSS)
        {
            gameMode = END;
            score = game.getScore();
        }
    }
}

void Mode::update(sf::RenderWindow &window) {
    window.clear();

    if (gameMode == MAIN)
    {
        mainMenuText.draw(window);
    }
    else if (gameMode == GAME)
    {
        game.draw(window, gameText);
        game.update();
    }
    else if (gameMode == END)
    {
        endMenuText.draw(window, score);
    }

    window.display();
}

