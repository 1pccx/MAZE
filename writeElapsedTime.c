#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
FILE* pfile;

// �g�J�C���C�������g�L���ɶ�����
void writeElapsedTime(double elapsedTime, int i)
{
    fprintf(pfile, "��%d���G%5.2f ��\n", i, elapsedTime);
}