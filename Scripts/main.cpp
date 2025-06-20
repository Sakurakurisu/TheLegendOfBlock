#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "block.h"
#include "conioex.h"
#include "map.h"
#include <windows.h>
#include "update.h"
#include "blockRandom.h"
#include "uiManager.h"
#include "player.h"
#include "devil.h"
#include "scence.h"
#define WIDTH 80 
#define HEIGHT 25

#define BUF_SIZE 1024*1024
extern char drawBuffer[BUF_SIZE];
extern char displayBuffer[BUF_SIZE];

void InitConsole()
{
    // バッファの初期化
    memset(displayBuffer, ' ', BUF_SIZE);
    memset(drawBuffer, ' ', BUF_SIZE);

    // コンソールの出力および入力ハンドルを取得
    HANDLE hOutputConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE hInputConsole = GetStdHandle(STD_INPUT_HANDLE);

    // 画面バッファサイズを設定
    COORD coord;
    coord.X = 80; // 幅は80文字
    coord.Y = 25; // 高さは25文字
    SetConsoleScreenBufferSize(hOutputConsole, coord);

    // コンソールウィンドウのタイトルを設定
    SetConsoleTitle(TEXT("ブロックの伝説　Legend of Block"));

    // ウィンドウサイズを設定
    SMALL_RECT rect;
    rect.Left = 0;
    rect.Top = 0;
    rect.Right = 80 - 1; // 幅は80文字、インデックスは0からなので1を引く
    rect.Bottom = 25 - 1; // 高さは25文字、インデックスは0からなので1を引く
    SetConsoleWindowInfo(hOutputConsole, TRUE, &rect);

    // クイック編集モードなどを無効化
    DWORD prevMode;
    GetConsoleMode(hInputConsole, &prevMode);
    SetConsoleMode(hInputConsole, prevMode & ~(ENABLE_QUICK_EDIT_MODE | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT));

    // カーソルを非表示に設定（必要に応じて調整）
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hOutputConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE; // カーソルを非表示にする
    SetConsoleCursorInfo(hOutputConsole, &cursorInfo);

    // コンソールフォントのサイズを設定
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;
    cfi.dwFontSize.Y = 20;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_BOLD;
    wcscpy_s(cfi.FaceName, L"Consolas");
    SetCurrentConsoleFontEx(hOutputConsole, FALSE, &cfi);

    // ANSIエスケープシーケンスのサポートを有効化
    DWORD dwMode = 0;
    GetConsoleMode(hOutputConsole, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOutputConsole, dwMode);

    HWND consoleWindow = GetConsoleWindow();
    SetWindowPos(consoleWindow, 0, 200, 110, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}

int main()
{
    InitConsole();

    InitScene();

    while (1)
    {
        UpdateScene();
    }

    return 0;
}
