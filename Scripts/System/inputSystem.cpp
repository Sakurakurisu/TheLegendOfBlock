#include <windows.h>
#include <stdio.h>
#include "map.h"
#define CONIOEX
#include "conioex.h"


static POINT lastPoint = { 0, 0 };  // 最後に記録されたマウス座標
static BOOL isMouseDown = FALSE;   // マウスボタンが押されているかどうかのフラグ

// マウスの左ボタンの状態を更新する関数
void updateMouseButtonDown() {
    if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
    { // 左クリックが押されているか
        if (!isMouseDown)
        {
            isMouseDown = TRUE;  // 押された瞬間を検出
            GetCursorPos(&lastPoint);  // 現在のカーソル座標を保存
        }
    }
    else
    {
        isMouseDown = FALSE;  // 離された場合、フラグをリセット
    }
}

// マウスの移動方向を取得する関数
Direction getMouseMovementDirection() {
    if (!isMouseDown)
    {
        return None;  // マウスが押されていなければ方向なし
    }

    POINT currentPoint;
    Direction direction = None;

    if (GetCursorPos(&currentPoint))
    {
        if (currentPoint.x == lastPoint.x && currentPoint.y == lastPoint.y)
        {
            // 移動していない場合
            direction = None;
        }
        else
        {
            // X軸とY軸の差分を比較して、どちらの移動が大きいかを判断
            if (abs(currentPoint.x - lastPoint.x) > abs(currentPoint.y - lastPoint.y))
            {
                // 横方向の移動が大きい → 左右方向と判断
                if (currentPoint.x > lastPoint.x)
                {
                    direction = Right;  // 右へ動かした
                }
                else
                {
                    direction = Left;   // 左へ動かした
                }
            }
            else
            {
                // 縦方向の移動が大きい → 上下方向と判断
                if (currentPoint.y > lastPoint.y)
                {
                    direction = Down;   // 下へ動かした
                }
                else
                {
                    direction = Up;     // 上へ動かした
                }
            }
        }

        // 方向が検出されたら、現在の座標を新たな基準として記録
        if (direction != None)
        {
            lastPoint = currentPoint;
        }
    }

    return direction;
}

// キーボード入力を方向に変換する関数
Direction getKeyBoardDirection()
{
    // 上キーまたはWキー
    if (GetAsyncKeyState(VK_UP) & 0x8000 || GetAsyncKeyState('W') & 0x8000)
    {
        return Up;
    }
    // 下キーまたはSキー
    else if (GetAsyncKeyState(VK_DOWN) & 0x8000 || GetAsyncKeyState('S') & 0x8000)
    {
        return Down;
    }
    // 左キーまたはAキー
    else if (GetAsyncKeyState(VK_LEFT) & 0x8000 || GetAsyncKeyState('A') & 0x8000)
    {
        return Left;
    }
    // 右キーまたはDキー
    else if (GetAsyncKeyState(VK_RIGHT) & 0x8000 || GetAsyncKeyState('D') & 0x8000)
    {
        return Right;
    }
    return None;  // どのキーも押されていない場合
}
