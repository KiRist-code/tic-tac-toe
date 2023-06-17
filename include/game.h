#pragma once

#if _WIN32 || _WIN64
#include<windows.h>
#define sleep(time) Sleep((time*1000))
#else
#include<unistd.h>
#endif

struct Board{
    int map[3][3];
};

struct Game{
    struct Board board;
    char player1[10];
    char player2[10];
    int winner;
};

struct Game *makeNewGame();

int checkBoard(struct Board* board,int player_id);
int isRow(int count);
int checkFilled(struct Board* board);

void pvp();