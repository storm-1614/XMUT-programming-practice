#include "board.h"
#include <ncurses.h>
#include <stdlib.h>

Board::Board(int height, int weigh)
{
    getmaxyx(stdscr, this->y, this->x);
    this->y = (this->y - height) / 2;
    this->x = (this->x - weigh) / 2;
    this->col = weigh;
    this->row = height;
}

Board::Board()
{
}

void Board::initialize()
{

    board_win = newwin(row, col, y, x);
    if (board_win == NULL)
    {
        printw("窗口创建错误： row=%d col=%d y=%d x=%d", row, col, y, x);
        refresh();
        return;
    }
    keypad(board_win, true);
    nodelay(board_win, true);
    noecho();
    curs_set(0);
}

void Board::drawFrame()
{
    // 保留旧接口，内部调用 drawBoard
    drawBoard();
}

char Board::getBoard(int x, int y)
{
    return board[x][y];
}
void Board::drawBoard()
{
    if (board_win == NULL)
        return;

    int offset_y = (row - 2 - BOARD_ROWS) / 2; // -2 是因为 box 占用了边框
    int offset_x = (col - 2 - BOARD_COLS) / 2;
    if (offset_y < 0)
        offset_y = 0;
    if (offset_x < 0)
        offset_x = 0;

    for (int r = 0; r < BOARD_ROWS; r++)
    {
        for (int c = 0; c < BOARD_COLS; c++)
        {
            char ch = board[r][c];
            chtype display_ch;

            switch (ch)
            {
            case '#':
                display_ch = '#';
                break;
            case '.':
                display_ch = '.';
                break;
            case 'S':
                display_ch = 'S';
                break;
            case 'T':
                display_ch = 'T';
                break;
            case 'E':
                display_ch = 'E';
                break;
            default:
                display_ch = ch;
                break;
            }

            mvwaddch(board_win, r, c, display_ch);
        }
    }

    wrefresh(board_win);
}

char Board::getChar(int x, int y)
{
    if (x > 0 && x < BOARD_ROWS && y > 0 && y < BOARD_COLS)
    {
        return mvwinch(board_win, y, x);
    }
    return '?';
}

char Board::getInputChar()
{
    return wgetch(board_win);
}

void Board::changeBoard(int x, int y, char dot)
{
    if (x > 0 && x < BOARD_ROWS && y > 0 && y < BOARD_COLS)
        board[y][x] = dot;
    else 
        wprintw(board_win, "ERROR");
}
WINDOW *Board::windowPoint()
{
    return board_win;
}
