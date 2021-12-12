#include "TitleScene.h"
#include <DxLib.h>

#include "../../Library/Manager/Scene/SceneManager.h"
#include "../../Common/CommonDefine.h"
#include "../Play/PlayScene.h"

TitleScene::TitleScene():
	selectStatus(GameStart),
	selectStr{"Start","Option","Exsit"},
	lastPush(false)
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Update()
{
	//カーソル移動
	if (CheckHitKey(KEY_INPUT_UP) && !lastPush)
	{
		if (selectStatus == 0) 
		{
			selectStatus = Exsit;
		}
		else
		{
			selectStatus = (SelectStatus)((int)selectStatus - 1);
		}
		lastPush = true;
	}
	else if (CheckHitKey(KEY_INPUT_DOWN) && !lastPush)
	{
		if (selectStatus == Exsit)
		{
			selectStatus = (SelectStatus)0;
		}
		else
		{
			selectStatus = (SelectStatus)((int)selectStatus + 1);
		}
		lastPush = true;
	}
	else if (!CheckHitKeyAll())
	{
		lastPush = false;
	}
	//決定
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		Decision();
	}
}

void TitleScene::Draw()
{
#if _DEBUG
	DrawFormatString(0, 0, 0xffffff,"TitleScene");
#endif
	for (int i = 0; i < SelectStatus::Exsit + 1; i++) 
	{
		int y = (CommonDefine::WindowHeight / 2) + i * 20;
		DrawFormatString(CommonDefine::WindowWidth / 2, y, 0xffffff, selectStr[i],true);
		if (selectStatus == i) 
		{
			//カーソル表示
			DrawFormatString((CommonDefine::WindowWidth / 2) - 30, y, 0xffffff, "->", true);
		}
	}
}

void TitleScene::Decision()
{
	switch (selectStatus)
	{
	case GameStart:
		SceneManager::GetInstance()->LoadScene<PlayScene>();
		break;
	case Option:
		break;
	case Exsit:
		break;
	}
}
