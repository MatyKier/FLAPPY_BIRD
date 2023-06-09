#include "MainMenuText.h"

MainMenuText::MainMenuText(sf::RenderWindow& window)
{
    backgroundTexture.loadFromFile("images/background.jpg");
    birdTexture.loadFromFile("images/bird.jpg");
    buttonTexture.loadFromFile("images/button.jpg");
    welcomeTexture.loadFromFile("images/welcome.jpg");
    easyButtonTexture.loadFromFile("images/easy.jpg");
    mediumButtonTexture.loadFromFile("images/medium.jpg");
    hardButtonTexture.loadFromFile("images/hard.jpg");

    welcomeSprite.setTexture(welcomeTexture);
    welcomeSprite.setScale(4.0f, 4.0f);
    welcomeSprite.setPosition(window.getSize().x / 3.5- welcomeSprite.getLocalBounds().width / 3.5, window.getSize().y / 4 -welcomeSprite.getLocalBounds().height / 4);

    backgroundSprite.setTexture(backgroundTexture);
    windowSize = window.getSize();
    backgroundSprite.setPosition(0, 0);
    float scaleX = 1.0f * windowSize.x / backgroundSprite.getLocalBounds().width;
    float scaleY = 1.0f * windowSize.y / backgroundSprite.getLocalBounds().height;
    backgroundSprite.setScale(scaleX, scaleY);

    birdSprite.setTexture(birdTexture);
    birdSprite.setScale(4.0f, 4.0f);
    birdSprite.setPosition(window.getSize().x / 2 - birdSprite.getLocalBounds().width / 2, window.getSize().y / 2.35 -birdSprite.getLocalBounds().height / 2.35);

    buttonSprite.setTexture(buttonTexture);
    buttonSprite.setScale(2.5f, 2.5f);
    buttonSprite.setPosition(window.getSize().x / 2.2 - buttonSprite.getLocalBounds().width / 2.2, window.getSize().y / 1.7 -buttonSprite.getLocalBounds().height / 1.7);

    easyButtonSprite.setTexture(easyButtonTexture);
    easyButtonSprite.setPosition(window.getSize().x / 7 - easyButtonSprite.getLocalBounds().width / 5, window.getSize().y / 1.3);

    mediumButtonSprite.setTexture(mediumButtonTexture);
    mediumButtonSprite.setPosition(window.getSize().x / 2.25 - mediumButtonSprite.getLocalBounds().width / 5, window.getSize().y / 1.3);

    hardButtonSprite.setTexture(hardButtonTexture);
    hardButtonSprite.setPosition(3 * window.getSize().x / 4 - hardButtonSprite.getLocalBounds().width / 5, window.getSize().y / 1.3);


}

void MainMenuText::draw(sf::RenderWindow& window)
{
    window.draw(backgroundSprite);
    window.draw(welcomeSprite);
    window.draw(buttonSprite);
    window.draw(birdSprite);
    window.draw(easyButtonSprite);
    window.draw(mediumButtonSprite);
    window.draw(hardButtonSprite);
}

sf::Sprite& MainMenuText::getEasyButtonSprite()
{
    return easyButtonSprite;
}

sf::Sprite& MainMenuText::getMediumButtonSprite()
{
    return mediumButtonSprite;
}

sf::Sprite& MainMenuText::getHardButtonSprite()
{
    return hardButtonSprite;
}

sf::Sprite& MainMenuText::getButtonSprite()
{
    return buttonSprite;
}

