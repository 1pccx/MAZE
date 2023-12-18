#include "maze.h"

// Åã¥Ü°g®c
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