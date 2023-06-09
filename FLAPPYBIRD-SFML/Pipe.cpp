#include "Pipe.h"

Pipe::Pipe(int BirdX, int gap, int gapHeight, Difficulty difficulty) : BirdX(BirdX), gap(gap), gapHeight(gapHeight), passed(false)
{
    switch(difficulty)
    {
        case Difficulty::EASY:
            speed = 4;
            break;
        case Difficulty::NORMAL:
            speed = 5;
            break;
        case Difficulty::HARD:
            speed = 7;
            break;
        default:
            speed = 5;
    }
}

void Pipe::update()
{
    BirdX = BirdX - speed;
}

int Pipe::getX() const
{
    return BirdX;
}

int Pipe::getGap() const
{
    return gap;
}

int Pipe::getGapHeight() const
{
    return gapHeight;
}

bool Pipe::isPassed() const
{
    return passed;
}

void Pipe::setPassed(bool passed)
{
    this->passed = passed;
}

void Pipe::setSpeed(int speed) {
    this->speed = speed;
}

