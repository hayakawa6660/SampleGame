#pragma once
#include <list>
#include "../../../Library/Common/GameObject.h"
#include "DefaultBullet.h"

class BulletManager : public GameObject
{
public:
	BulletManager();
	~BulletManager();
	void Update()override;
	void Draw()override;
	void CreateBullet(VECTOR _pos, VECTOR _velocity, int _color, int _aliveTime, bool _isPlayer = false);
private:
	std::list<DefaultBullet*> m_bullets;
};

