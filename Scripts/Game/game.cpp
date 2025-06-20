#define _CRT_SECURE_NO_WARNINGS
#include "block.h"
#include "uiManager.h"
#include "devil.h"
#include "player.h"
#include "blockRandom.h"
#include <Windows.h>
#include "update.h"
#include "scence.h"


Block map[7][7];

int turnCount = 0;

void InitGame()
{
    printBGColor();
    printMapUI();
    printMapFrame();
    initMap(map);
    initPlayer();
    initDevil();
    printPlayerInfo();
    printDevilInfo();
    printTurnsInfo();
    turnCount = 0;

}

void UpdateGame()
{
    double TimePerFrame = 1000.0f / 60;

    DWORD lastTime = GetTickCount();

    while (1) {
        DWORD nowTime = GetTickCount();		
        DWORD deltaTime = nowTime - lastTime;  
        lastTime = nowTime;			

        update(deltaTime);
        if (g_Scene == SCENE_GAMEOVER || g_Scene == SCENE_YOUWIN) return;
        if (deltaTime <= TimePerFrame)
            Sleep(TimePerFrame - deltaTime);
    };
}