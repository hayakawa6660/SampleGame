#include "PlayScene.h"
#include <DxLib.h>

#include "../../Library/Common/GameObject.h"
#include "Player/Player.h"
#include "Bullet/BulletManager.h"

PlayScene::PlayScene()
{
	m_objects.clear();
	auto bullet = CreateObject<BulletManager>("Bullet");
	auto player = CreateObject<Player>("Player");
	player->Initialize(bullet);
}

PlayScene::~PlayScene()
{
	for (auto it = m_objects.begin(); it != m_objects.end();)
	{
		delete (*it);
		it = m_objects.erase(it);
	}
}

void PlayScene::Update()
{
	for (auto obj : m_objects)
	{
		obj->Update();
	}
}

void PlayScene::Draw()
{
#if _DEBUG
	DrawFormatString(0, 0, 0xffffff, "PlayScene");
#endif
	for (auto obj : m_objects)
	{
		obj->Draw();
	}
}