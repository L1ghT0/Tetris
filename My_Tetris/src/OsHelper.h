#ifndef TETRIS_OSHELPER_H
#define TETRIS_OSHELPER_H
#include <cstdlib>

#ifdef __linux__
#include <cstdio>
    #include <termios.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <ncurses.h>
    #include <cstdio>
#else
    #include<conio.h>
    #include<Windows.h>
#endif

class OsHelper {
private:
    static void input_enter_off() {
        struct termios t;
        tcgetattr(STDIN_FILENO, &t);
            t.c_lflag &= ~ICANON;
            tcsetattr(STDIN_FILENO, TCSANOW, &t);
        }

        static void input_enter_on() {
            struct termios t;
            tcgetattr(STDIN_FILENO, &t);
            t.c_lflag |= ICANON;
            tcsetattr(STDIN_FILENO, TCSANOW, &t);
        }
public:

    static char m_getch(){
#ifdef __linux__
        OsHelper::input_enter_on();
        OsHelper::input_enter_off();
        return getchar();
#else
        return _getch();
#endif
    }
    static void m_sysCLaer(){
#ifdef __linux__
        system("clear");
#else
        system("cls");
#endif
    }
    static void change_color(const int lineBackColor, const int fontColor){
#ifdef __linux__
#else
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, (WORD)((lineBackColor << 4) | fontColor));
#endif
    }
    static void reset_color(){
#ifdef __linux__
#else
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 7));
#endif
    }

    static int m_kbhit() {
#ifdef __linux__
        {
            struct termios oldt, newt;
            int ch;
            int oldf;

            tcgetattr(STDIN_FILENO, &oldt);
            newt = oldt;
            newt.c_lflag &= ~(ICANON | ECHO);
            tcsetattr(STDIN_FILENO, TCSANOW, &newt);
            oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
            fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

            ch = getchar();

            tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
            fcntl(STDIN_FILENO, F_SETFL, oldf);

            if (ch != EOF) {
                ungetc(ch, stdin);
                return 1;
            }
            return 0;
        }
#else
        _kbhit();
#endif
    }

#ifdef __linux__
    static const char enter = 10;
#else
    static const char enter = 13;
#endif

};

#endif //TETRIS_OSHELPER_H
