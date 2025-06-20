#include <stdio.h>
#include "block.h"
#include "color.h"
#include "map.h"
#include <stdlib.h>
#include <time.h>
#include "blockRandom.h"
#include "animation.h"

void initMap(Block map[7][7])
{
    // マップの初期化処理
    for (int i = 2; i < 25; i += 3)
    {
        for (int j = 19; j < 80; j += 6)
        {
            map[(i-1) / 3][(j-19) / 6] = { i, j, EMPTY, 0 };
        }
    }

    rollBlock(map, 10);
}

void rollBlock(Block map[7][7], int count)
{
    srand(time(NULL));
    Block* randomBlocks[50] = {};
    int index = 0;

    // ランダムにブロックを配置する処理（重複しないように注意）
    while (count != 0)
    {
        int i = rand() % 7;
        int j = rand() % 7;

        // すでに色がついているブロックはスキップ
        if (map[i][j].colorEnum == EMPTY)
        {
            map[i][j].colorEnum = rollColor();
            randomBlocks[index] = &map[i][j];
            index++;
            count--;
        }
    }
    playCreateAnimation(randomBlocks, index);
    updateMap();
}

ColorEnum rollColor()
{
    // ランダムで色を決定する処理
    int colorCode = rand() % 3;
    switch (colorCode)
    {
    case 0:
        return Red;
    case 1:
        return Green;
    case 2:
        return Blue;
    default:
        return EMPTY;
    }
}