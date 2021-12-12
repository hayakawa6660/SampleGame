#pragma once
#include <DxLib.h>

class DefaultBullet
{
public:
	DefaultBullet();
	~DefaultBullet();
	void Initialize(VECTOR _pos, VECTOR _velocity, int _color, int _aliveTime, bool _isPlayer = false);
	void Update();
	void Draw();
	bool GetActive() { return m_active; }
private:
	VECTOR m_position;
	VECTOR m_velocity;
	int m_color;
	int m_aliveTime;
	int m_time;
	bool m_active;
	bool m_isPlyaer;
};