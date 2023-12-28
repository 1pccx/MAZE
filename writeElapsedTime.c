#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
FILE* pfile;

// 寫入每次遊戲結束經過的時間到文件中
void writeElapsedTime(double elapsedTime, int i)
{
    fprintf(pfile, "第%d次：%5.2f 秒\n", i, elapsedTime);
}