#include "maze.h"

// �ͦ��g�c���X�f
void generateExits() 
{
    for (int i = 0; i < 3; i++) 
    {
        exitPoint.row = ROWS - 1;  // �N�X�f�����m�]�m�b�̩����@��
        exitPoint.col = rand() % COLS;   // �ͦ��H���C��m�A��ܰg�c���X�f���C��m
        maze[exitPoint.row][exitPoint.col] = 0;  // �b�g�c���N������m���ȳ]�m��0�A��ܳq�D
    }
}