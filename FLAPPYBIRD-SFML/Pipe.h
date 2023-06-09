#ifndef PIPE_H
#define PIPE_H



enum Difficulty { EASY, NORMAL, HARD };

class Pipe {
public:
    Pipe(int BirdX, int gap, int gapHeight, Difficulty difficulty);
    void update();
    int getX() const;
    int getGap() const;
    int getGapHeight() const;
    bool isPassed() const;
    void setPassed(bool passed);
    void setSpeed(int speed);

private:
    int BirdX;
    int gap;
    int gapHeight;
    int speed;
    bool passed;
};

#endif // PIPE_H

