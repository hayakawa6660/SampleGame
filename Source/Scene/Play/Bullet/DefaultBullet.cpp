#include "DefaultBullet.h"

DefaultBullet::DefaultBullet():
	m_position({0,0,0}),
	m_velocity({ 0,0,0 }),
	m_color(0xffffff),
	m_aliveTime(0),
	m_time(0),
	m_active(true),
	m_isPlyaer(false)
{
}

DefaultBullet::~DefaultBullet()
{
}

void DefaultBullet::Initialize(VECTOR _pos, VECTOR _velocity, int _color, int _aliveTime, bool _isPlayer)
{
	m_position = _pos;
	m_velocity = _velocity;
	m_color = _color;
	m_aliveTime = _aliveTime;
	m_isPlyaer = _isPlayer;
	m_time = 0;
	m_active = true;
}

void DefaultBullet::Update()
{
	m_position.x += m_velocity.x;
	m_position.y += m_velocity.y;
	if (++m_time > m_aliveTime)
	{
		m_active = false;
	}
}

void DefaultBullet::Draw()
{
	if (m_active) 
	{
		DrawFormatString(m_position.x, m_position.y, m_color, "Åú");
	}
}
