#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>  // Ture or False
#include <stdlib.h>
#include <time.h>
#include "maze.h"

// 迷宮
int maze[ROWS][COLS];

// 玩家的位置
int playerRow = 0;
int playerCol = 0;

// 出口位置
int exitRow = ROWS - 1;
int exitCol = COLS - 1;

int main(void) 
{
    char move;
    bool gameOver = false;

    while (!gameOver) 
    {
        generateMaze();  // 重新生成迷宮
        displayMaze();

#ifdef _WIN32
        move = _getch();
#elif defined __linux__
        move = getKeyPress();
#endif

        movePlayer(move);

        if (playerRow == exitRow && playerCol == exitCol) 
        {
            gameOver = true;
            printf("恭喜你找到出口!\n");
        }
    }

    return 0;
}
