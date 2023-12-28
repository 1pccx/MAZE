#include "maze.h"

// ²¾°Êª±®a
void movePlayer(char direction) 
{
    switch (direction) 
    {
    case 'W':
    case 'w':
        if (playerRow > 0 && maze[playerRow - 1][playerCol] == 0) 
        {
            playerRow--;
        }
        break;

    case 'S':
    case 's':
        if (playerRow < ROWS - 1 && maze[playerRow + 1][playerCol] == 0) 
        {
            playerRow++;
        }
        break;

    case 'A':
    case 'a':
        if (playerCol > 0 && maze[playerRow][playerCol - 1] == 0) 
        {
            playerCol--;
        }
        break;

    case 'D':
    case 'd':
        if (playerCol < COLS - 1 && maze[playerRow][playerCol + 1] == 0) 
        {
            playerCol++;
        }
        break;
    }
}