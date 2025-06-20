
#define _CRT_SECURE_NO_WARNINGS
#include "block.h"
#include <stdio.h>
#include <locale.h>
#include <wchar.h>

#define CONIOEX
#include "conioex.h"
#include "player.h"
#include "devil.h"
#include "turnsUI.h"
#include "scence.h"
#include "drawImageCSV.h"
#include "animation.h"


void drawUI(int position_x, int position_y, ColorEnum bgColor, ColorEnum textColor, const char* format, ...) 
{
	char buffer[1024];
	va_list args;

	va_start(args, format);
	vsnprintf(buffer, sizeof(buffer), format, args);
	va_end(args);

	printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm%s\x1b[0m",
		position_x, position_y,
		colors[bgColor].R, colors[bgColor].G, colors[bgColor].B,
		colors[textColor].R, colors[textColor].G, colors[textColor].B,
		buffer);
}


void printMapFrame()
{
	drawUI(1,18, BGBlue,White,"■■■■■■■■■■■■■■■■■■■■■■■");
	drawUI(23, 18, BGBlue, White, "■■■■■■■■■■■■■■■■■■■■■■■");
	for (int k = 2; k < 24; k++)
	{
		drawUI(k, 18, BGBlue, White, "■");
		drawUI(k, 62, BGBlue, White, "■");
	}

}


void printFullWidthNumber(int num, int position_x, int position_y) 
{
	const char* fullWidthDigits[] = { "０", "１", "２", "３", "４", "５", "６", "７", "８", "９" };
	char result[100] = "";
	char numStr[50];      
	sprintf(numStr, "%d", num); 

	for (int i = 0; i < strlen(numStr); i++) {
		strcat(result, fullWidthDigits[numStr[i] - '0']);
	}
	gotoxy(position_y, position_x);
	printf("\x1b[38;5;233m%s", result);
}


void printBlocksCountUI(int redBlockCleanCount, int greenBlockCleanCount, int blueBlockCleanCount)
{   
	if(redBlockCleanCount != 0)
		drawUI(9, 10, PlayerUI, Red, "+%2d", redBlockCleanCount);
	if (greenBlockCleanCount != 0)
		drawUI(11, 10, PlayerUI, Green, "+%2d", greenBlockCleanCount);
	if (blueBlockCleanCount != 0)
		printf("\x1b[13;10H\x1b[48;2;%d;%d;%dm\x1b[38;2;41;140;238m+%2d\x1b[0m", colors[PlayerUI].R, colors[PlayerUI].G, colors[PlayerUI].B,blueBlockCleanCount);
}

void updatePlayerInfo()
{

	drawUI(9, 7, PlayerUI, White, "%d", hp_player);

	drawUI(11, 7, PlayerUI, White, "%d", sp_player);

	drawUI(13, 7, PlayerUI, White, "%d", atk_player);


	if (redBlockCleanCount != 0)
	{
		for (int i = redBlockCleanCount; i > 0; i--)
		{
			if (hp_player < hpMax_player)
			{
				hp_player++;
				drawUI(9, 7, PlayerUI, White, "%d", hp_player);
			}

			redBlockCleanCount--;
			drawUI(9, 10, PlayerUI, Red, "+%2d", redBlockCleanCount);
			Sleep(25);
		}
		drawUI(9, 10, PlayerUI, PlayerUI, " 　");
	}

	
	if (greenBlockCleanCount != 0)
	{
		for (int j = greenBlockCleanCount; j >0; j--)
		{
			if (sp_player < spMax_player)
			{
				sp_player++;
				drawUI(11, 7, PlayerUI, White, "%d", sp_player);
			}

			greenBlockCleanCount--;
			drawUI(11, 10, PlayerUI, Green, "+%2d", greenBlockCleanCount);
			Sleep(25);
		}
		drawUI(11, 10, PlayerUI, PlayerUI, " 　");
	}

	if (blueBlockCleanCount != 0)
	{
		for (int k = blueBlockCleanCount; k > 0; k--)
		{
			if (atk_player < atkMax_player)
			{
				atk_player++;
				drawUI(13, 7, PlayerUI, White, "%d", atk_player);
			}

			blueBlockCleanCount--;
			printf("\x1b[13;10H\x1b[48;2;%d;%d;%dm\x1b[38;2;41;140;238m+%2d\x1b[0m", colors[PlayerUI].R, colors[PlayerUI].G, colors[PlayerUI].B, blueBlockCleanCount);
			Sleep(25);
		}
		drawUI(13, 10, PlayerUI, PlayerUI, " 　");
	}
}

