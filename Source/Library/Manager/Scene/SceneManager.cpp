#include "SceneManager.h"

SceneManager* SceneManager::GetInstance()
{
	static SceneManager* instance = nullptr;
	if (!instance) 
	{
		instance = new SceneManager();
	}
	return instance;
}

SceneManager::SceneManager():
	m_scene(nullptr)
{
}

SceneManager::~SceneManager()
{
	delete m_scene;
	m_scene = nullptr;
}

void SceneManager::Update()
{
	if (m_scene) 
	{
		m_scene->Update();
	}
}

void SceneManager::Draw()
{
	if (m_scene)
	{
		m_scene->Draw();
	}
}
