#pragma once
#include <DxLib.h>

#include "../../../Library/Common/GameObject.h"
#include "../Bullet/BulletManager.h"

class Player : public GameObject
{
public:
	Player();
	void Initialize(BulletManager* _bullet);
	void Update()override;
	void Draw()override;
private:
	~Player();
	VECTOR m_position;
	float m_moveSpeed;
	BulletManager* m_bullet;
};