#include "App.h"
#include <DxLib.h>
#include <assert.h>
#include "Library/Manager/Scene/SceneManager.h"
#include "Scene/Title/TitleScene.h"

App::App()
{
	//シングルトンでSceneManagerを生成
	auto sceneManager = SceneManager::GetInstance();
	//タイトルシーンを生成
	sceneManager->LoadScene<TitleScene>();
}

App::~App()
{
}

void App::Update()
{
	SceneManager::GetInstance()->Update();
}

void App::Draw()
{
	SceneManager::GetInstance()->Draw();
}
