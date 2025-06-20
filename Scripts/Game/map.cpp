#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "block.h"
#include "color.h"
#include "map.h"
#include <windows.h>
#include "player.h"
#include "animation.h"

#define BUF_SIZE 1024*1024
extern char drawBuffer[BUF_SIZE];
extern char displayBuffer[BUF_SIZE];

void updateMap()
{
    int offset = 0;
    for (int i = 0; i < 7; i ++)
    {
        for (int j = 0; j < 7; j ++)
        {
            switch (map[i][j].colorEnum)
            {
                case Red:
                    printToBuffer(drawBuffer, &offset, &map[i][j], Red, RedBlockText, "○");
                    break;
                case Green:
                    printToBuffer(drawBuffer, &offset, &map[i][j], Green, GreenBlockText, "△");
                    break;
                case Blue:
                    printToBuffer(drawBuffer, &offset, &map[i][j], Blue, BlueBlockText, "×");
                    break;
                case EMPTY:
                    offset += sprintf(drawBuffer + offset, "\x1b[%d;%dH\x1b[48;2;%d;%d;%dm　　　\x1b[0m", map[i][j].position_x, map[i][j].position_y + 1, colors[map[i][j].colorEnum].R, colors[map[i][j].colorEnum].G, colors[map[i][j].colorEnum].B);
                    offset += sprintf(drawBuffer + offset, "\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm　%s　\x1b[0m", map[i][j].position_x + 1, map[i][j].position_y + 1, colors[map[i][j].colorEnum].R, colors[map[i][j].colorEnum].G, colors[map[i][j].colorEnum].B, colors[PointText].R, colors[PointText].G, colors[PointText].B, "・");
                    offset += sprintf(drawBuffer + offset, "\x1b[%d;%dH\x1b[48;2;%d;%d;%dm　　　\x1b[0m", map[i][j].position_x + 2, map[i][j].position_y + 1, colors[map[i][j].colorEnum].R, colors[map[i][j].colorEnum].G, colors[map[i][j].colorEnum].B);
                    break;
                case Barrier:
                    printBarrierToBuffer(drawBuffer, &offset, &map[i][j], Barrier, BarrierBlockText, shapeList[map[i][j].barrierLevel],5 -  map[i][j].barrierLevel);
                    break;
            }
            
        }    
    }
    displayScreenBuffer();
}

void bounceConsoleWindow(Direction direction, int value)
{
    HWND consoleWindow = GetConsoleWindow();
    RECT windowRect;
    GetWindowRect(consoleWindow, &windowRect);

    int originalX = windowRect.left;
    int originalY = windowRect.top;

    int distance_x = 0;
    int distance_y = 0;

    switch (direction)
    {
        case Up:
            distance_y = -value;
            break;
        case Down:
            distance_y = value;
            break;
        case Left:
            distance_x = -value;
            break;
        case Right:
            distance_x = value;
            break;
    }



    SetWindowPos(consoleWindow, 0, originalX + distance_x, originalY + distance_y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
    Sleep(100);

    SetWindowPos(consoleWindow, 0, originalX, originalY, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}

void move(Direction direction)
{
    int speed = 5;
    switch (direction)
    {
        case Up:
            // 上方向への移動
            for (int i = 6; i > 0; i--)
            {
                for (int j = 0; j < 7; j++)
                {
                    for (int k = i; k < 7; k++)
                    {
                        // 直上のブロックが空ならスワップ可能
                        if (map[k - 1][j].colorEnum == EMPTY)
                        {
                            // 色が異なり、両方バリアでないなら入れ替え
                            if (map[k][j].colorEnum != map[k - 1][j].colorEnum && map[k][j].colorEnum != Barrier && map[k - 1][j].colorEnum != Barrier)
                            {
                                swapColor(&map[k][j], &map[k - 1][j]);
                            }
                        }
                    }
                }
                updateMap();
                Sleep(speed); // アニメーション用の待機
            }
            break;

        case Down:
            // 下方向への移動
            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 7; j++)
                {
                    for (int k = i; k >= 0; k--)
                    {
                        // 直下が空ならスワップ可能
                        if (map[k + 1][j].colorEnum == EMPTY)
                        {
                            // 色が異なり、両方バリアでないなら入れ替え
                            if (map[k][j].colorEnum != map[k + 1][j].colorEnum && map[k][j].colorEnum != Barrier && map[k + 1][j].colorEnum != Barrier)
                            {
                                swapColor(&map[k][j], &map[k + 1][j]);
                            }
                        }
                    }
                }
                updateMap();
                Sleep(speed);
            }
            break;

        case Left:
            // 左方向への移動
            for (int i = 6; i > 0; i--)
            {
                for (int j = 0; j < 7; j++)
                {
                    for (int k = i; k < 7; k++)
                    {
                        if (map[j][k - 1].colorEnum == EMPTY)
                        {
                            if (map[j][k].colorEnum != map[j][k - 1].colorEnum && map[j][k].colorEnum != Barrier && map[j][k - 1].colorEnum != Barrier)
                            {
                                swapColor(&map[j][k], &map[j][k - 1]);
                            }
                        }
                    }
                }
                updateMap();
                Sleep(speed);
            }
            break;

        case Right:
            // 右方向への移動
            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 7; j++)
                {
                    for (int k = i; k >= 0; k--)
                    {
                        if (map[j][k + 1].colorEnum == EMPTY)
                        {
                            if (map[j][k].colorEnum != map[j][k + 1].colorEnum && map[j][k].colorEnum != Barrier && map[j][k + 1].colorEnum != Barrier)
                            {
                                swapColor(&map[j][k], &map[j][k + 1]);
                            }
                        }
                    }
                }
                updateMap();
                Sleep(speed);
            }
    }
    checkBarrier(direction); // 移動後にバリアチェック
}

