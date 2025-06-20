#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "drawImageCSV.h"



#include <stdio.h>
#include <string.h>

void LoadCSV(const char* fileName, Pixel image[][80], int rows, int cols)
{
    FILE* file = fopen(fileName, "r"); // CSVファイルを読み込みモードで開く
    if (!file)
    {
        perror("Failed to open image CSV file"); // ファイルが開けなければエラーメッセージ表示して終了
        exit(EXIT_FAILURE);
    }

    char line[10000]; // 1行の読み込みバッファ
    int row = 0;
    while (fgets(line, sizeof(line), file) && row < rows)
    {
        int col = 0;
        char* token = strtok(line, ","); // カンマ区切りで最初のトークンを取得
        while (token != NULL && col < cols)
        {
            int bR, bG, bB;         // 背景色（RGB）
            char text[100];         // 表示文字
            int tR, tG, tB;         // 文字色（RGB）

            // CSV形式: 背景R 背景G 背景B テキスト 文字R 文字G 文字B
            if (sscanf(token, "%d %d %d %99s %d %d %d", &bR, &bG, &bB, text, &tR, &tG, &tB) == 7)
            {
                if (strcmp(text, "404") == 0)
                {
                    strcpy(text, " "); // "404"は空白に置き換え（透明表示とするため）
                }

                // ピクセル情報を構造体に格納
                image[row][col].bR = bR;
                image[row][col].bG = bG;
                image[row][col].bB = bB;
                strncpy(image[row][col].text, text, sizeof(image[row][col].text) - 1);
                image[row][col].text[sizeof(image[row][col].text) - 1] = '\0'; // 安全な終端
                image[row][col].tR = tR;
                image[row][col].tG = tG;
                image[row][col].tB = tB;

                col++;
            }

            token = strtok(NULL, ","); // 次のトークンへ
        }

        row++;
    }

    fclose(file);
}



void DrawImage(Pixel image[][80], int rows, int cols, int printPosition_x, int printPosition_y)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int bR = image[i][j].bR;
            int bG = image[i][j].bG;
            int bB = image[i][j].bB;

            int tR = image[i][j].tR;
            int tG = image[i][j].tG;
            int tB = image[i][j].tB;

            // 背景も文字も空（透明セル）の場合
            if (bR == 0 && bG == 0 && bB == 0 && strcmp(image[i][j].text, " ") == 0)
            {
                printf("\x1b[%d;%dH ", i + 1 + printPosition_x, j + 1 + printPosition_y);
            }
            // 背景色なし＋文字あり → 色なしのテキスト表示
            else if (bR == 0 && bG == 0 && bB == 0 && strcmp(image[i][j].text, " ") != 0)
            {
                printf("\x1b[%d;%dH%s", i + 1 + printPosition_x, j + 1 + printPosition_y, image[i][j].text);
            }
            else
            {
                // 背景色・文字色を付けたカラー表示
                printf(
                    "\x1b[%d;%dH\x1b[48;2;%d;%d;%dm\x1b[38;2;%d;%d;%dm%s",
                    i + 1 + printPosition_x, j + printPosition_y,
                    bR, bG, bB, tR, tG, tB, image[i][j].text
                );
                printf("\x1b[0m"); // 色リセット
            }
        }
    }
}
