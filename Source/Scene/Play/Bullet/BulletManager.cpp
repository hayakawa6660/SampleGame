#include "BulletManager.h"

BulletManager::BulletManager()
{
	m_bullets.clear();
}

BulletManager::~BulletManager()
{
	for (auto it = m_bullets.begin(); it != m_bullets.end();) 
	{
		delete (*it);
		it = m_bullets.erase(it);
	}
}

void BulletManager::Update()
{
	for (auto b : m_bullets)
	{
		b->Update();
	}
}

void BulletManager::Draw()
{
	for (auto b : m_bullets)
	{
		b->Draw();
	}
}

void BulletManager::CreateBullet(VECTOR _pos, VECTOR _velocity, int _color, int _aliveTime, bool _isPlayer)
{
	for (auto b : m_bullets) 
	{
		if (b->GetActive()) 
		{
			continue;
		}
		b->Initialize(_pos, _velocity, _color, _aliveTime, _isPlayer);
		return;
	}
	DefaultBullet* bullet = new DefaultBullet();
	bullet->Initialize(_pos, _velocity, _color, _aliveTime, _isPlayer);
	m_bullets.push_back(bullet);
}
