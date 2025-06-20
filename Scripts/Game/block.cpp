#include "block.h"
#include <windows.h>
#include <stdio.h>
#include <time.h>
#include "color.h"

#define CONIOEX
#include "conioex.h"

#define BUF_SIZE 1024*1024

char drawBuffer[BUF_SIZE];
char displayBuffer[BUF_SIZE];

const char* shapeList[] =
{ 
    "　", 
    "□",
    "＃",
    "※",
    "◆",

};  

int barrierColor[] =
{
    238,
    240,
    248
};

void swapBuffers()
{
    memcpy(displayBuffer, drawBuffer, BUF_SIZE);
    memset(drawBuffer, ' ', BUF_SIZE);
}

void displayScreenBuffer()
{
    swapBuffers();
    printf("%s", displayBuffer);
    printf("\x1b[0m");
}