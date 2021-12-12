#include "PlayScene.h"
#include <DxLib.h>

PlayScene::PlayScene()
{
}

PlayScene::~PlayScene()
{
}

void PlayScene::Update()
{
}

void PlayScene::Draw()
{
#if _DEBUG
	DrawFormatString(0, 0, 0xffffff, "PlayScene");
#endif
}