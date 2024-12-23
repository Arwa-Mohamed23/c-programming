#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "empfunction.h"

/*
    Reference:-

        1- What is the equivalent to getch() & getche() in Linux?
            https://stackoverflow.com/questions/7469139/what-is-the-equivalent-to-getch-getche-in-linux
        2- Clear screen in C and C++ on UNIX-based system?
            https://stackoverflow.com/questions/17271576/clear-screen-in-c-and-c-on-unix-based-system
        3- Change text color using C
            https://stackoverflow.com/questions/44234508/change-text-color-using-c
*/
#ifdef _WIN32
    #include <windows.h>    // for win32 API functions
    #include <io.h>         // for _get_osfhandle()
#else
    #ifndef _POSIX_SOURCE
        #define _POSIX_SOURCE   // enable POSIX extensions in standard library headers
    #endif
    #include <unistd.h>     // for isatty()

    #include <termios.h> //for getch(),getche()
    static struct termios old, current;

    /* Initialize new terminal i/o settings */
    void initTermios(int echo)
    {
        tcgetattr(0, &old); /* grab old terminal i/o settings */
        current = old; /* make new settings same as old settings */
        current.c_lflag &= ~ICANON; /* disable buffered i/o */
        if (echo)
        {
            current.c_lflag |= ECHO; /* set echo mode */
        }
        else
        {
            current.c_lflag &= ~ECHO; /* set no echo mode */
        }
        tcsetattr(0, TCSANOW, &current); /* use these new terminal i/o settings now */
    }

    /* Restore old terminal i/o settings */
    void resetTermios(void)
    {
        tcsetattr(0, TCSANOW, &old);
    }

    /* Read 1 character - echo defines echo mode */
    char getch_(int echo)
    {
        char ch;
        initTermios(echo);
        ch = getchar();
        resetTermios();
        return ch;
    }

    /* Read 1 character without echo */
    char getch(void)
    {
        return getch_(0);
    }

    /* Read 1 character with echo */
    char getche(void)
    {
        return getch_(1);
    }

    // set output color on the given stream:
    void setTextColor(FILE *stream, TextColor color);
    //gotoxy function
    #define clear() printf("\033[H\033[J")
    void gotoxy(int x,int y)
    {
        printf("%c[%d;%df",0x1B,y,x);
    }
#endif

#ifdef _WIN32

void setTextColor(FILE *stream, TextColor color)
{
    int outfd = fileno(stream);
    HANDLE out = (HANDLE)_get_osfhandle(outfd);
    DWORD outType = GetFileType(out);
    DWORD mode;
    if (outType == FILE_TYPE_CHAR && GetConsoleMode(out, &mode))
    {
        // we're directly outputting to a win32 console if the file type
        // is FILE_TYPE_CHAR and GetConsoleMode() returns success

        SetConsoleTextAttribute(out, color);
        // the enum constants are defined to the same values
        // SetConsoleTextAttribute() uses, so just pass on.
    }
}

#else

static const char *ansiColorSequences[] =
{
    "\x1B[0;30m",
    "\x1B[0;34m",
    "\x1B[0;32m",
    "\x1B[0;36m",
    "\x1B[0;31m",
    "\x1B[0;35m",
    "\x1B[0;33m",
    "\x1B[0;37m",
    "\x1B[1;30m",
    "\x1B[1;34m",
    "\x1B[1;32m",
    "\x1B[1;36m",
    "\x1B[1;31m",
    "\x1B[1;35m",
    "\x1B[1;33m",
    "\x1B[1;37m"
};

static const char *ansiColorTerms[] =
{
    "xterm",
    "rxvt",
    "vt100",
    "linux",
    "screen",
    0
    // there are probably missing a few others
};

// get current terminal and check whether it's in our list of terminals
// supporting ANSI colors:
static int isAnsiColorTerm(void)
{
    char *term = getenv("TERM");
    for (const char **ansiTerm = &ansiColorTerms[0]; *ansiTerm; ++ansiTerm)
    {
        int match = 1;
        const char *t = term;
        const char *a = *ansiTerm;
        while (*a && *t)
        {
            if (*a++ != *t++)
            {
                match = 0;
                break;
            }
        }
        if (match) return 1;
    }
    return 0;
}

void setTextColor(FILE *stream, TextColor color)
{
    int outfd = fileno(stream);
    if (isatty(outfd) && isAnsiColorTerm())
    {
        // we're directly outputting to a terminal supporting ANSI colors,
        // so send the appropriate sequence:
        fputs(ansiColorSequences[color], stream);
    }
}




#endif
#ifdef _WIN32
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}
#else
void delay(int number_of_seconds) {
    fflush(stdout);
    // Converting time into clock ticks (assuming CLOCKS_PER_SEC is the number of clock ticks per second)
    int clock_ticks = number_of_seconds * CLOCKS_PER_SEC;

    // Storing start time
    clock_t start_time = clock();

    // Loop until the required time has passed
    while (clock() - start_time < clock_ticks) {
        // Busy-waiting, consuming CPU cycles (not efficient)
    }
    /*struct timespec req;
    req.tv_sec = 1;      // Delay for 1 second
    req.tv_nsec = number_of_seconds*1;  // 500 milliseconds (0.5 seconds)
    nanosleep(&req, NULL);  // Delay for 1.5 seconds*/
}
#endif
