#include "EndMenuText.h"

EndMenuText::EndMenuText(sf::RenderWindow& window)
{
    font.loadFromFile("fonts/Guardian Pro Italic.ttf");
    backgroundTexture.loadFromFile("images/background.jpg");
    scoreTexture.loadFromFile("images/score.jpg");
    gameoverTexture.loadFromFile("images/gameover.jpg");
    brownmedalTexture.loadFromFile("images/brown_medal.jpg");
    silvermedalTexture.loadFromFile("images/silver_medal.jpg");
    goldmedalTexture.loadFromFile("images/gold_medal.jpg");
    platiniummedalTexture.loadFromFile("images/platinium_medal.jpg");
    buttonTexture.loadFromFile("images/button.jpg");
    backButtonTexture.loadFromFile("images/back_button.jpg");


    scoreText.setFont(font);
    scoreText.setCharacterSize(48);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setPosition(515, 245);

    highScoreText.setFont(font);
    highScoreText.setCharacterSize(48);
    highScoreText.setFillColor(sf::Color::Black);
    highScoreText.setPosition(515, 325);

    backgroundSprite.setTexture(backgroundTexture);
    windowSize = window.getSize();
    backgroundSprite.setPosition(0, 0);
    float scaleX = 1.0f * windowSize.x / backgroundSprite.getLocalBounds().width;
    float scaleY = 1.0f * windowSize.y / backgroundSprite.getLocalBounds().height;
    backgroundSprite.setScale(scaleX, scaleY);

    scoreSprite.setTexture(scoreTexture);
    scoreSprite.setPosition(window.getSize().x / 2 - scoreSprite.getLocalBounds().width / 2, window.getSize().y / 2 - scoreSprite.getLocalBounds().height / 2);

    gameoverSprite.setTexture(gameoverTexture);
    gameoverSprite.setScale(2.0f, 2.0f);
    gameoverSprite.setPosition(window.getSize().x / 3 - gameoverSprite.getLocalBounds().width / 3, window.getSize().y / 5.5 - gameoverSprite.getLocalBounds().height / 5.5);

    brownmedalSprite.setTexture(brownmedalTexture);
    brownmedalSprite.setScale(1.5f, 1.5f);
    brownmedalSprite.setPosition(window.getSize().x / 3.3 - brownmedalSprite.getLocalBounds().width / 3.3, window.getSize().y / 2 - brownmedalSprite.getLocalBounds().height / 2);

    silvermedalSprite.setTexture(silvermedalTexture);
    silvermedalSprite.setScale(1.5f, 1.5f);
    silvermedalSprite.setPosition(window.getSize().x / 3.3 - silvermedalSprite.getLocalBounds().width / 3.3, window.getSize().y / 2 -silvermedalSprite.getLocalBounds().height / 2);

    goldmedalSprite.setTexture(goldmedalTexture);
    goldmedalSprite.setScale(1.5f, 1.5f);
    goldmedalSprite.setPosition(window.getSize().x / 3.3 - goldmedalSprite.getLocalBounds().width / 3.3, window.getSize().y / 2 -goldmedalSprite.getLocalBounds().height / 2);

    platiniummedalSprite.setTexture(platiniummedalTexture);
    platiniummedalSprite.setScale(1.5f, 1.5f);
    platiniummedalSprite.setPosition(window.getSize().x / 3.3 - platiniummedalSprite.getLocalBounds().width / 3.3, window.getSize().y / 2 -platiniummedalSprite.getLocalBounds().height / 2);

    buttonSprite.setTexture(buttonTexture);
    buttonSprite.setScale(3.0f, 3.0f);
    buttonSprite.setPosition(window.getSize().x / 4.2 - buttonSprite.getLocalBounds().width / 4.2, window.getSize().y / 1.3 -buttonSprite.getLocalBounds().height / 1.3);


    backButtonSprite.setTexture(backButtonTexture);
    backButtonSprite.setScale(3.0f, 3.0f);
    backButtonSprite.setPosition(window.getSize().x / 1.7 - backButtonSprite.getLocalBounds().width / 1.7, window.getSize().y / 1.3 - backButtonSprite.getLocalBounds().height / 1.3);


    highScore = 0;
}

void EndMenuText::draw(sf::RenderWindow& window, int score)
{
    if (score > highScore)
    {
        highScore = score;
    }

    scoreText.setString("" + std::to_string(score));
    highScoreText.setString("" + std::to_string(highScore));

    window.draw(backgroundSprite);
    window.draw(scoreSprite);
    window.draw(gameoverSprite);

    if (score >= 10 && score < 20)
    {
        window.draw(brownmedalSprite);
    }
    else if (score >= 20 && score < 30)
    {
        window.draw(silvermedalSprite);
    }
    else if (score >= 30 && score < 40)
    {
        window.draw(goldmedalSprite);
    }
    else if (score > 40)
    {
        window.draw(platiniummedalSprite);
    }

    window.draw(scoreText);
    window.draw(highScoreText);
    window.draw(buttonSprite);
    window.draw(backButtonSprite);
}

sf::Sprite& EndMenuText::getBackButtonSprite()
{
    return backButtonSprite;
}

sf::Sprite& EndMenuText::getButtonSprite()
{
    return buttonSprite;
}




