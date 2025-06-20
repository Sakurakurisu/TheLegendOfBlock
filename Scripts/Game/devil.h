#include "drawImageCSV.h"
#ifndef DEVIL_H
#define DEVIL_H




extern int hp_devil;
extern int hpMax_devil;
extern int level_devil;

extern Pixel devil_image[13][80];

void drawDevil();
void initDevil();


void createBlockBarrier(Block map[7][7]);

#endif
