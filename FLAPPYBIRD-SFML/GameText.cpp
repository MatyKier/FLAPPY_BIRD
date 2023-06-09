#include "GameText.h"
#include <iostream>

GameText::GameText()
{
    font.loadFromFile("fonts/rexlia rg.otf");
    birdTexture.loadFromFile("images/bird.jpg");
    topPipeTexture.loadFromFile("images/top_pipe.jpg");
    bottomPipeTexture.loadFromFile("images/bottom_pipe.jpg");
    backgroundTexture.loadFromFile("images/background.jpg");

    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10, 10);

    birdSprite.setTexture(birdTexture);
    topPipeSprite.setTexture(topPipeTexture);
    bottomPipeSprite.setTexture(bottomPipeTexture);
    backgroundSprite.setTexture(backgroundTexture);

    score = 0;
}

void GameText::updateScore(int newScore)
{
    score = newScore;

}

void GameText::draw(sf::RenderWindow& window, const Bird& bird, const std::vector<Pipe>& pipes, int height)
{
    window.draw(backgroundSprite);

    windowSize = window.getSize();
    float scaleX = 1.0f * windowSize.x / backgroundSprite.getLocalBounds().width;
    float scaleY = 1.0f * windowSize.y / backgroundSprite.getLocalBounds().height;
    backgroundSprite.setScale(scaleX, scaleY);

    birdSprite.setPosition(bird.getX(), bird.getY());
    birdSprite.setScale(3.0f, 3.0f);
    window.draw(birdSprite);

    topPipeSprite.setScale(2.0f, 2.0f);
    bottomPipeSprite.setScale(2.0f, 2.0f);

   for (std::size_t i = 0; i < pipes.size(); i++)
{
    const Pipe& pipe = pipes[i];

    topPipeSprite.setPosition(pipe.getX(), 0);
    topPipeSprite.setScale(2, pipe.getGap() / float(topPipeTexture.getSize().y));
    window.draw(topPipeSprite);

    bottomPipeSprite.setPosition(pipe.getX(), pipe.getGap() + pipe.getGapHeight());
    bottomPipeSprite.setScale(2, (height - (pipe.getGap() + pipe.getGapHeight())) / float(bottomPipeTexture.getSize().y));
    window.draw(bottomPipeSprite);
}

    scoreText.setString("Score: " + std::to_string(score));
    scoreText.setPosition(10, 10);
    window.draw(scoreText);
}

