#ifndef GAME_H
#define GAME_H

#include "Bird.h"
#include "Pipe.h"
#include "GameText.h"
#include <SFML/Audio.hpp>

enum GameState { WAITING, RUNNING, FINISHED_LOSS };

class Game {
public:
    Game(int width, int height);
    int getWidth();
    int getHeight();
    Bird& getBird();
    void setDifficulty(Difficulty difficulty);
    void reset();
    void update();
    void fly();
    void draw(sf::RenderWindow& window, GameText& gameText);
    bool isCollision();
    void checkScore();
    GameState getGameState();
    int getScore();

private:
    int width;
    int height;
    Bird bird;
    std::vector<Pipe> pipes;
    GameState state;
    Difficulty difficulty;
    int pipeGapSize;
    int score;
    int speed;
    sf::SoundBuffer pointBuffer;
    sf::SoundBuffer hitBuffer;
    sf::SoundBuffer dieBuffer;
    sf::Sound pointSound;
    sf::Sound hitSound;
    sf::Sound dieSound;
};

#endif // GAME_H

