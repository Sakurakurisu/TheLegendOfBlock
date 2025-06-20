#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "block.h"
#include "color.h"
#include "map.h"
#include <windows.h>
#include "animation.h"
#include "uiManager.h"
#include "turnsUI.h"
#include "player.h"
#include "audioManager.h"

void playClearAnimation(Block* cleanBlocks[], int length)
{
	playsound(cleanAudio, 0);
	Sleep(34);
	for (int i = 0; i < length; i++)
	{
		drawAnimationUnit(cleanBlocks[i], cleanBlocks[i]->colorEnum, cleanBlocks[i]->colorEnum, "■■■");
	}
	Sleep(51);
	for (int i = 0; i < length; i++)
	{
		drawAnimationUnit(cleanBlocks[i], cleanBlocks[i]->colorEnum+1, cleanBlocks[i]->colorEnum, "■■■");
	}
	Sleep(51);
	for (int i = 0; i < length; i++)
	{
		drawAnimationUnit(cleanBlocks[i], cleanBlocks[i]->colorEnum, cleanBlocks[i]->colorEnum, "■■■");
	}
	Sleep(51);
	for (int i = 0; i < length; i++)
	{
		drawAnimationUnit(cleanBlocks[i], cleanBlocks[i]->colorEnum+1, cleanBlocks[i]->colorEnum, "■■■");
	}

	Sleep(51);
	for (int i = 0; i < length; i++)
	{
		drawAnimationUnit(cleanBlocks[i], cleanBlocks[i]->colorEnum, cleanBlocks[i]->colorEnum, "　　　");
	}
	Sleep(85);
	for (int i = 0; i < length; i++)
	{
		drawAnimationUnit(cleanBlocks[i], EMPTY, cleanBlocks[i]->colorEnum, "■■■");
	}
	Sleep(85);
	for (int i = 0; i < length; i++)
	{
		drawAnimationUnit(cleanBlocks[i], EMPTY, cleanBlocks[i]->colorEnum, "●●●");
	}
	Sleep(34);
	for (int i = 0; i < length; i++)
	{
		drawAnimationUnit(cleanBlocks[i], EMPTY, cleanBlocks[i]->colorEnum, "◎◎◎");
	}
	Sleep(17);
	for (int i = 0; i < length; i++)
	{
		drawAnimationUnit(cleanBlocks[i], EMPTY, cleanBlocks[i]->colorEnum, "○○○");
	}
	Sleep(17);
	for (int i = 0; i < length; i++)
	{
		drawAnimationUnit(cleanBlocks[i], EMPTY, cleanBlocks[i]->colorEnum, "☆☆☆");
	}
	Sleep(17);
	for (int i = 0; i < length; i++)
	{
		drawAnimationUnit(cleanBlocks[i], EMPTY, cleanBlocks[i]->colorEnum, "×××");
	}
	Sleep(34);
	for (int i = 0; i < length; i++)
	{
		drawAnimationUnit(cleanBlocks[i], EMPTY, cleanBlocks[i]->colorEnum, "・・・");
	}
	Sleep(34);

	for (int i = 0; i < length; i++)
	{
		drawAnimationUnit(cleanBlocks[i], EMPTY, cleanBlocks[i]->colorEnum, "　　　");
	}
}

void playCreateAnimation(Block* randomBlocks[], int length)
{
	
	for (int i = 0; i < length; i++)
	{
		drawAnimationUnit(randomBlocks[i], EMPTY, randomBlocks[i]->colorEnum, "・・・");
	}
	Sleep(34);

	for (int i = 0; i < length; i++)
	{
		drawAnimationUnit(randomBlocks[i], EMPTY, randomBlocks[i]->colorEnum, "○○○");
	}
	Sleep(34);

	for (int i = 0; i < length; i++)
	{
		drawAnimationUnit(randomBlocks[i], EMPTY, randomBlocks[i]->colorEnum, "◎◎◎");
	}
	Sleep(34);

	for (int i = 0; i < length; i++)
	{
		drawAnimationUnit(randomBlocks[i], EMPTY, randomBlocks[i]->colorEnum, "●●●");
	}
	Sleep(34);

	for (int i = 0; i < length; i++)
	{
		drawAnimationUnit(randomBlocks[i], EMPTY, randomBlocks[i]->colorEnum, "■■■");
	}
	Sleep(34);
}

