// https://geundung.dev/17?category=699626

#include <iostream>
#include <cstdio>
#include <windows.h>
#include <cstdlib>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

int keyControl();
void init();
void titleDraw();
int menuDraw();
void infoDraw();
void gotoxy(int, int);

int main() {
    init();
    while(1) {
        titleDraw();
        int menuCode = menuDraw();
        if(menuCode == 0) {

        }
        else if(menuCode == 1) {
            infoDraw();
        }
        else if(menuCode == 2) {
            return 0;
        }

        system("cls");
    }
    return 0;
}

void infoDraw() {
    system("cls");
    printf("\n\n");
    printf("            정보 만들기 귀찮음\n");

    while(1) {
        if(keyControl() == SUBMIT) break;
    }
}

int keyControl() {
    char temp = getch();

    if(temp=='w' || temp=='W') return UP;
    else if(temp=='a' || temp=='A') return LEFT;
    else if(temp=='s' || temp=='S') return DOWN;
    else if(temp=='d' || temp=='D') return RIGHT;
    else if(temp==' ') return SUBMIT;
}

void init() {
    system("mode con cols=56 lines=20 | title 게 임 제 목 ");
    
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = 0;
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

void titleDraw() {
    printf("\n\n\n\n");
    printf("        #####    ###     ###    #    ####   ##### \n");
    printf("        #       #       #      # #   #   #  #     \n");
    printf("        ####    ####    #     #####  ####   ####  \n");
    printf("        #           #   #     #   #  #      #     \n");
    printf("        #####   ####     ###  #   #  #      ##### \n");
}

int menuDraw() {
    int x = 24;
    int y = 12;

    gotoxy(x-2, y);
    printf("> 게 임 시 작");
    gotoxy(x, y+1);
    printf("게 임 정 보");
    gotoxy(x, y+2);
    printf("    종 료    ");

    while(1) {
        int n = keyControl();
        switch(n) {
            case UP: 
                if(y>12) {
                    gotoxy(x-2, y);
                    printf(" ");
                    gotoxy(x-2, --y);
                    printf(">");
                }
                break;
            case DOWN:
                if(y<14) {
                    gotoxy(x-2, y);
                    printf(" ");
                    gotoxy(x-2, ++y);
                    printf(">");
                }
                break;
            case SUBMIT: {
                return y-12;
            }
        }
    }
}

void gotoxy(int x, int y) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);
}
