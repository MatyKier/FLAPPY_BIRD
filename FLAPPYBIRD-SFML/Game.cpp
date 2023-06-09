#include "Game.h"
#include "Pipe.h"
#include <SFML/Audio.hpp>
#include <stdlib.h>

Game::Game(int width, int height) : bird(width, height), width(width), height(height), state(WAITING), pipeGapSize(300), score(0)
{
    pointBuffer.loadFromFile("sounds/point.wav");
    pointSound.setBuffer(pointBuffer);
    hitBuffer.loadFromFile("sounds/hit.wav");
    hitSound.setBuffer(hitBuffer);
    dieBuffer.loadFromFile("sounds/die.wav");
    dieSound.setBuffer(dieBuffer);
}

void Game::update()
{
    if (state == WAITING)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            state = RUNNING;
        }
        else
        {
            return;
        }
    }

    bird.update();

    for (auto& pipe : pipes)
    {
        pipe.update();
    }

    if (pipes.empty() || pipes.back().getX() < width - pipeGapSize)
    {
        int minGap = height / 8;
        int maxGap = 5 * height / 8;
        int gap = rand() % (maxGap - minGap) + minGap;
        int gapHeight = height / 3.5;

        pipes.push_back(Pipe(width, gap, gapHeight, difficulty));
    }

    if (pipes.front().getX() < -60)
    {
        pipes.erase(pipes.begin());
    }

    if (isCollision())
    {
        state = FINISHED_LOSS;
    }

    checkScore();
}

int Game::getWidth()
{
    return width;
}

int Game::getHeight()
{
    return height;
}

Bird& Game::getBird()
{
    return bird;
}

void Game::setDifficulty(Difficulty difficulty)
{
    this->difficulty = difficulty;

    for (auto& pipe : pipes)
    {
        pipe.setSpeed(speed);
    }
}

void Game::reset()
{
    bird = Bird(width / 2, height / 2);
    pipes.clear();
    int minGap = height / 8;
    int maxGap = 5 * height / 8;
    int gap = rand() % (maxGap - minGap) + minGap;
    int gapHeight = height / 4;

    pipes.push_back(Pipe(width, gap, gapHeight, difficulty));

    state = WAITING;
    score = 0;
}

bool Game::isCollision()
{
    if (state == WAITING)
    {
        return false;
    }

    if (bird.getY() < 0 || bird.getY() > height)
    {
        dieSound.play();
        return true;
    }

    for (const auto& pipe : pipes)
    {
        if (bird.getX() > pipe.getX() && bird.getX() < pipe.getX() + 50)
        {
            if (bird.getY() < pipe.getGap() -20 || bird.getY() > pipe.getGap() + pipe.getGapHeight() - 20)
            {
                hitSound.play();
                return true;
            }
        }
    }

    return false;
}

void Game::checkScore()
{
    for (auto& pipe : pipes)
    {
        if (bird.getX() > pipe.getX() + 50 && !pipe.isPassed())
        {
            pipe.setPassed(true);
            score++;
            pointSound.play();
        }
    }
}

GameState Game::getGameState()
{
    return state;
}

int Game::getScore()
{
    return score;
}

void Game::fly()
{
    bird.fly();
}

void Game::draw(sf::RenderWindow& window, GameText& gameText)
{
    gameText.draw(window, bird, pipes, height);
}

