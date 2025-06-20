#ifndef BLOCK_H
#define BLOCK_H


#include "color.h" 
typedef struct Block Block;

struct Block {
    int position_x;
    int position_y;
    int colorEnum;
    int barrierLevel;
    
};

extern const char* shapeList[];

extern int barrierColor[];

void swapBuffers();
void displayScreenBuffer();

#endif
