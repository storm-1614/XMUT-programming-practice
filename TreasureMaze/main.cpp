/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  06/22/2026 10:15:40 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  storm-1614
 *   Organization:
 *
 * =====================================================================================
 */

#include <ncurses.h>

#include "game.h"
int main (int argc, char *argv[]) {
    initscr();
    start_color();

    refresh();

    Game game;

    getch();
    endwin();
    return 0;
}
