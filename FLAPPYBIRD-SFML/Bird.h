#ifndef BIRD_H
#define BIRD_H

class Bird
{
public:
    Bird(int BirdX, int BirdY);
    void update();
    void fly();
    int getX() const;
    int getY() const;

private:
    int BirdX;
    int BirdY;
    int fallSpead;
};

#endif // BIRD_H

