#include "Bird.h"

Bird::Bird(int BirdX, int BirdY) : BirdX(BirdX), BirdY(BirdY), fallSpead(0)
{

}


void Bird::update()
{
    fallSpead = fallSpead + 1;
    BirdY = BirdY + fallSpead;
}

void Bird::fly()
{
    fallSpead = -15;
}

int Bird::getX() const
{
    return BirdX;
}

int Bird::getY() const
{
    return BirdY;
}

