



//列挙体でシーンの種類を定義する
enum SCENE
{
	SCENE_TITLE,	//タイトル画面
	SCENE_GAME,		//ゲーム本編
	SCENE_RESULT,	//ゲーム結果表示画面
	SCENE_GAMEOVER,
	SCENE_YOUWIN,
	SCENE_NUM,		//終端コード
};

extern SCENE g_Scene;
void InitScene(void);
void UninitScene(void);
void UpdateScene(void);
void DrawScene(void);

void SetScene(SCENE next);
void CheckScene(void);
