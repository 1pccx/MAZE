#include <stdbool.h>  
#include "maze.h"     

// 顯示迷宮函數
void displayMaze() 
{
#ifdef _WIN32
    system("cls");  // 清除Windows命令行窗口
#elif defined __linux__
    system("clear");  // 清除Linux终端窗口
#endif

    for (int i = 0; i < ROWS; i++) 
    {
        for (int j = 0; j < COLS; j++) 
        {
            if (i == playerRow && j == playerCol) 
            {
                printf("@ ");  // 如果當前位置是玩家位置，顯示玩家符號
            }
            else if (maze[i][j] == 1)
            {
                printf("# ");  // 如果當前位置是障礙物，顯示障礙物符號
            }
            else
            {
                bool Exit = false;  // 創建一個布林變數Exit，用於標記當前位置是否是出口
                
                // 迴圈檢查當前位置是否是其中一個出口
                for (int k = 0; k < 3; k++)
                {
                    if (i == exitPoint.row && j == exitPoint.col)
                    {
                        printf("! ");  // 如果當前位置是出口，顯示出口符號
                        Exit = true;
                        break;
                    }
                }
                if (!Exit)  // 如果當前位置不是出口，顯示空格
                {
                    printf("  ");
                }
            }
        }
        printf("\n");
    }
    printf("\n");
}
