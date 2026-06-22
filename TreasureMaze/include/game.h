/*
 * =====================================================================================
 *
 *       Filename:  game.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  06/22/2026 10:19:04 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  storm-1614
 *   Organization:
 *
 * =====================================================================================
 */

#pragma once

#include "board.h"
#include "player.h"
#include <stdlib.h>
#include <utility>

class Game
{
  public:
    Game();
    ~Game();
    void initialize();
    void processInput();
    void updateState();
    void redraw();

  private:
    bool running = true;
    Board *board;
    Player *charactor;
    std::pair<int, int> nextPos;
};
