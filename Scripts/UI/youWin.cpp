#define _CRT_SECURE_NO_WARNINGS
#include "drawImageCSV.h"
#include <corecrt_malloc.h>
#include <stdio.h>
#include <conio.h>
#include "scence.h"
#include <stdlib.h>
#include <windows.h>
#include "game.h"


Pixel youWin[25][80];

void InitYouWin()
{
    for (int i = 0; i < 25; ++i) {
        for (int j = 0; j < 80; ++j) {
            youWin[i][j] = {};
        }
    }
    LoadCSV("youWin.csv", youWin, 25, 80);
    DrawImage(youWin, 25, 80, 0, 1);
    printf("\x1b[6;54H\x1b[48;2;0;176;240m\x1b[38;2;255;255;255mターン\x1b[0m");

    const char* fullWidthDigits[] = { "０", "１", "２", "３", "４", "５", "６", "７", "８", "９" };
    char result[100] = "";
    char numStr[50];
    sprintf(numStr, "%d", turnCount);

    for (int i = 0; i < strlen(numStr); i++) {
        strcat(result, fullWidthDigits[numStr[i] - '0']);
    }

    printf("\x1b[8;56H\x1b[48;2;0;176;240m\x1b[38;2;255;255;255m%s\x1b[0m", result);
    printf("\x1b[22;34H\x1b[48;2;146;208;80m\x1b[38;2;255;255;255m伝説はつづく...\x1b[0m");


    while (_kbhit()) _getch(); 

    while (TRUE) {
        if (_kbhit()) 
        {
            _getch();
            break;
        }
        if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
        {
            break;
        }
        Sleep(50);
    }

    SetScene(SCENE_TITLE);
    CheckScene();

}

void UpdateYouWin()
{

}

void UninitYouWin()
{

}