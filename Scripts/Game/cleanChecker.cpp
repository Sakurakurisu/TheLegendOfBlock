#include "cleanChecker.h"
#include "map.h"
#include <corecrt_malloc.h>
#include "color.h"
#include <stdlib.h>
#include <windows.h>
#include "animation.h"
#include "player.h"
#include "uiManager.h"
#include "audioManager.h"

void cleanBlock(Block map[7][7], Direction direction)
{
	Block* cleanBlocks[50] = {};

	int currentIndex = 0;
	int i = 0;
	switch (direction) 
	{
		case Up:
			for (int i = 0; i < 7; i++)
			{
				// 上方向に隣接するブロックを判定
				for (int j = 0; j < 6 && map[j][i].colorEnum != EMPTY && map[j + 1][i].colorEnum != EMPTY; j++)
				{
					// 同じ色かつバリアでない場合
					if (isSameColor(&map[j][i], &map[j + 1][i]) && map[j][i].colorEnum != Barrier && map[j + 1][i].colorEnum != Barrier)
					{
						// すでにcleanBlocksに含まれているか判定（重複防止）
						if (cleanBlocks[currentIndex] == &map[j][i])
						{
							cleanBlocks[++currentIndex] = &map[j + 1][i];
							currentIndex++;
						}
						else
						{
							cleanBlocks[currentIndex] = &map[j][i];
							cleanBlocks[++currentIndex] = &map[j + 1][i];
							currentIndex++;
						}
					}
				}
			}
			break;
		case Down:
			for (int i = 0; i < 7; i++)
			{
				// 下方向に隣接するブロックを判定
				for (int j = 6; j > 0 && map[j][i].colorEnum != EMPTY && map[j - 1][i].colorEnum != EMPTY; j--)
				{
					// 同じ色かつバリアでない場合
					if (isSameColor(&map[j][i], &map[j - 1][i]) && map[j][i].colorEnum != Barrier && map[j - 1][i].colorEnum != Barrier)
					{
						// すでにcleanBlocksに含まれているか判定（重複防止）
						if (cleanBlocks[currentIndex] == &map[j][i])
						{
							cleanBlocks[++currentIndex] = &map[j - 1][i];
							currentIndex++;
						}
						else
						{
							cleanBlocks[currentIndex] = &map[j][i];
							cleanBlocks[++currentIndex] = &map[j - 1][i];
							currentIndex++;
						}
					}
				}
			}
			break;
		case Left:
			for (int i = 0; i < 7; i++)
			{
				// 左方向に隣接するブロックを判定
				for (int j = 0; j < 6 && map[i][j].colorEnum != EMPTY && map[i][j+1].colorEnum != EMPTY; j++)
				{
					// 同じ色かつバリアでない場合
					if (isSameColor(&map[i][j], &map[i][j + 1]) && map[i][j].colorEnum != Barrier && map[i][j + 1].colorEnum != Barrier)
					{
						// すでにcleanBlocksに含まれているか判定（重複防止）
						if (cleanBlocks[currentIndex] == &map[i][j])
						{
							cleanBlocks[++currentIndex] = &map[i][j + 1];
							currentIndex++;
						}
						else
						{
							cleanBlocks[currentIndex] = &map[i][j];
							cleanBlocks[++currentIndex] = &map[i][j + 1];
							currentIndex++;
						}
					}
				}
			}
			break;
		case Right:
			for (int i = 0; i < 7; i++)
			{
				// 右方向に隣接するブロックを判定
				for (int j = 6; j > 0 && map[i][j].colorEnum != EMPTY && map[i][j-1].colorEnum != EMPTY; j--)
				{
					// 同じ色かつバリアでない場合
					if (isSameColor(&map[i][j], &map[i][j - 1]) && map[i][j].colorEnum != Barrier && map[i][j - 1].colorEnum != Barrier)
					{
						// すでにcleanBlocksに含まれているか判定（重複防止）
						if (cleanBlocks[currentIndex] == &map[i][j])
						{
							cleanBlocks[++currentIndex] = &map[i][j - 1];
							currentIndex++;
						}
						else
						{
							cleanBlocks[currentIndex] = &map[i][j];
							cleanBlocks[++currentIndex] = &map[i][j - 1];
							currentIndex++;
						}
					}
				}
			}
			break;
	}

	if (currentIndex != 0)
	{
		// 消去アニメーションを再生
		playClearAnimation(cleanBlocks, currentIndex);
	}

	// ブロック消去処理
	for (int i = 0; i < currentIndex; i++)
	{
		// 色ごとにカウントを加算
		switch(cleanBlocks[i]->colorEnum)
		{
			case Red:
				redBlockCleanCount++;
				break;
			case Green:
				greenBlockCleanCount++;
				break;
			case Blue:
				blueBlockCleanCount+=2;
				break;
		}
		printBlocksCountUI(redBlockCleanCount, greenBlockCleanCount, blueBlockCleanCount);
		Sleep(25);
		cleanBlocks[i]->colorEnum = EMPTY;
	}

	updateMap();
}

// 2つのブロックが同じ色か判定
bool isSameColor(Block* block_1, Block* block_2)
{
	return block_1->colorEnum == block_2->colorEnum;
}