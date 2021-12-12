#pragma once
#include <list>
#include "../../Library/Common/SceneBase.h"

class GameObject;
class PlayScene : public SceneBase
{
public:
	PlayScene();
	void Update();
	void Draw();
	template<class C>
	C* CreateObject(std::string _tag)
	{
		auto object = new C();
		object->SetTag(_tag);
		m_objects.push_back(object);
		return object;
	}
private:
	~PlayScene();
	std::list<GameObject*> m_objects;
};