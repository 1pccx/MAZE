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

FILE* pfile;

int main(void) 
{
    char move;
    bool gameOver = false;
    time_t startTime, endTime;  //time_t：一種用來表示時間的數據類型。它通常用來存儲從某個特定時刻開始的秒數，可用來記錄程序的開始和結束時間
    double elapsedTime;
    double bestTime = -1; // 初始值為 -1，表示還沒有最佳時間
   
    pfile = fopen("time.txt", "a");
    if (pfile == NULL) 
    {
        printf("can't open file");
    }

    

    int i = 1; // 紀錄遊戲進行的次數

    while (1)
    {
        playerRow = 0;
        playerCol = 0;

        printf("歡迎來到走迷宮遊戲!\n");
        printf("最佳時間: %5.2f 秒\n", bestTime);
        printf("按下空白鍵開始遊戲...\n");

#ifdef _WIN32
        while (_getch() != ' ');
#elif defined __linux__
        while (getKeyPress() != ' ');
#endif

        startTime = time(NULL);
        gameOver = false;

        while (!gameOver)
        {
            generateMaze();
            generateExits(); // 生成新的出口
            displayMaze();

#ifdef _WIN32
            move = _getch();
#elif defined __linux__
            move = getKeyPress();
#endif

            movePlayer(move);


            if (playerRow == exitPoint.row && playerCol == exitPoint.col)
            {
                gameOver = true;
                break;
            }
        }

        if (gameOver)
        {
            endTime = time(NULL);
            elapsedTime = difftime(endTime, startTime);  //計算兩個時間點之間的時間差
            printf("恭喜你找到出口!\n");
            printf("遊戲時間: %5.2f 秒\n", elapsedTime);
            writeElapsedTime(elapsedTime, i); 
            if (bestTime == -1 || elapsedTime < bestTime)
            {
                bestTime = elapsedTime;
                printf("新紀錄！最佳時間: %.2f 秒\n", bestTime);
            }
            i++; // 遊戲次數加一
        }


        printf("按下空白鍵重新開始遊戲，或按下其他鍵結束程式...\n");

#ifdef _WIN32
        char restart = _getch();
#elif defined __linux__
        char restart = getKeyPress();
#endif

        if (restart != ' ')
        {
            fclose(pfile); // 關閉檔案
            break;        // 結束程式
        }
    }
}
