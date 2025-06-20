#ifndef TURNSUI_H
#define TURNSUI_H

typedef struct TurnsUI TurnsUI;

struct TurnsUI {
    int position_x;
    int position_y;
    int colorEnum;
    const char* shape;
};


extern TurnsUI turnsUI[10];

void InitTurnsUI(int position_x, int position_y, int turnsCount);

#endif
