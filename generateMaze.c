#include "maze.h"

// �H���ͦ��g�c
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

    // �T�O�_�I�M���I�O�q�D
    maze[0][0] = 0;
    maze[exitRow][exitCol] = 0;
}