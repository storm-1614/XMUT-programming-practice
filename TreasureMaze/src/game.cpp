#include "game.h"
#include <ncurses.h>

Game::Game()
{
    initialize();
    while (running)
    {
        processInput();
        updateState();
        redraw();
        napms(20);
    }
    clear();
    delwin(board->windowPoint());
    printw("Game End\n");
    printw("scores: %d", charactor->getScore());
}

Game::~Game()
{
    delete board;
    delete charactor;
}

void Game::initialize()
{
    board = new Board;
    charactor = new Player(1, 1);
    board->initialize();
}

void Game::processInput()
{
    nextPos = {charactor->getx(), charactor->gety()};
    switch (board->getInputChar())
    {
    case 'q': {
        running = false;
        break;
    }
    case 'd': {
        nextPos.first++;
        break;
    }
    case 'a': {
        nextPos.first--;
        break;
    }
    case 'w': {
        nextPos.second--;
        break;
    }

    case 's': {
        nextPos.second++;
        break;
    }
    }
}

void Game::updateState()
{
    if (board->getChar(nextPos.first, nextPos.second) == '.')
    {
        board->changeBoard(charactor->getx(), charactor->gety(), '.');
        charactor->setPosion(nextPos.first, nextPos.second);
        board->changeBoard(nextPos.first, nextPos.second, 'S');
    }
    else if (board->getChar(nextPos.first, nextPos.second) == 'T')
    {
        board->changeBoard(charactor->getx(), charactor->gety(), '.');
        charactor->setPosion(nextPos.first, nextPos.second);
        charactor->scoreAdd();
        board->changeBoard(nextPos.first, nextPos.second, 'S');
    }
    else if (board->getChar(nextPos.first, nextPos.second) == 'E')
    {
        running = false;
    }
    else
    {
    }
}

void Game::redraw()
{
    board->drawBoard();
    wmove(board->windowPoint(), 9, 0);
    wprintw(board->windowPoint(), "pos: %d %d", charactor->getx(), charactor->gety());
    wmove(board->windowPoint(), 10, 0);
    wprintw(board->windowPoint(), "score: %d", charactor->getScore());
}
