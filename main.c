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

// 隨機生成迷宮
void generateMaze() {
    srand(time(NULL));

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = rand() % 4 == 0 ? 1 : 0;
        }
    }

    // 確保起點和終點是通道
    maze[0][0] = 0;
    maze[exitRow][exitCol] = 0;
}

// 顯示迷宮
void displayMaze() {
#ifdef _WIN32
    system("cls");
#elif defined __linux__
    system("clear");
#endif

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == playerRow && j == playerCol) {
                printf("@ ");
            }
            else if (i == exitRow && j == exitCol) {
                printf("! ");
            }
            else if (maze[i][j] == 1) {
                printf("# ");
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// 移動玩家
void movePlayer(char direction) {
    switch (direction) {
    case 'W':
    case 'w':
        if (playerRow > 0 && maze[playerRow - 1][playerCol] == 0) {
            playerRow--;
        }
        break;

    case 'S':
    case 's':
        if (playerRow < ROWS - 1 && maze[playerRow + 1][playerCol] == 0) {
            playerRow++;
        }
        break;

    case 'A':
    case 'a':
        if (playerCol > 0 && maze[playerRow][playerCol - 1] == 0) {
            playerCol--;
        }
        break;

    case 'D':
    case 'd':
        if (playerCol < COLS - 1 && maze[playerRow][playerCol + 1] == 0) {
            playerCol++;
        }
        break;
    }
}

int main(void) {
    char move;
    bool gameOver = false;

    while (!gameOver) {
        generateMaze();  // 重新生成迷宮
        displayMaze();

#ifdef _WIN32
        move = _getch();
#elif defined __linux__
        move = getKeyPress();
#endif

        movePlayer(move);

        if (playerRow == exitRow && playerCol == exitCol) {
            gameOver = true;
            printf("恭喜你找到出口!\n");
        }
    }

    return 0;
}
