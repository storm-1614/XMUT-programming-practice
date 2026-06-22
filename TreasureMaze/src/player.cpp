#include "player.h"

Player::Player(int x, int y)
{
    this->x = x;
    this->y = y;
    this->score = 0;
}

Player::~Player()
{
}
void Player::setPosion(int x, int y)
{
    this->x = x;
    this->y = y;
}
std::pair<int, int> Player::getPos()
{
    return std::pair<int, int>(this->x, this->y);
}

int Player::getx()
{
    return this->x;
}
int Player::gety()
{
    return this->y;
}

int Player::getScore()
{
    return this->score;
}

void Player::scoreAdd()
{
    score+=10;
}
