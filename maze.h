#define ROWS 20
#define COLS 20

#ifdef _WIN32  // �P�_�@�~�t��
#include <conio.h>  // Windows
#elif defined __linux__  // �P�_�@�~�t��
#include <termios.h>   // Linux
#include <unistd.h>   // Linux

// �b Linux �U�����L���䪺�禡
char getKeyPress() 
{
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);  //�Ω�����зǿ�J�y���׺��ݩʡA�ñN��O�s�� oldt ��
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);  //�����F�׺ݪ��зǿ�J�Ҧ� (ICANON) �M�^���J (ECHO)
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);  //�Ω�]�m�зǿ�J�y���׺��ݩʡA�èϥ� TCSANOW �Ѽƪ�ܥߧY�ͮ�
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);  //��_�줧�e�O�s�� oldt ���ȡA�H�٭��l���׺��ݩ�
    return ch;
}
#else
#error "Unsupported platform"  // �p�G���䴩�����x�i�J�o�Ӱ϶��A�sĶ���|����
#endif

typedef struct 
{
    int row;
    int col;
} Exit;

Exit exitPoint;

void displayMaze();
void generateMaze();
void generateExits();
void movePlayer();
void writeElapsedTime();

//�~���ܼƫŧi
extern int maze[ROWS][COLS];
extern int playerRow;
extern int playerCol;
extern int exitRow;
extern int exitCol;