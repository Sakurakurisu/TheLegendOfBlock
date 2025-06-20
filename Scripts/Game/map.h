#include "block.h"
#ifndef Map_H
#define Map_H


enum Direction 
{
    Up,
    Down,
    Left,
    Right,
    None
};

extern Block map[7][7];

void updateMap();

void move(Direction direction);

void bounceConsoleWindow(Direction direction, int value);

void swapColor(Block* block_1, Block* block_2);

void printToBuffer(char* drawBuffer, int* offset, Block* block, int BGColorEnum, int textColorEnum, const char* shape);

void barrierHandle(Block* barrier);

void printBarrierToBuffer(char* drawBuffer, int* offset, Block* block, int BGColorEnum, int textColorEnum, const char* shape, int num);

void checkBarrier(Direction direction);


#endif
