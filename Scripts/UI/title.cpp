#include "drawImageCSV.h"
#include <corecrt_malloc.h>
#include <stdio.h>
#include <conio.h>
#include "scence.h"
#include <stdlib.h>
#include <windows.h>

#include "audioManager.h"






Pixel title[25][80];

void InitTitle()
{

    playsound(bgmAudio, 1);

    for (int i = 0; i < 25; ++i) {
        for (int j = 0; j < 80; ++j) {
            title[i][j] = {};
        }
    }
    LoadCSV("title.csv", title, 25,80);
    DrawImage(title, 25,80, 0, 1);
    printf("\x1b[19;25H\x1b[48;2;0;176;240m\x1b[38;2;255;255;255m■「　The　Legend　Of　Block」■\033[0m");
    printf("\033[5m\x1b[23;31H\x1b[48;2;0;112;192m\x1b[38;2;255;255;255m任意キーでスタート");
    printf("\x1b[0m");


    
    while (TRUE) {
        if (_kbhit()) {
            break;
        }
        if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) 
        { 
            break;
        }
        Sleep(50); 
    }
  
    SetScene(SCENE_GAME);
    CheckScene();

}

void UpdateTitle()
{

}

void UninitTitle()
{
  
}