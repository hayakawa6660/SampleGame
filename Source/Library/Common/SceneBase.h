#pragma once
#include <string>

class SceneBase
{
public:
	SceneBase();
	~SceneBase();
	virtual void Update();
	virtual void Draw();
	void SetSceneName(std::string _name);
	const std::string& GetName() { return m_sceneName; }
private:
	std::string m_sceneName;
};