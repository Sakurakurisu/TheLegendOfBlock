#ifndef PLAYER_H
#define PLAYER_H




extern int redBlockCleanCount;
extern int greenBlockCleanCount;
extern int blueBlockCleanCount;

extern int hp_player;
extern int hpMax_player;
extern int sp_player;
extern int spMax_player;
extern int atk_player;
extern int atkMax_player;
extern int remainingTurns;

void initPlayer();

void drawPlayer();

#endif

