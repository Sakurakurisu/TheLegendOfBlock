#include "player.h"
#include "drawImageCSV.h"
#include <stdio.h>





int redBlockCleanCount;
int greenBlockCleanCount;
int blueBlockCleanCount;



int hp_player;
int hpMax_player;
int sp_player;
int spMax_player;
int atk_player;
int atkMax_player;

int remainingTurns;

Pixel player_image[8][80];

void initPlayer() 
{
	redBlockCleanCount = 0;
	greenBlockCleanCount = 0;
	blueBlockCleanCount = 0;

	hp_player = 99;
	hpMax_player = 99;
	sp_player = 0;
	spMax_player = 10;
	atk_player = 0;
	atkMax_player = 25;
	remainingTurns = 10;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 17; ++j) {
			player_image[i][j] = {};
		}
	}
	drawPlayer();
}

void drawPlayer()
{

	LoadCSV("player.csv", player_image, 8, 16);
	DrawImage(player_image,8 ,16,14,2);
	printf("\x1b[15;4H\x1b[48;2;255;102;153m\x1b[38;2;255;255;255m×\x1b[0m");
	printf("\x1b[15;9H\x1b[48;2;255;217;102m\x1b[38;2;255;255;255m×\x1b[0m"); 
	printf("\x1b[18;6H\x1b[48;2;255;139;59m\x1b[38;2;255;255;255m ＼\x1b[0m");
	printf("\x1b[19;6H\x1b[48;2;255;139;59m\x1b[38;2;255;255;255m ●\x1b[0m");
}

