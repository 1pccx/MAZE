#include "maze.h"

// 移動玩家
void movePlayer(char direction) 
{
    switch (direction) 
    {
    case 'W':
    case 'w':
        // 如果玩家不在迷宮的最上方且上方的位置是可通行的
        if (playerRow > 0 && maze[playerRow - 1][playerCol] == 0) 
        {
            playerRow--;  // 移動玩家位置到上方
            //在大多數座標系統中，較小的行座標表示位置在上方，所以 playerRow--使玩家向上移動
        }
        break;

    case 'S':
    case 's':
        // 如果玩家不在迷宮的最底部且下方的位置是可通行的
        if (playerRow < ROWS - 1 && maze[playerRow + 1][playerCol] == 0) 
        {
            playerRow++;  // 移動玩家位置到下方
        }
        break;

    case 'A':
    case 'a':
        // 如果玩家不在迷宮的最左側且左側的位置是可通行的
        if (playerCol > 0 && maze[playerRow][playerCol - 1] == 0) 
        {
            playerCol--;  // 移動玩家位置到左側
        }
        break;

    case 'D':
    case 'd':
        // 如果玩家不在迷宮的最右側且右側的位置是可通行的
        if (playerCol < COLS - 1 && maze[playerRow][playerCol + 1] == 0) 
        {
            playerCol++;  // 移動玩家位置到右側
        }
        break;
    }
}
