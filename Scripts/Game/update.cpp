#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "block.h"
#include "color.h"
#include "cleanChecker.h"
#include "blockRandom.h"

#define CONIOEX
#include "conioex.h"
#include <windows.h>
#include "player.h"
#include "uiManager.h"
#include "devil.h"
#include "animation.h"
#include "inputSystem.h"
#include "game.h"
#include "audioManager.h"
#include "scence.h"


void StartDevilTurns(int damage)
{
   
}



void spAction()
{
    Block* barrierList[50] = {};  // バリアブロックを一時的に保存する配列
    int index = 0;

    // マップを走査して、バリアブロックをリストアップする
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

    srand(time(NULL));  // 乱数初期化

    if (index != 0)
    {
        int i = rand() % index;  // ランダムにバリア1つ選択

        playBarrierClearAnimation(barrierList[i]);  // バリア破壊アニメーション

        int colorRandom = rand() % 3;
        // バリアの代わりにランダムな色ブロック生成
        switch (colorRandom)
        {
            case 0:
                barrierList[i]->colorEnum = Red;
                break;
            case 1:
                barrierList[i]->colorEnum = Green;
                break;
            case 2:
                barrierList[i]->colorEnum = Blue;
                break;
        }

        barrierList[i]->barrierLevel = 0;
        playSpCreateBlockAnimation(barrierList[i]);  // SP演出アニメーション
        updateMap();
    }
    else
    {
        rollBlock(map, 2);  // バリアが存在しない場合、ブロックを2回転がす
    }
}


void update(float deltaTime) {

    updateMouseButtonDown();  // マウスクリック更新

    Direction keyBoardInput = None;
    Direction mouseInput = None;

    // キーボード入力を確認
    keyBoardInput = getKeyBoardDirection();

    if (keyBoardInput == None)
    {
        // キーボード入力がなければ、マウスの動きを確認
        mouseInput = getMouseMovementDirection();
    }

    // 実際に使う入力を決定（どちらか一方）
    Direction effectiveInput = (keyBoardInput != None) ? keyBoardInput : mouseInput;

    if (effectiveInput != None)
    {
        playsound(moveAudio, 0);
        move(effectiveInput);  // ブロックを移動
        remainingTurns--;  // 残りターン減少
        playTurnsUI();
        playMapFrameAnimation(effectiveInput);
        bounceConsoleWindow(effectiveInput, 25);
        printMapFrame();
        cleanBlock(map, effectiveInput);  // 消去可能ブロックチェック
        rollBlock(map, 3);  // ブロックを3回ランダムにロール
    }

    // ターン終了処理
    if (remainingTurns == 0)
    {
        playTurnOverAnimation();
        remainingTurns = 10;
        updatePlayerInfo();

        // プレイヤーの攻撃力がある場合、攻撃アニメーション演出
        if (atk_player != 0)
        {
            Sleep(700);
            printMapFrame();
            playsound(atkAudio, 0);
            playMapFrameAnimation(Right);
            bounceConsoleWindow(Right, 60);
            printMapFrame();
        }

        playTurnOverAnimation();
        Sleep(600);
        playsound(damageAudio, 0);
        AnimateWindowPosition(10, 4);
        printDevilDamage();
        updateDevilInfo();

        // SPゲージが10以上なら特殊スキル発動
        if (sp_player >= 10)
        {
            playSpActionAnimation();
            spAction();
        }

        playTurnOverAnimation();
        Sleep(1000);

        turnCount++;

        // 敵のターン処理（悪魔が生きていれば）
        if (hp_devil > 0)
        {
            // 悪魔のUI枠演出
            drawUI(1, 18, DevilPuple, BrightPuple, "□□□□□□□□□□□□□□□□□□□□□□□");
            drawUI(23, 18, DevilPuple, BrightPuple, "□□□□□□□□□□□□□□□□□□□□□□□");
            for (int k = 1; k < 24; k++)
            {
                drawUI(k, 18, DevilPuple, BrightPuple, "□");
                drawUI(k, 62, DevilPuple, BrightPuple, "□");
            }

            drawUI(24, 29, BGBlue, White, "   ");
            drawUI(24, 54, DevilUI, White, "-＞");
            Sleep(800);

            int damage = getPlayerDamage();  // プレイヤーへのダメージ計算
            if (damage > 0)
            {
                ShingBarrier();  // バリアを追加

                printMapFrame();
                for (int k = 1; k < 24; k++)
                {
                    drawUI(k, 18, DevilPuple, White, "　");  // 攻撃演出
                }
                playsound(atkAudio, 0);
                bounceConsoleWindow(Left, 60);
                printMapFrame();

                // 攻撃枠再表示
                drawUI(1, 18, DevilPuple, BrightPuple, "□□□□□□□□□□□□□□□□□□□□□□□");
                drawUI(23, 18, DevilPuple, BrightPuple, "□□□□□□□□□□□□□□□□□□□□□□□");
                for (int k = 1; k < 24; k++)
                {
                    drawUI(k, 18, DevilPuple, BrightPuple, "□");
                    drawUI(k, 62, DevilPuple, BrightPuple, "□");
                }

                Sleep(600);
                playsound(damageAudio, 0);
                AnimateWindowPosition(10, 4);
                printPlayerDamage(damage);  // ダメージを表示
                if (hp_player <= 0)
                {
                    SetScene(SCENE_GAMEOVER);  // プレイヤーが死亡したらゲームオーバー
                    CheckScene();
                    return;
                }
            }

            // バリアブロック生成
            createBlockBarrier(map);

            drawUI(24, 54, BGBlue, White, "   ");
            printMapFrame();
            printTurnsInfo();

            // SPゲージの表示更新（減少アニメーション）
            for (int i = sp_player; i > 0; i--)
            {
                sp_player--;
                printf("\x1b[11;7H\x1b[48;2;%d;%d;%dm\x1b[38;5;%d;%d;%dm  \x1b[0m", colors[PlayerUI].R, colors[PlayerUI].G, colors[PlayerUI].B, colors[White].R, colors[White].G, colors[White].B);
                printf("\x1b[11;7H\x1b[48;2;%d;%d;%dm\x1b[38;5;%d;%d;%dm%d\x1b[0m", colors[PlayerUI].R, colors[PlayerUI].G, colors[PlayerUI].B, colors[White].R, colors[White].G, colors[White].B, sp_player);
                Sleep(25);
            }

            // ATK表示の更新（減少アニメーション）
            for (int j = atk_player; j > 0; j--)
            {
                atk_player--;
                printf("\x1b[13;7H\x1b[48;2;%d;%d;%dm\x1b[38;5;%d;%d;%dm  \x1b[0m", colors[PlayerUI].R, colors[PlayerUI].G, colors[PlayerUI].B, colors[White].R, colors[White].G, colors[White].B);
                printf("\x1b[13;7H\x1b[48;2;%d;%d;%dm\x1b[38;5;%d;%d;%dm%d\x1b[0m", colors[PlayerUI].R, colors[PlayerUI].G, colors[PlayerUI].B, colors[White].R, colors[White].G, colors[White].B, atk_player);
                Sleep(25);
            }

        }
        else
        {
            // 悪魔のHPが0になったら勝利シーンへ
            SetScene(SCENE_YOUWIN);
            CheckScene();
            return;
        }
    }
}




