#include "SceneBase.h"

SceneBase::SceneBase():
	m_sceneName("")
{
}

SceneBase::~SceneBase()
{
}

void SceneBase::Update()
{
}

void SceneBase::Draw()
{
}

void SceneBase::SetSceneName(std::string _name)
{
	m_sceneName = _name;
}
