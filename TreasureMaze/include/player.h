#pragma once

#include <utility>

class Player
{
  public:
    Player();
    Player(int x, int y);
    ~Player();
    void setPosion(int x, int y);
    std::pair<int, int> getPos();
    int getx();
    int gety();
    int getScore();
    void scoreAdd();

  private:
    int x, y;
    int score;
};
