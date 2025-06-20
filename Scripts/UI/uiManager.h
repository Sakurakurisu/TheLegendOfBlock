#ifndef UIMANAGER_H
#define UIMANAGER_H

void drawUI(int position_x, int position_y, ColorEnum bgColor, ColorEnum textColor, const char* format, ...);

void printFullWidthNumber(int score, int position_x, int position_y);

void printBlocksCountUI(int redBlockCount, int blueBlockCount, int greenBlockCount);

void printMapFrame();


void updatePlayerInfo();

void printPlayerInfo();

void printDevilInfo();

void printDevilDamage();

void updateDevilInfo();

void updateDevilLevel();

void printTurnsInfo();

void printMapUI();

void printBGColor();

void printPlayerDamage(int damage);

int getPlayerDamage();


#endif
