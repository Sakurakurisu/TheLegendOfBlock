#include "drawImageCSV.h"
#include <corecrt_malloc.h>
#include <stdio.h>
#include <conio.h>
#include "scence.h"
#include <stdlib.h>
#include <windows.h>
#define CONIOEX
#include "conioex.h"
Pixel gameOver[25][80];

void InitGameOver()
{
    for (int i = 0; i < 25; ++i) {
        for (int j = 0; j < 80; ++j) {
            gameOver[i][j] = {};
        }
    }
    LoadCSV("gameOver.csv", gameOver, 25,80);
    DrawImage(gameOver, 25,80, 0, 1);
    printf("\x1b[20;14H\x1b[48;2;237;166;57m\x1b[38;2;248;248;248m続ける\x1b[0m");
    

    printf("\x1b[20;62H\x1b[48;2;0;176;240m\x1b[38;2;248;248;248m諦める\x1b[0m");
    printf("\x1b[22;35H\x1b[48;2;112;48;160m\x1b[38;2;248;248;248mやり直すか？\x1b[0m");

    while (1)
    {
        const HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
        const HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

        SetConsoleMode(hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
        int mouseX = inport(PM_CURX);
        int mouseY = inport(PM_CURY);

        if (mouseX > 13 && mouseX < 20 && mouseY>18 && mouseY < 22)
        {
            printf("\x1b[17;18H\x1b[48;2;30;8;85m\x1b[38;2;248;248;248m=\x1b[0m");
            printf("\x1b[18;18H\x1b[48;2;242;242;242m \x1b[0m");
            printf("\x1b[19;14H\x1b[48;2;237;166;57m\x1b[38;2;248;248;248m続ける\x1b[0m");
            printf("\x1b[20;14H\x1b[48;2;31;78;120m \x1b[0m");
            printf("\x1b[20;15H\x1b[48;2;30;8;85m   \x1b[0m");
            printf("\x1b[20;18H\x1b[48;2;242;242;242m \x1b[0m");
            printf("\x1b[20;19H\x1b[48;2;30;8;85m \x1b[0m");
            if (inport(PM_LEFT) != 0)
            {
                SetScene(SCENE_GAME);
                CheckScene();
            }
        }
        else
        {
            printf("\x1b[17;18H\x1b[48;2;30;8;85m\x1b[38;2;248;248;248m \x1b[0m");
            printf("\x1b[18;18H\x1b[48;2;30;8;85m\x1b[38;2;248;248;248m=\x1b[0m");
            printf("\x1b[19;18H\x1b[48;2;242;242;242m \x1b[0m");
            printf("\x1b[20;14H\x1b[48;2;237;166;57m\x1b[38;2;248;248;248m続ける\x1b[0m");
            printf("\x1b[19;14H\x1b[48;2;31;78;120m \x1b[0m");
            printf("\x1b[19;15H\x1b[48;2;30;8;85m   \x1b[0m");
            printf("\x1b[19;18H\x1b[48;2;242;242;242m \x1b[0m");
            printf("\x1b[19;19H\x1b[48;2;30;8;85m \x1b[0m");
        }

        if (mouseX > 61 && mouseX < 68 && mouseY>18 && mouseY < 22)
        {
           

            printf("\x1b[17;63H\x1b[48;2;30;8;85m\x1b[38;2;248;248;248m=\x1b[0m");
            printf("\x1b[18;63H\x1b[48;248;248;248m\x1b[38;2;248;248;248m \x1b[0m");
            printf("\x1b[19;62H\x1b[48;2;0;176;240m\x1b[38;2;248;248;248m諦める\x1b[0m");
            printf("\x1b[20;62H\x1b[48;2;30;8;85m \x1b[0m");
            printf("\x1b[20;63H\x1b[48;2;242;242;242m \x1b[0m");
            printf("\x1b[20;64H\x1b[48;2;30;8;85m   \x1b[0m");
            printf("\x1b[20;67H\x1b[48;2;31;78;120m \x1b[0m");
            

            if (inport(PM_LEFT)  != 0)
            {
                SetScene(SCENE_TITLE);
                CheckScene();
            }
        }
        else
        {
            printf("\x1b[17;63H\x1b[48;2;30;8;85m \x1b[0m");
            printf("\x1b[18;63H\x1b[48;2;30;8;85m\x1b[38;2;248;248;248m=\x1b[0m");
            printf("\x1b[19;62H\x1b[48;2;30;8;85m \x1b[0m");
            printf("\x1b[19;63H\x1b[48;2;242;242;242m \x1b[0m");
            printf("\x1b[19;64H\x1b[48;2;30;8;85m   \x1b[0m");
            printf("\x1b[19;67H\x1b[48;2;31;78;120m \x1b[0m");
            printf("\x1b[20;62H\x1b[48;2;0;176;240m\x1b[38;2;248;248;248m諦める\x1b[0m");
            
        }
    }


}

void UpdateGameOver()
{

}

void UninitGameOver()
{
  
}