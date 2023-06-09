#ifndef ENDMENUTEXT_H
#define ENDMENUTEXT_H

#include <SFML/Graphics.hpp>

class EndMenuText
{
public:
    EndMenuText(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window, int score);
    sf::Sprite& getBackButtonSprite();
    sf::Sprite& getButtonSprite();

private:
    sf::Font font;
    sf::Text scoreText;
    sf::Text highScoreText;
    sf::Sprite backgroundSprite;
    sf::Texture backgroundTexture;
    sf::Texture scoreTexture;
    sf::Sprite scoreSprite;
    sf::Texture gameoverTexture;
    sf::Sprite gameoverSprite;
    sf::Texture brownmedalTexture;
    sf::Sprite brownmedalSprite;
    sf::Texture silvermedalTexture;
    sf::Sprite silvermedalSprite;
    sf::Texture goldmedalTexture;
    sf::Sprite goldmedalSprite;
    sf::Texture platiniummedalTexture;
    sf::Sprite platiniummedalSprite;
    sf::Texture buttonTexture;
    sf::Sprite buttonSprite;
    sf::Texture backButtonTexture;
    sf::Sprite backButtonSprite;
    sf::Vector2u windowSize;
    int highScore;
};

#endif // ENDMENUTEXT_H

