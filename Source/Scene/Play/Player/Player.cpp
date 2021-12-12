#include "Player.h"
#include "../../../Common/CommonDefine.h"

Player::Player():
	m_bullet(nullptr),
	m_position({CommonDefine::WindowWidth / 2,CommonDefine::WindowHeight / 2 }),
	m_moveSpeed(1.5f)
{
}

void Player::Initialize(BulletManager* _bullet)
{
	m_bullet = _bullet;
}

Player::~Player()
{
	m_bullet = nullptr;
}

void Player::Update()
{
	if (CheckHitKey(KEY_INPUT_W)) 
	{
		m_position.y -= m_moveSpeed;
	}
	else if (CheckHitKey(KEY_INPUT_S))
	{

		m_position.y += m_moveSpeed;
	}


	if (CheckHitKey(KEY_INPUT_A))
	{
		m_position.x -= m_moveSpeed;
	}
	else if (CheckHitKey(KEY_INPUT_D))
	{
		m_position.x += m_moveSpeed;
	}

	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		m_bullet->CreateBullet(m_position, VGet(0, -10, 0), 0xffffff, 60, true);
	}
}

void Player::Draw()
{
	DrawFormatString((int)m_position.x, (int)m_position.y, 0xffffff, "P");
}

