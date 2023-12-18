#include "maze.h"

// 隨機生成迷宮
void generateMaze() 
{
    srand(time(NULL));

    for (int i = 0; i < ROWS; i++) 
    {
        for (int j = 0; j < COLS; j++) 
        {
            maze[i][j] = rand() % 4 == 0 ? 1 : 0;
        }
    }

    // 確保起點和終點是通道
    maze[0][0] = 0;
    maze[exitRow][exitCol] = 0;
}