void playBlockBarrierAnimation(Block* barrier)
{
	playsound(createBlockAudio, 0);
	drawAnimationUnit(barrier, barrier->colorEnum, barrier->colorEnum, "　　　");

	drawAnimationLine(barrier->position_x, barrier->position_y, barrier->colorEnum, Barrier, "・　・");
	drawAnimationLine(barrier->position_x+1, barrier->position_y, barrier->colorEnum, Barrier, "　・　");
	drawAnimationLine(barrier->position_x+2, barrier->position_y, barrier->colorEnum, Barrier, "・　・");
	Sleep(34);

	drawAnimationLine(barrier->position_x, barrier->position_y, barrier->colorEnum, Barrier, "○　○");
	drawAnimationLine(barrier->position_x + 1, barrier->position_y, barrier->colorEnum, Barrier, "　○　");
	drawAnimationLine(barrier->position_x + 2, barrier->position_y, barrier->colorEnum, Barrier, "○　○");
	Sleep(34);

	drawAnimationLine(barrier->position_x, barrier->position_y, barrier->colorEnum, Barrier, "◎・◎");
	drawAnimationLine(barrier->position_x + 1, barrier->position_y, barrier->colorEnum, Barrier, "・◎・");
	drawAnimationLine(barrier->position_x + 2, barrier->position_y, barrier->colorEnum, Barrier, "◎・◎");
	Sleep(34);

	drawAnimationLine(barrier->position_x, barrier->position_y, barrier->colorEnum, Barrier, "●○●");
	drawAnimationLine(barrier->position_x + 1, barrier->position_y, barrier->colorEnum, Barrier, "○●○");
	drawAnimationLine(barrier->position_x + 2, barrier->position_y, barrier->colorEnum, Barrier, "●○●");
	Sleep(34);

	drawAnimationLine(barrier->position_x, barrier->position_y, barrier->colorEnum, Barrier, "■◎■");
	drawAnimationLine(barrier->position_x + 1, barrier->position_y, barrier->colorEnum, Barrier, "◎■◎");
	drawAnimationLine(barrier->position_x + 2, barrier->position_y, barrier->colorEnum, Barrier, "■◎■");
	Sleep(34);

	drawAnimationLine(barrier->position_x, barrier->position_y, Barrier, Barrier, "　●　");
	drawAnimationLine(barrier->position_x + 1, barrier->position_y, Barrier, Barrier, "●　●");
	drawAnimationLine(barrier->position_x + 2, barrier->position_y, Barrier, Barrier, "　●　");
	Sleep(34);

	drawAnimationLine(barrier->position_x, barrier->position_y, Barrier, Barrier, "　■　");
	drawAnimationLine(barrier->position_x + 1, barrier->position_y, Barrier, Barrier, "■　■");
	drawAnimationLine(barrier->position_x + 2, barrier->position_y, Barrier, Barrier, "　■　");
	Sleep(34);

	drawAnimationUnit(barrier, Barrier, Barrier, "　　　");
}

void playTurnsUI()
{
	printf("\x1b[%d;%dH\x1b[48;2;120;219;217m\x1b[38;2;%d;%d;%dm%s\x1b[0m", turnsUI[remainingTurns].position_x, turnsUI[remainingTurns].position_y, gradientColorList[turnsUI[remainingTurns].colorEnum].R, gradientColorList[turnsUI[remainingTurns].colorEnum].G, gradientColorList[turnsUI[remainingTurns].colorEnum].B, "◎");

	Sleep(34);
	printf("\x1b[%d;%dH\x1b[48;2;120;219;217m\x1b[38;2;%d;%d;%dm%s\x1b[0m", turnsUI[remainingTurns].position_x, turnsUI[remainingTurns].position_y, gradientColorList[turnsUI[remainingTurns].colorEnum].R, gradientColorList[turnsUI[remainingTurns].colorEnum].G, gradientColorList[turnsUI[remainingTurns].colorEnum].B, "・");

	Sleep(34);
	printf("\x1b[%d;%dH\x1b[48;2;120;219;217m\x1b[38;2;%d;%d;%dm%s\x1b[0m", turnsUI[remainingTurns].position_x, turnsUI[remainingTurns].position_y, colors[White].R, colors[White].G, colors[White].B, "○");

}

void playInitTurnsUI()
{
	for (int i = 0; i < remainingTurns; i++)
	{
		printf("\x1b[%d;%dH\x1b[48;2;120;219;217m\x1b[38;2;%d;%d;%dm%s\x1b[0m", turnsUI[i].position_x, turnsUI[i].position_y, gradientColorList[turnsUI[i].colorEnum].R, gradientColorList[turnsUI[i].colorEnum].G, gradientColorList[turnsUI[i].colorEnum].B, "・");
		Sleep(10);
		printf("\x1b[%d;%dH\x1b[48;2;120;219;217m\x1b[38;2;%d;%d;%dm%s\x1b[0m", turnsUI[i].position_x, turnsUI[i].position_y, gradientColorList[turnsUI[i].colorEnum].R, gradientColorList[turnsUI[i].colorEnum].G, gradientColorList[turnsUI[i].colorEnum].B, "×");

		Sleep(10);
		printf("\x1b[%d;%dH\x1b[48;2;120;219;217m\x1b[38;2;%d;%d;%dm%s\x1b[0m", turnsUI[i].position_x, turnsUI[i].position_y, gradientColorList[turnsUI[i].colorEnum].R, gradientColorList[turnsUI[i].colorEnum].G, gradientColorList[turnsUI[i].colorEnum].B, "○");

		Sleep(10);
		printf("\x1b[%d;%dH\x1b[48;2;120;219;217m\x1b[38;2;%d;%d;%dm%s\x1b[0m", turnsUI[i].position_x, turnsUI[i].position_y, gradientColorList[turnsUI[i].colorEnum].R, gradientColorList[turnsUI[i].colorEnum].G, gradientColorList[turnsUI[i].colorEnum].B, "◎");

		Sleep(10);
		printf("\x1b[%d;%dH\x1b[48;2;120;219;217m\x1b[38;2;%d;%d;%dm%s\x1b[0m", turnsUI[i].position_x, turnsUI[i].position_y, gradientColorList[turnsUI[i].colorEnum].R, gradientColorList[turnsUI[i].colorEnum].G, gradientColorList[turnsUI[i].colorEnum].B, "●");

		Sleep(10);
		
	}
}

