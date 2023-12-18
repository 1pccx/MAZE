#define ROWS 20
#define COLS 20

#ifdef _WIN32  // 判斷作業系統
#include <conio.h>  // Windows
#elif defined __linux__  // 判斷作業系統
#include <termios.h>   // Linux
#include <unistd.h>   // Linux

char getKeyPress() {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);  //用於獲取標準輸入流的終端屬性，並將其保存到 oldt 中
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);  //關閉了終端的標準輸入模式 (ICANON) 和回顯輸入 (ECHO)
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);  //用於設置標準輸入流的終端屬性，並使用 TCSANOW 參數表示立即生效
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);  //恢復到之前保存的 oldt 的值，以還原原始的終端屬性
    return ch;
}
#else
#error "Unsupported platform"  // 如果不支援的平台進入這個區塊，編譯器會報錯
#endif

void generateMaze();
void displayMaze();
void movePlayer(char direction);

extern int maze[ROWS][COLS];
extern int playerRow;
extern int playerCol;
extern int exitRow;
extern int exitCol;