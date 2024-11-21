#define NUMOFLIST 5
#define SIZE 5
#define UP 65
#define DOWN 66
#define ENTER 10
#define ARROW 91
#define BACK 127
#define YES 121
#define NO 110
#define NEW 0
#define DISPLAY 1
#define DELETE 2
#define MODIFIE 3
#define EXIT 4



typedef struct Employee
{
    int code;
    int salary;
    char name[50];
} employee;

// use an enum for platform-independent interface:
typedef enum TextColor
{
    TC_BLACK = 0,
    TC_BLUE = 1,
    TC_GREEN = 2,
    TC_CYAN = 3,
    TC_RED = 4,
    TC_MAGENTA = 5,
    TC_BROWN = 6,
    TC_LIGHTGRAY = 7,
    TC_DARKGRAY = 8,
    TC_LIGHTBLUE = 9,
    TC_LIGHTGREEN = 10,
    TC_LIGHTCYAN = 11,
    TC_LIGHTRED = 12,
    TC_LIGHTMAGENTA = 13,
    TC_YELLOW = 14,
    TC_WHITE = 15
} TextColor;

void switchoption(int numofoption);
void displayEmployee (employee e[],int size);
void enterNewEmployee (employee e[],int index);
void setTextColor(FILE *stream, TextColor color);
void gotoxy(int x,int y);
char getche(void);
char getch(void);