void printPlayerInfo() 
{	
	drawUI(9, 1, PlayerUI, PlayerUI, "             ");
	drawUI(9, 2, Red, White, "HP ");
	drawUI(9, 14, PlayerUI, White, "/%d", hpMax_player);
	
	drawUI(11, 1, PlayerUI, PlayerUI, "              ");
	drawUI(11, 2, Green, White, "SP ");
	drawUI(11, 14, PlayerUI, White, "/%d", spMax_player);

	drawUI(13, 1, PlayerUI, PlayerUI, "              ");
	drawUI(13, 2, Blue, White, "ATK");
	drawUI(13, 14, PlayerUI, White, "/%d", atkMax_player);
	updatePlayerInfo();
}

void printDevilDamage()
{
	if (atk_player != 0)
		drawUI(17,74, DevilUI, DevilHP, "-%2d", atk_player);

}

void printDevilInfo()
{
	drawUI(17, 65, DevilUI, DevilUI, "                ");
	drawUI(17,65, PlayerUI,White," Lv%d|", level_devil);
	drawUI(18, 72, BGBlue, Barrier,"■");
	drawUI(17, 77, DevilHP, White, " HP");
	drawUI(17, 71, DevilUI, White, "%2d", hp_devil);

}

void updateDevilLevel()
{
	if (level_devil == 2)
	{
		drawUI(17, 65, PlayerUI, White, " Lv%d|", level_devil);
		drawUI(18, 72, BGBlue, Barrier, "■■");

		LoadCSV("devil_2.csv", devil_image, 11, 15);
		DrawImage(devil_image, 11, 15, 5, 65);
	}
	else if (level_devil == 3)
	{
		drawUI(17, 65, PlayerUI, White, " Lv%d|", level_devil);
		drawUI(18, 72, BGBlue, Barrier, "■■■");
		LoadCSV("devil_3.csv", devil_image, 14, 16);
		DrawImage(devil_image, 14, 16, 2, 65);
	}

}

void updateDevilInfo()
{
	for (int k = atk_player; k > 0; k--)
	{
			if(hp_devil != 0)
				hp_devil--;
			drawUI(17,71,DevilUI,White,"%2d", hp_devil);
		Sleep(50);
	}
	drawUI(17,74,DevilUI,DevilUI," 　");

	if (hp_devil <= 70 && hp_devil > 30)
	{
		level_devil = 2;
		drawUI(17, 65, PlayerUI, White, " Lv%d|", level_devil);
	}
	if (hp_devil <= 30)
	{
		level_devil = 3;
		drawUI(17, 65, PlayerUI, White, " Lv%d|", level_devil);
	}
	if (hp_devil <= 0)
	{
		Sleep(1000);
		
	}
	updateDevilLevel();
}



void printTurnsInfo()
{
	drawUI(24, 29, PlayerUI, White,"＜-");
	
	InitTurnsUI(24, 33, 10);
	playInitTurnsUI();

}

void printMapUI()
{
	drawUI(1,2,BGBlue,White,"ーーーーーーーー");
	drawUI(1, 64, BGBlue, White, "ーーーーーーーー");
	drawUI(25, 2, BGBlue, White, "ーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーー");
	drawUI(25, 80, BGBlue, White, " ");
	drawUI(25, 1, BGBlue, White, " ");

	for (int i = 0; i < 2; i++)
	{
		drawUI(3+i, 2, BGWhite, BGWhite, " ");
	}
	for (int i = 0; i < 9; i++)
	{
		drawUI(6 + i, 2, BGWhite, BGWhite, " ");
	}
	drawUI(14, 3, BGWhite, White, "     ");

	for (int i = 0; i < 17; i++)
	{
		drawUI(5 + i, 79, BGGray, BGGray, " ");
	}
	drawUI(23, 79, BGGray, BGGray, " ");

	drawUI(16, 69, BGGray, BGGray, "          ");


	printf("\x1b[7;4H\x1b[4m\x1b[48;2;120;219;217m\x1b[38;2;255;255;255mブロックマン\x1b[0m");
	printf("\x1b[20;70H\x1b[4m\x1b[48;2;120;219;217m\x1b[38;2;255;255;255mマオウ\x1b[0m");
}

void printBGColor()
{
	for (int i = 0;i<= 25;i++)
	{
		for (int j = 0; j <= 80; j++)
		{
			drawUI(i,j,BGBlue, BGBlue, " ");
		}
	}
}


void printPlayerDamage(int damage)
{

	if (damage != 0)
	{
		drawUI(9, 10, DevilHP, White, "-%2d", damage);
		for (int i = damage; i > 0; i--)
		{
			if (hp_player > 0)
			{
				hp_player--;
				drawUI(9, 6, PlayerUI, White, "%3d", hp_player);
				Sleep(50);
			}
			
		}

		drawUI(9, 10, PlayerUI, PlayerUI, "   ");
	}
	
}

int getPlayerDamage()
{
	int index = 0;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (map[i][j].colorEnum == Barrier)
			{
				if (index < 50)
				{
					index++;
				}
			}
		}
	}

	int damage = index * 20;

	return damage;
}