void playMapFrameAnimation(Direction direction)
{
	switch (direction)
	{
		case Up:
			drawUI(1, 18, PlayerMain, White, "　　　　　　　　　　　　　　　　　　　　　　　");
			break;
		case Down:
			drawUI(23, 18, PlayerMain, White, "　　　　　　　　　　　　　　　　　　　　　　　");
			break;
		case Left:
			for (int k = 1; k < 24; k++)
			{
				drawUI(k, 18, PlayerMain, White, "　");
			}
			break;
		case Right:
			for (int k = 1; k < 24; k++)
			{
				drawUI(k, 62, PlayerMain, White, "　");
			}
			break;
	}
}

void drawAnimationUnit(Block* block, int bgColorEnum, int colorEnum, const char* image)
{
	for (int k = 0; k < 3; k++)
	{
		drawAnimationLine(block->position_x + k, block->position_y, bgColorEnum, colorEnum, image);
	}	
}

void drawAnimationLine(int position_x,int position_y,int bgColorEnum, int colorEnum, const char* image)
{
	printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm　　　", position_x, position_y + 1, colors[bgColorEnum].R, colors[bgColorEnum].G, colors[bgColorEnum].B);
	printf("\x1b[%d;%dH\x1b[38;2;%d;%d;%dm%s", position_x, position_y + 1, colors[colorEnum].R, colors[colorEnum].G, colors[colorEnum].B, image);
	printf("\x1b[0m");
}


void playTurnOverAnimation()
{
	
	drawUI(1,18,PlayerYellow, White, "□□□□□□□□□□□□□□□□□□□□□□□");
	drawUI(23, 18, PlayerYellow, White, "□□□□□□□□□□□□□□□□□□□□□□□");
	for (int k = 1; k < 24; k++)
	{
		drawUI(k, 18, PlayerYellow, White, "□");
	}
	for (int k = 1; k < 24; k++)
	{
		drawUI(k, 62, PlayerYellow, White, "□");	}
}

