#ifndef GAMETEXT_H
#define GAMETEXT_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Bird.h"
#include "Pipe.h"

class GameText
{
public:
    GameText();
    void updateScore(int newScore);
    void draw(sf::RenderWindow& window, const Bird& bird, const std::vector<Pipe>& pipes, int height);

private:
    sf::Font font;
    sf::Text scoreText;
    sf::Texture birdTexture;
    sf::Texture topPipeTexture;
    sf::Texture bottomPipeTexture;
    sf::Texture backgroundTexture;
    sf::Sprite birdSprite;
    sf::Sprite topPipeSprite;
    sf::Sprite bottomPipeSprite;
    sf::Sprite backgroundSprite;
    sf::Vector2u windowSize;
    int score;
};

#endif // GAMETEXT_H
