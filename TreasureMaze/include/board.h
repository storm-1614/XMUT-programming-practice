#pragma once

#include <ncurses.h>

class Board
{
  private:
    WINDOW *board_win;
    int col, row; // 大小
    int y, x;     // 左上角坐标
    static const int BOARD_COLS = 10;
    static const int BOARD_ROWS = 9;

    char board[BOARD_ROWS][BOARD_COLS + 1] = {"##########", 
                                              "#...T....#",  
                                              "#.######.#", 
                                              "#.#.##.#T#",
                                              "#.#.##.#.#",
                                              "#.#....#.#", 
                                              "#.######.#", 
                                              "#..T....E#",   
                                              "##########"};


  public:
    Board();
    Board(int height, int weigh);
    void initialize();
    void drawFrame();
    void drawBoard();
    char getChar(int x, int y);
    char getInputChar();
    char getBoard(int x, int y);
    void changeBoard(int x, int y, char dot);
    WINDOW *windowPoint();
};
