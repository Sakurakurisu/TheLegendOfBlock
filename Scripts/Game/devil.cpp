#include "block.h"
#include <stdlib.h>
#include "map.h"
#include "animation.h"
#include "drawImageCSV.h"







int hp_devil;
int hpMax_devil; 
int level_devil;

Pixel devil_image[13][80];

void drawDevil()
{

    LoadCSV("devil_1.csv", devil_image, 9, 16);
    DrawImage(devil_image, 9, 16, 6, 65);
     
}

void initDevil()
{
	hp_devil = 99;
	hpMax_devil = 99;
    level_devil = 1;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 17; ++j) {
            devil_image[i][j] = {};
        }
    }
    drawDevil();
}




void createBlockBarrier(Block map[7][7])
{
    int count = level_devil;
    int i = rand() % 7;
    int j = rand() % 7;

    while (count != 0)
    {
        int i = rand() % 7;
        int j = rand() % 7;

        if (map[i][j].colorEnum != Barrier)
        {
            playBlockBarrierAnimation(&map[i][j]);
            map[i][j].colorEnum = Barrier;
            count--;
        }
    }
    //playCreateAnimation(randomBlocks, index);
    updateMap();
}