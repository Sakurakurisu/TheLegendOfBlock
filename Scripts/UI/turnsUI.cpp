#include "turnsUI.h"
#include "color.h"


////int gradientColorList[10] = { 160,161,162,163,164,165,166,167,168,169 };
TurnsUI turnsUI[10];

ColorRGB Color_0 = { 255, 186, 83 };
ColorRGB Color_1 = { 255, 186, 83 };
ColorRGB Color_2 = { 255, 207, 96 };
ColorRGB Color_3 = { 255, 207, 96 };
ColorRGB Color_4 = { 255, 207, 96 };
ColorRGB Color_5 = { 255, 233 ,116 };
ColorRGB Color_6 = { 255, 233 ,116 };
ColorRGB Color_7 = { 255, 233 ,116 };
ColorRGB Color_8 = { 255, 233 ,116 };
ColorRGB Color_9 = { 255, 233 ,116 };

ColorRGB gradientColorList[] = 
{
	Color_0,
	Color_1,
	Color_2,
	Color_3,
	Color_4,
	Color_5,
	Color_6,
	Color_7,
	Color_8,
	Color_9
};

void InitTurnsUI(int position_x, int position_y, int turnsCount)
{

	for (int i = 0; i < turnsCount; i++)
	{
		turnsUI[i] = { position_x , position_y + i * 2 , i, "œ"};
	}
}