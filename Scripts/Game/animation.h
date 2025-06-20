#ifndef ANIMATION_H
#define ANIMATION_H
#include "block.h"
#include "map.h"
#include <windows.h>
#include <stdlib.h>
#include <time.h>  


void playClearAnimation(Block* cleanBlocks[], int length);

void playCreateAnimation(Block* cleanBlocks[], int length);

void playBlockBarrierAnimation(Block* barrier);

void playTurnsUI();

void playInitTurnsUI();

void playMapFrameAnimation(Direction direction);

void drawAnimationLine(int position_x, int position_y, int bgColorEnum, int colorEnum, const char* image);

void drawAnimationUnit(Block* block, int bgColorEnum, int colorEnum, const char* image);

void playTurnOverAnimation();


void AnimateWindowPosition(int frequency, int count);

void ShingBarrier();

void playSpActionAnimation(); 

void playSpCreateBlockAnimation(Block* block);


void playBarrierClearAnimation(Block* barrier);

void BarrierBlockAnimation(Block* block);

#endif