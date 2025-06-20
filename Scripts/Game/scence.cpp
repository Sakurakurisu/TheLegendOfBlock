#define CONIOEX
#include "conioex.h"
#include "scence.h"
#include "game.h"
#include "title.h"
#include "gameOver.h"
#include "youWin.h"

//起動時に動作させたいシーンをセットしておく
SCENE g_Scene = SCENE_TITLE;		//現在動作中のシーン
//SCENE g_SceneNext = SCENE_TITLE;	//移行先のシーン

//デバッグ中はタイトル表示から始まると面倒なのでゲーム画面から始めているので後で消す
SCENE g_SceneNext = SCENE_GAME;	//移行先のシーン


//シーンの初期化
void InitScene(void)
{
	switch (g_Scene)
	{
	case SCENE_TITLE:
		//タイトル画面の初期化
		InitTitle();
		break;
	case SCENE_GAME:
		//ゲーム本編の初期化
		InitGame();
		break;
	case SCENE_GAMEOVER:
		InitGameOver();
		break;
	case SCENE_YOUWIN:
		InitYouWin();
		break;
	case SCENE_RESULT:
		//リザルト画面の初期化
		break;
	}
}


//シーンの終了処理
void UninitScene(void)
{
	switch (g_Scene)
	{
	case SCENE_TITLE:
		//タイトル画面の終了処理
		UninitTitle();
		break;
	case SCENE_GAME:
		//ゲーム本編の終了処理
		//UninitGame();
		break;
	case SCENE_RESULT:
		//リザルト画面の終了処理
		break;
	}
}


//シーンの更新処理
void UpdateScene(void)
{
	switch (g_Scene)
	{
	case SCENE_TITLE:
		//タイトル画面の更新処理
		//UpdateTitle();
		break;
	case SCENE_GAME:
		//ゲーム本編の更新処理
		UpdateGame();
		break;

	case SCENE_GAMEOVER:
		
		break;
	case SCENE_YOUWIN:
		
		break;
	case SCENE_RESULT:
		//リザルト画面の更新処理
		break;
	}
}


//シーンの描画処理
void DrawScene(void)
{
	switch (g_Scene)
	{
	case SCENE_TITLE:
		//タイトル画面の描画処理
		//DrawTitle();
		break;
	case SCENE_GAME:
		//ゲーム本編の描画処理
		//DrawGame();
		break;
	case SCENE_RESULT:
		//リザルト画面の描画処理
		break;
	}
}


//移行先シーンのセット
void SetScene(SCENE next)
{
	g_SceneNext = next;
}


//シーン切り替え
void CheckScene(void)
{
	//移行先シーンがセットされているかを確認する
	if (g_Scene != g_SceneNext)
	{
		//現在動作中のシーンを終了させる
		UninitScene();

		//現在動作中のシーンを移行先シーンで更新する
		g_Scene = g_SceneNext;

		//画面のクリア
		clrscr();

		//更新したシーンの初期化を行う
		InitScene();

		
		
	}
}
