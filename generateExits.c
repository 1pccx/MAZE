#include "maze.h"

// 生成迷宮的出口
void generateExits() 
{
    for (int i = 0; i < 3; i++) 
    {
        exitPoint.row = ROWS - 1;  // 將出口的行位置設置在最底部一排
        exitPoint.col = rand() % COLS;   // 生成隨機列位置，表示迷宮中出口的列位置
        maze[exitPoint.row][exitPoint.col] = 0;  // 在迷宮中將對應位置的值設置為0，表示通道
    }
}