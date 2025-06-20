#ifndef DRAWIMAGECVS_H
#define DRAWIMAGECVS_H

typedef struct
{
	int bR, bG, bB;
	char text[100];
	int tR, tG, tB;
} Pixel;

void LoadCSV(const char* fileName, Pixel image[][80], int rows, int cols);
void DrawImage(Pixel image[][80], int rows, int cols, int printPosition_x, int printPosition_y);

#endif
