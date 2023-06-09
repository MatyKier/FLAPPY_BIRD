#ifndef MAINMENUTEXT_H
#define MAINMENUTEXT_H

#include <SFML/Graphics.hpp>
#include <vector>


class MainMenuText
{
public:
    MainMenuText(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
    sf::Sprite& getEasyButtonSprite();
    sf::Sprite& getMediumButtonSprite();
    sf::Sprite& getHardButtonSprite();
    sf::Sprite& getButtonSprite();

private:
    sf::Texture welcomeTexture;
    sf::Sprite welcomeSprite;
    sf::Texture birdTexture;
    sf::Sprite birdSprite;
    sf::Sprite backgroundSprite;
    sf::Texture backgroundTexture;
    sf::Texture buttonTexture;
    sf::Sprite buttonSprite;
    sf::Texture easyButtonTexture;
    sf::Sprite easyButtonSprite;
    sf::Texture mediumButtonTexture;
    sf::Sprite mediumButtonSprite;
    sf::Texture hardButtonTexture;
    sf::Sprite hardButtonSprite;
    sf::Vector2u windowSize;
};

#endif // MAINMENUTEXT_H

