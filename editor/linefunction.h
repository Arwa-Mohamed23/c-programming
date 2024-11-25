#define TERMINATOR '\0'
#define SIZE 100
#define EXTENDCHAR 27
#define ARROW 91
#define LEFT 68
#define RIGHT 67
#define UP 65
#define DOWN 66
#define BACK 127
#define ENTER 10
#define SPACE 32
#define INSERT 50
#define DELETE 51
#define INSDEL 126

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

void setTextColor(FILE *stream, TextColor color);
void gotoxy(int x,int y);
char getche(void);
char getch(void);
void displayLine(int current,char line[]);
void enterChar(int current,int tail,char line[],char ch);
void deleteChar(int current,char line[]);