void swapColor(Block* block_1, Block* block_2) 
{
    int temp = block_2->colorEnum;
    block_2->colorEnum = block_1->colorEnum;
    block_1->colorEnum = temp;
}

void printToBuffer(char* drawBuffer, int* offset, Block* block, int BGColorEnum, int textColorEnum, const char* shape)
{
        *offset += sprintf(drawBuffer + *offset, "\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm%s　%s\x1b[0m", block->position_x, block->position_y + 1, colors[BGColorEnum].R, colors[BGColorEnum].G, colors[BGColorEnum].B, colors[textColorEnum].R, colors[textColorEnum].G, colors[textColorEnum].B, shape, shape);
        *offset += sprintf(drawBuffer + *offset, "\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm　　　\x1b[0m", block->position_x + 1, block->position_y + 1, colors[BGColorEnum].R, colors[BGColorEnum].G, colors[BGColorEnum].B, colors[textColorEnum].R, colors[textColorEnum].G, colors[textColorEnum].B);
        *offset += sprintf(drawBuffer + *offset, "\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm%s　%s\x1b[0m", block->position_x + 2, block->position_y + 1, colors[BGColorEnum].R, colors[BGColorEnum].G, colors[BGColorEnum].B, colors[textColorEnum].R, colors[textColorEnum].G, colors[textColorEnum].B, shape, shape);

}

void barrierHandle(Block* barrier)
{
    if (barrier->barrierLevel >= 4)
    {
        barrier->colorEnum = EMPTY;
        barrier->barrierLevel = 0;
        updateMap();
    }
    else
    {
        barrier->barrierLevel++;
        updateMap();
    }
}

void printBarrierToBuffer(char* drawBuffer, int* offset, Block* block, int BGColorEnum, int textColorEnum, const char* shape, int num)
{
    const char* fullWidthDigits[] = { "０", "１", "２", "３", "４", "５", "６", "７", "８", "９" };
    char result[100] = "";
    char numStr[50];
    sprintf(numStr, "%d", num);

    for (int i = 0; i < strlen(numStr); i++) {
        strcat(result, fullWidthDigits[numStr[i] - '0']);
    }

    *offset += sprintf(drawBuffer + *offset, "\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm%s　%s\x1b[0m", block->position_x, block->position_y + 1, colors[BGColorEnum].R, colors[BGColorEnum].G, colors[BGColorEnum].B, colors[textColorEnum].R, colors[textColorEnum].G, colors[textColorEnum].B, shape, shape);
    *offset += sprintf(drawBuffer + *offset, "\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm　%s　\x1b[0m", block->position_x + 1, block->position_y + 1, colors[BGColorEnum].R, colors[BGColorEnum].G, colors[BGColorEnum].B, 143, 127, 219, result);
    *offset += sprintf(drawBuffer + *offset, "\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm%s　%s\x1b[0m", block->position_x + 2, block->position_y + 1, colors[BGColorEnum].R, colors[BGColorEnum].G, colors[BGColorEnum].B, colors[textColorEnum].R, colors[textColorEnum].G, colors[textColorEnum].B, shape, shape);
}


void checkBarrier(Direction direction)
{
    switch (direction)
    {

    case Up:
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                // バリアの下に通常ブロックがある場合
                if (map[j][i].colorEnum == Barrier && map[j + 1][i].colorEnum != EMPTY && map[j + 1][i].colorEnum != Barrier)
                {
                    BarrierBlockAnimation(&map[j + 1][i]); // アニメーション実行
                    Sleep(100);
                    map[j + 1][i].colorEnum = EMPTY;
                    barrierHandle(&map[j][i]); // バリアを破壊カウント処理
                }
            }
        }
        break;
    case Down:
        for (int i = 0; i < 7; i++)
        {
            for (int j = 6; j > 0; j--)
            {
                if (map[j][i].colorEnum == Barrier && map[j - 1][i].colorEnum != EMPTY && map[j - 1][i].colorEnum != Barrier)
                {
                    BarrierBlockAnimation(&map[j - 1][i]);
                    Sleep(100);
                    map[j - 1][i].colorEnum = EMPTY;
                    barrierHandle(&map[j][i]);
                }
            }
        }
        break;
    case Left:
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (map[i][j].colorEnum == Barrier && map[i][j + 1].colorEnum != EMPTY && map[i][j + 1].colorEnum != Barrier)
                {
                    BarrierBlockAnimation(&map[i][j + 1]);
                    Sleep(100);
                    map[i][j + 1].colorEnum = EMPTY;
                    barrierHandle(&map[i][j]);
                }
            }
        }
        break;
    case Right:
        for (int i = 0; i < 7; i++)
        {
            for (int j = 6; j > 0; j--)
            {
                if (map[i][j].colorEnum == Barrier && map[i][j - 1].colorEnum != EMPTY && map[i][j - 1].colorEnum != Barrier)
                {
                    BarrierBlockAnimation(&map[i][j - 1]);
                    Sleep(100);
                    map[i][j - 1].colorEnum = EMPTY;
                    barrierHandle(&map[i][j]);
                }

            }
        }
        break;
    }
        
}