void AnimateWindowPosition(int frequency, int count)
{
	srand((unsigned int)time(NULL));
	RECT windowRect;
	static POINT currentPosition;
	static bool currentPositionInitialized = false;
	HWND consoleWindow = GetConsoleWindow();
	int MOVE_DISTANCE = frequency;

	if (!currentPositionInitialized) {
		if (GetWindowRect(consoleWindow, &windowRect)) {
			currentPosition.x = windowRect.left;
			currentPosition.y = windowRect.top;
			currentPositionInitialized = true;
		}

	}
	for (int i = 0; i < count; i++)
	{
		int dx1 = (rand() % 3 - 1) * MOVE_DISTANCE;
		int dy1 = (rand() % 3 - 1) * MOVE_DISTANCE;
		SetWindowPos(consoleWindow, 0, currentPosition.x + dx1, currentPosition.y + dy1, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

		Sleep(16);
		int dx2 = (rand() % 3 - 1) * (MOVE_DISTANCE / 2);
		int dy2 = (rand() % 3 - 1) * (MOVE_DISTANCE / 2);
		SetWindowPos(consoleWindow, 0, currentPosition.x + dx2, currentPosition.y + dy2, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

		Sleep(16);
		SetWindowPos(consoleWindow, 0, currentPosition.x, currentPosition.y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	}


}

void ShingBarrier()
{
	
	Block* barrierList[50] = {};
	int index = 0;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (map[i][j].colorEnum == Barrier)
			{
				if (index < 50) 
				{
					barrierList[index] = &map[i][j];
					index++;
				}
			}
		}
	}

	if (index == 0) return;


	Sleep(100);
	for (int k = index - 1; k >= 0; k--)
	{
		const char* fullWidthDigits[] = { "０", "１", "２", "３", "４", "５", "６", "７", "８", "９" };
		char result[100] = "";
		char numStr[50];
		sprintf(numStr, "%d", 5 - barrierList[k]->barrierLevel);

		for (int i = 0; i < strlen(numStr); i++) {
			strcat(result, fullWidthDigits[numStr[i] - '0']);
		}
		printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm%s　%s\x1b[0m", barrierList[k]->position_x, barrierList[k]->position_y + 1, colors[BrightBarrier].R, colors[BrightBarrier].G, colors[BrightBarrier].B, colors[BarrierBlockText].R, colors[BarrierBlockText].G, colors[BarrierBlockText].B, shapeList[barrierList[k]->barrierLevel], shapeList[barrierList[k]->barrierLevel]);
		printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm　%s　\x1b[0m", barrierList[k]->position_x + 1, barrierList[k]->position_y + 1, colors[BrightBarrier].R, colors[BrightBarrier].G, colors[BrightBarrier].B, 143, 127, 219, result);
		printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm%s　%s\x1b[0m", barrierList[k]->position_x + 2, barrierList[k]->position_y + 1, colors[BrightBarrier].R, colors[BrightBarrier].G, colors[BrightBarrier].B, colors[BarrierBlockText].R, colors[BarrierBlockText].G, colors[BarrierBlockText].B, shapeList[barrierList[k]->barrierLevel], shapeList[barrierList[k]->barrierLevel]);
	}
	Sleep(100);


	for (int k = index - 1; k >= 0; k--)
	{
		const char* fullWidthDigits[] = { "０", "１", "２", "３", "４", "５", "６", "７", "８", "９" };
		char result[100] = "";
		char numStr[50];
		sprintf(numStr, "%d", 5 - barrierList[k]->barrierLevel);

		for (int i = 0; i < strlen(numStr); i++) {
			strcat(result, fullWidthDigits[numStr[i] - '0']);
		}
		printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm%s　%s\x1b[0m", barrierList[k]->position_x, barrierList[k]->position_y + 1, colors[Barrier].R, colors[Barrier].G, colors[Barrier].B, colors[BarrierBlockText].R, colors[BarrierBlockText].G, colors[BarrierBlockText].B, shapeList[barrierList[k]->barrierLevel], shapeList[barrierList[k]->barrierLevel]);
		printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm　%s　\x1b[0m", barrierList[k]->position_x + 1, barrierList[k]->position_y + 1, colors[Barrier].R, colors[Barrier].G, colors[Barrier].B, 143, 127, 219, result);
		printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm%s　%s\x1b[0m", barrierList[k]->position_x + 2, barrierList[k]->position_y + 1, colors[Barrier].R, colors[Barrier].G, colors[Barrier].B, colors[BarrierBlockText].R, colors[BarrierBlockText].G, colors[BarrierBlockText].B, shapeList[barrierList[k]->barrierLevel], shapeList[barrierList[k]->barrierLevel]);
	}
	Sleep(100);


	for (int k = index - 1; k >= 0; k--)
	{
		const char* fullWidthDigits[] = { "０", "１", "２", "３", "４", "５", "６", "７", "８", "９" };
		char result[100] = "";
		char numStr[50];
		sprintf(numStr, "%d", 5 - barrierList[k]->barrierLevel);

		for (int i = 0; i < strlen(numStr); i++) {
			strcat(result, fullWidthDigits[numStr[i] - '0']);
		}
		printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm%s　%s\x1b[0m", barrierList[k]->position_x, barrierList[k]->position_y + 1, colors[BrightBarrier].R, colors[BrightBarrier].G, colors[BrightBarrier].B, colors[BarrierBlockText].R, colors[BarrierBlockText].G, colors[BarrierBlockText].B, shapeList[barrierList[k]->barrierLevel], shapeList[barrierList[k]->barrierLevel]);
		printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm　%s　\x1b[0m", barrierList[k]->position_x + 1, barrierList[k]->position_y + 1, colors[BrightBarrier].R, colors[BrightBarrier].G, colors[BrightBarrier].B, 143, 127, 219, result);
		printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm%s　%s\x1b[0m", barrierList[k]->position_x + 2, barrierList[k]->position_y + 1, colors[BrightBarrier].R, colors[BrightBarrier].G, colors[BrightBarrier].B, colors[BarrierBlockText].R, colors[BarrierBlockText].G, colors[BarrierBlockText].B, shapeList[barrierList[k]->barrierLevel], shapeList[barrierList[k]->barrierLevel]);
	}
	Sleep(100);

	for (int k = index - 1; k >= 0; k--)
	{
		const char* fullWidthDigits[] = { "０", "１", "２", "３", "４", "５", "６", "７", "８", "９" };
		char result[100] = "";
		char numStr[50];
		sprintf(numStr, "%d", 5 - barrierList[k]->barrierLevel);

		for (int i = 0; i < strlen(numStr); i++) {
			strcat(result, fullWidthDigits[numStr[i] - '0']);
		}
		printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm%s　%s\x1b[0m", barrierList[k]->position_x, barrierList[k]->position_y + 1, colors[Barrier].R, colors[Barrier].G, colors[Barrier].B, colors[BarrierBlockText].R, colors[BarrierBlockText].G, colors[BarrierBlockText].B, shapeList[barrierList[k]->barrierLevel], shapeList[barrierList[k]->barrierLevel]);
		printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm　%s　\x1b[0m", barrierList[k]->position_x + 1, barrierList[k]->position_y + 1, colors[Barrier].R, colors[Barrier].G, colors[Barrier].B, 143, 127, 219, result);
		printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm%s　%s\x1b[0m", barrierList[k]->position_x + 2, barrierList[k]->position_y + 1, colors[Barrier].R, colors[Barrier].G, colors[Barrier].B, colors[BarrierBlockText].R, colors[BarrierBlockText].G, colors[BarrierBlockText].B, shapeList[barrierList[k]->barrierLevel], shapeList[barrierList[k]->barrierLevel]);
	}
	Sleep(100);
	for (int k = index - 1; k >= 0; k--)
	{
		const char* fullWidthDigits[] = { "０", "１", "２", "３", "４", "５", "６", "７", "８", "９" };
		char result[100] = "";
		char numStr[50];
		sprintf(numStr, "%d", 5 - barrierList[k]->barrierLevel);

		for (int i = 0; i < strlen(numStr); i++) {
			strcat(result, fullWidthDigits[numStr[i] - '0']);
		}
		printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm%s　%s\x1b[0m", barrierList[k]->position_x, barrierList[k]->position_y + 1, colors[BrightBarrier].R, colors[BrightBarrier].G, colors[BrightBarrier].B, colors[BarrierBlockText].R, colors[BarrierBlockText].G, colors[BarrierBlockText].B, shapeList[barrierList[k]->barrierLevel], shapeList[barrierList[k]->barrierLevel]);
		printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm　%s　\x1b[0m", barrierList[k]->position_x + 1, barrierList[k]->position_y + 1, colors[BrightBarrier].R, colors[BrightBarrier].G, colors[BrightBarrier].B, 143, 127, 219, result);
		printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm%s　%s\x1b[0m", barrierList[k]->position_x + 2, barrierList[k]->position_y + 1, colors[BrightBarrier].R, colors[BrightBarrier].G, colors[BrightBarrier].B, colors[BarrierBlockText].R, colors[BarrierBlockText].G, colors[BarrierBlockText].B, shapeList[barrierList[k]->barrierLevel], shapeList[barrierList[k]->barrierLevel]);
	}
	Sleep(100);

	for (int k = index - 1; k >= 0; k--)
	{
		const char* fullWidthDigits[] = { "０", "１", "２", "３", "４", "５", "６", "７", "８", "９" };
		char result[100] = "";
		char numStr[50];
		sprintf(numStr, "%d", 5 - barrierList[k]->barrierLevel);

		for (int i = 0; i < strlen(numStr); i++) {
			strcat(result, fullWidthDigits[numStr[i] - '0']);
		}
		printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm%s　%s\x1b[0m", barrierList[k]->position_x, barrierList[k]->position_y + 1, colors[Barrier].R, colors[Barrier].G, colors[Barrier].B, colors[BarrierBlockText].R, colors[BarrierBlockText].G, colors[BarrierBlockText].B, shapeList[barrierList[k]->barrierLevel], shapeList[barrierList[k]->barrierLevel]);
		printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm　%s　\x1b[0m", barrierList[k]->position_x + 1, barrierList[k]->position_y + 1, colors[Barrier].R, colors[Barrier].G, colors[Barrier].B, 143, 127, 219, result);
		printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm%s　%s\x1b[0m", barrierList[k]->position_x + 2, barrierList[k]->position_y + 1, colors[Barrier].R, colors[Barrier].G, colors[Barrier].B, colors[BarrierBlockText].R, colors[BarrierBlockText].G, colors[BarrierBlockText].B, shapeList[barrierList[k]->barrierLevel], shapeList[barrierList[k]->barrierLevel]);
	}
	Sleep(100);
	for (int k = index - 1; k >= 0; k--)
	{
		const char* fullWidthDigits[] = { "０", "１", "２", "３", "４", "５", "６", "７", "８", "９" };
		char result[100] = "";
		char numStr[50];
		sprintf(numStr, "%d", 5 - barrierList[k]->barrierLevel);

		for (int i = 0; i < strlen(numStr); i++) {
			strcat(result, fullWidthDigits[numStr[i] - '0']);
		}
		printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm%s　%s\x1b[0m", barrierList[k]->position_x, barrierList[k]->position_y + 1, colors[BrightBarrier].R, colors[BrightBarrier].G, colors[BrightBarrier].B, colors[BarrierBlockText].R, colors[BarrierBlockText].G, colors[BarrierBlockText].B, shapeList[barrierList[k]->barrierLevel], shapeList[barrierList[k]->barrierLevel]);
		printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm　%s　\x1b[0m", barrierList[k]->position_x + 1, barrierList[k]->position_y + 1, colors[BrightBarrier].R, colors[BrightBarrier].G, colors[BrightBarrier].B, 143, 127, 219, result);
		printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm%s　%s\x1b[0m", barrierList[k]->position_x + 2, barrierList[k]->position_y + 1, colors[BrightBarrier].R, colors[BrightBarrier].G, colors[BrightBarrier].B, colors[BarrierBlockText].R, colors[BarrierBlockText].G, colors[BarrierBlockText].B, shapeList[barrierList[k]->barrierLevel], shapeList[barrierList[k]->barrierLevel]);
	}
	Sleep(100);

	for (int k = index - 1; k >= 0; k--)
	{
		const char* fullWidthDigits[] = { "０", "１", "２", "３", "４", "５", "６", "７", "８", "９" };
		char result[100] = "";
		char numStr[50];
		sprintf(numStr, "%d", 5 - barrierList[k]->barrierLevel);

		for (int i = 0; i < strlen(numStr); i++) {
			strcat(result, fullWidthDigits[numStr[i] - '0']);
		}
		printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm%s　%s\x1b[0m", barrierList[k]->position_x, barrierList[k]->position_y + 1, colors[Barrier].R, colors[Barrier].G, colors[Barrier].B, colors[BarrierBlockText].R, colors[BarrierBlockText].G, colors[BarrierBlockText].B, shapeList[barrierList[k]->barrierLevel], shapeList[barrierList[k]->barrierLevel]);
		printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm　%s　\x1b[0m", barrierList[k]->position_x + 1, barrierList[k]->position_y + 1, colors[Barrier].R, colors[Barrier].G, colors[Barrier].B, 143, 127, 219, result);
		printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm%s　%s\x1b[0m", barrierList[k]->position_x + 2, barrierList[k]->position_y + 1, colors[Barrier].R, colors[Barrier].G, colors[Barrier].B, colors[BarrierBlockText].R, colors[BarrierBlockText].G, colors[BarrierBlockText].B, shapeList[barrierList[k]->barrierLevel], shapeList[barrierList[k]->barrierLevel]);
	}
	Sleep(100);

}

void playSpActionAnimation()
{
	drawUI(11, 2, White, White, "SP ");
	Sleep(100);
	drawUI(11, 2, Green, White, "SP ");
	Sleep(100);

	drawUI(11, 2, White, White, "SP ");
	Sleep(100);
	drawUI(11, 2, Green, White, "SP ");
	Sleep(100);

	drawUI(11, 2, White, White, "SP ");
	Sleep(100);
	drawUI(11, 2, Green, White, "SP ");
	Sleep(100);

	drawUI(11, 2, White, White, "SP ");
	Sleep(100);
	drawUI(11, 2, Green, White, "SP ");

	Sleep(700);
}

void playSpCreateBlockAnimation(Block* block)
{
	drawAnimationUnit(block, EMPTY, block->colorEnum, "・・・");
	Sleep(34);

	drawAnimationUnit(block, EMPTY, block->colorEnum, "○○○");
	Sleep(34);

	drawAnimationUnit(block, EMPTY, block->colorEnum, "◎◎◎");
	Sleep(34);

	drawAnimationUnit(block, EMPTY, block->colorEnum, "●●●");
	Sleep(34);

	drawAnimationUnit(block, EMPTY, block->colorEnum, "■■■");
	Sleep(34);
}

void playBarrierClearAnimation(Block* barrier)
{
	const char* fullWidthDigits[] = { "０", "１", "２", "３", "４", "５", "６", "７", "８", "９" };
	char result[100] = "";
	char numStr[50];
	sprintf(numStr, "%d", 5 - barrier->barrierLevel);

	for (int i = 0; i < strlen(numStr); i++) {
		strcat(result, fullWidthDigits[numStr[i] - '0']);
	}

	printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm%s　%s\x1b[0m", barrier->position_x, barrier->position_y + 1, colors[BrightBarrier].R, colors[BrightBarrier].G, colors[BrightBarrier].B, colors[BarrierBlockText].R, colors[BarrierBlockText].G, colors[BarrierBlockText].B, shapeList[barrier->barrierLevel], shapeList[barrier->barrierLevel]);
	printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm　%s　\x1b[0m", barrier->position_x + 1, barrier->position_y + 1, colors[BrightBarrier].R, colors[BrightBarrier].G, colors[BrightBarrier].B, 143, 127, 219, result);
	printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm%s　%s\x1b[0m", barrier->position_x + 2, barrier->position_y + 1, colors[BrightBarrier].R, colors[BrightBarrier].G, colors[BrightBarrier].B, colors[BarrierBlockText].R, colors[BarrierBlockText].G, colors[BarrierBlockText].B, shapeList[barrier->barrierLevel], shapeList[barrier->barrierLevel]);

	Sleep(100);

	printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm%s　%s\x1b[0m", barrier->position_x, barrier->position_y + 1, colors[Barrier].R, colors[Barrier].G, colors[Barrier].B, colors[BarrierBlockText].R, colors[BarrierBlockText].G, colors[BarrierBlockText].B, shapeList[barrier->barrierLevel], shapeList[barrier->barrierLevel]);
	printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm　%s　\x1b[0m", barrier->position_x + 1, barrier->position_y + 1, colors[Barrier].R, colors[Barrier].G, colors[Barrier].B, 143, 127, 219, result);
	printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm%s　%s\x1b[0m", barrier->position_x + 2, barrier->position_y + 1, colors[Barrier].R, colors[Barrier].G, colors[Barrier].B, colors[BarrierBlockText].R, colors[BarrierBlockText].G, colors[BarrierBlockText].B, shapeList[barrier->barrierLevel], shapeList[barrier->barrierLevel]);
	Sleep(100);

	printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm%s　%s\x1b[0m", barrier->position_x, barrier->position_y + 1, colors[BrightBarrier].R, colors[BrightBarrier].G, colors[BrightBarrier].B, colors[BarrierBlockText].R, colors[BarrierBlockText].G, colors[BarrierBlockText].B, shapeList[barrier->barrierLevel], shapeList[barrier->barrierLevel]);
	printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm　%s　\x1b[0m", barrier->position_x + 1, barrier->position_y + 1, colors[BrightBarrier].R, colors[BrightBarrier].G, colors[BrightBarrier].B, 143, 127, 219, result);
	printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm%s　%s\x1b[0m", barrier->position_x + 2, barrier->position_y + 1, colors[BrightBarrier].R, colors[BrightBarrier].G, colors[BrightBarrier].B, colors[BarrierBlockText].R, colors[BarrierBlockText].G, colors[BarrierBlockText].B, shapeList[barrier->barrierLevel], shapeList[barrier->barrierLevel]);

	Sleep(100);

	printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm%s　%s\x1b[0m", barrier->position_x, barrier->position_y + 1, colors[Barrier].R, colors[Barrier].G, colors[Barrier].B, colors[BarrierBlockText].R, colors[BarrierBlockText].G, colors[BarrierBlockText].B, shapeList[barrier->barrierLevel], shapeList[barrier->barrierLevel]);
	printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm　%s　\x1b[0m", barrier->position_x + 1, barrier->position_y + 1, colors[Barrier].R, colors[Barrier].G, colors[Barrier].B, 143, 127, 219, result);
	printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm%s　%s\x1b[0m", barrier->position_x + 2, barrier->position_y + 1, colors[Barrier].R, colors[Barrier].G, colors[Barrier].B, colors[BarrierBlockText].R, colors[BarrierBlockText].G, colors[BarrierBlockText].B, shapeList[barrier->barrierLevel], shapeList[barrier->barrierLevel]);
	Sleep(100);

	printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm%s　%s\x1b[0m", barrier->position_x, barrier->position_y + 1, colors[BrightBarrier].R, colors[BrightBarrier].G, colors[BrightBarrier].B, colors[BarrierBlockText].R, colors[BarrierBlockText].G, colors[BarrierBlockText].B, shapeList[barrier->barrierLevel], shapeList[barrier->barrierLevel]);
	printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm　%s　\x1b[0m", barrier->position_x + 1, barrier->position_y + 1, colors[BrightBarrier].R, colors[BrightBarrier].G, colors[BrightBarrier].B, 143, 127, 219, result);
	printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm%s　%s\x1b[0m", barrier->position_x + 2, barrier->position_y + 1, colors[BrightBarrier].R, colors[BrightBarrier].G, colors[BrightBarrier].B, colors[BarrierBlockText].R, colors[BarrierBlockText].G, colors[BarrierBlockText].B, shapeList[barrier->barrierLevel], shapeList[barrier->barrierLevel]);

	Sleep(100);

	printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm%s　%s\x1b[0m", barrier->position_x, barrier->position_y + 1, colors[Barrier].R, colors[Barrier].G, colors[Barrier].B, colors[BarrierBlockText].R, colors[BarrierBlockText].G, colors[BarrierBlockText].B, shapeList[barrier->barrierLevel], shapeList[barrier->barrierLevel]);
	printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm　%s　\x1b[0m", barrier->position_x + 1, barrier->position_y + 1, colors[Barrier].R, colors[Barrier].G, colors[Barrier].B, 143, 127, 219, result);
	printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm%s　%s\x1b[0m", barrier->position_x + 2, barrier->position_y + 1, colors[Barrier].R, colors[Barrier].G, colors[Barrier].B, colors[BarrierBlockText].R, colors[BarrierBlockText].G, colors[BarrierBlockText].B, shapeList[barrier->barrierLevel], shapeList[barrier->barrierLevel]);
	Sleep(100);

	printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm%s　%s\x1b[0m", barrier->position_x, barrier->position_y + 1, colors[BrightBarrier].R, colors[BrightBarrier].G, colors[BrightBarrier].B, colors[BarrierBlockText].R, colors[BarrierBlockText].G, colors[BarrierBlockText].B, shapeList[barrier->barrierLevel], shapeList[barrier->barrierLevel]);
	printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm　%s　\x1b[0m", barrier->position_x + 1, barrier->position_y + 1, colors[BrightBarrier].R, colors[BrightBarrier].G, colors[BrightBarrier].B, 143, 127, 219, result);
	printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm%s　%s\x1b[0m", barrier->position_x + 2, barrier->position_y + 1, colors[BrightBarrier].R, colors[BrightBarrier].G, colors[BrightBarrier].B, colors[BarrierBlockText].R, colors[BarrierBlockText].G, colors[BarrierBlockText].B, shapeList[barrier->barrierLevel], shapeList[barrier->barrierLevel]);

	Sleep(100);

	printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm%s　%s\x1b[0m", barrier->position_x, barrier->position_y + 1, colors[Barrier].R, colors[Barrier].G, colors[Barrier].B, colors[BarrierBlockText].R, colors[BarrierBlockText].G, colors[BarrierBlockText].B, shapeList[barrier->barrierLevel], shapeList[barrier->barrierLevel]);
	printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm　%s　\x1b[0m", barrier->position_x + 1, barrier->position_y + 1, colors[Barrier].R, colors[Barrier].G, colors[Barrier].B, 143, 127, 219, result);
	printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm%s　%s\x1b[0m", barrier->position_x + 2, barrier->position_y + 1, colors[Barrier].R, colors[Barrier].G, colors[Barrier].B, colors[BarrierBlockText].R, colors[BarrierBlockText].G, colors[BarrierBlockText].B, shapeList[barrier->barrierLevel], shapeList[barrier->barrierLevel]);
	Sleep(100);

	printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm%s　%s\x1b[0m", barrier->position_x, barrier->position_y + 1, colors[BrightBarrier].R, colors[BrightBarrier].G, colors[BrightBarrier].B, colors[BarrierBlockText].R, colors[BarrierBlockText].G, colors[BarrierBlockText].B, shapeList[barrier->barrierLevel], shapeList[barrier->barrierLevel]);
	printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm　%s　\x1b[0m", barrier->position_x + 1, barrier->position_y + 1, colors[BrightBarrier].R, colors[BrightBarrier].G, colors[BrightBarrier].B, 143, 127, 219, result);
	printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm%s　%s\x1b[0m", barrier->position_x + 2, barrier->position_y + 1, colors[BrightBarrier].R, colors[BrightBarrier].G, colors[BrightBarrier].B, colors[BarrierBlockText].R, colors[BarrierBlockText].G, colors[BarrierBlockText].B, shapeList[barrier->barrierLevel], shapeList[barrier->barrierLevel]);

	Sleep(100);

	printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm%s　%s\x1b[0m", barrier->position_x, barrier->position_y + 1, colors[Barrier].R, colors[Barrier].G, colors[Barrier].B, colors[BarrierBlockText].R, colors[BarrierBlockText].G, colors[BarrierBlockText].B, shapeList[barrier->barrierLevel], shapeList[barrier->barrierLevel]);
	printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm　%s　\x1b[0m", barrier->position_x + 1, barrier->position_y + 1, colors[Barrier].R, colors[Barrier].G, colors[Barrier].B, 143, 127, 219, result);
	printf("\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm%s　%s\x1b[0m", barrier->position_x + 2, barrier->position_y + 1, colors[Barrier].R, colors[Barrier].G, colors[Barrier].B, colors[BarrierBlockText].R, colors[BarrierBlockText].G, colors[BarrierBlockText].B, shapeList[barrier->barrierLevel], shapeList[barrier->barrierLevel]);
	Sleep(100);
}

void BarrierBlockAnimation(Block* block)
{
	printf("\x1b[%d;%dH\x1b[48;2;255;255;245m\x1b[38;2;%d;%d;%dm□  □\x1b[0m", block->position_x, block->position_y + 1, colors[block->colorEnum].R, colors[block->colorEnum].G, colors[block->colorEnum].B);
	printf("\x1b[%d;%dH\x1b[48;2;255;255;245m\x1b[38;2;%d;%d;%dm□　□\x1b[0m", block->position_x + 1, block->position_y + 1, colors[block->colorEnum].R, colors[block->colorEnum].G, colors[block->colorEnum].B);
	printf("\x1b[%d;%dH\x1b[48;2;255;255;245m\x1b[38;2;221;246;236m・\x1b[0m", block->position_x + 1, block->position_y + 3);
	printf("\x1b[%d;%dH\x1b[48;2;255;255;245m\x1b[38;2;%d;%d;%dm□  □\x1b[0m", block->position_x + 2, block->position_y + 1, colors[block->colorEnum].R, colors[block->colorEnum].G, colors[block->colorEnum].B);
	Sleep(50);
	printf("\x1b[%d;%dH\x1b[48;2;255;255;245m\x1b[38;2;%d;%d;%dm++  ++\x1b[0m", block->position_x, block->position_y + 1, colors[block->colorEnum].R, colors[block->colorEnum].G, colors[block->colorEnum].B);
	printf("\x1b[%d;%dH\x1b[48;2;255;255;245m\x1b[38;2;%d;%d;%dm+    +\x1b[0m", block->position_x + 1, block->position_y + 1, colors[block->colorEnum].R, colors[block->colorEnum].G, colors[block->colorEnum].B);
	printf("\x1b[%d;%dH\x1b[48;2;255;255;245m\x1b[38;2;221;246;236m・\x1b[0m", block->position_x + 1, block->position_y + 3);
	printf("\x1b[%d;%dH\x1b[48;2;255;255;245m\x1b[38;2;%d;%d;%dm++  ++\x1b[0m", block->position_x + 2, block->position_y + 1, colors[block->colorEnum].R, colors[block->colorEnum].G, colors[block->colorEnum].B);
}