#include "App.h"
#include <DxLib.h>
#include <assert.h>
#include "Library/Manager/Scene/SceneManager.h"
#include "Scene/Title/TitleScene.h"

App::App()
{
	//�V���O���g����SceneManager�𐶐�
	auto sceneManager = SceneManager::GetInstance();
	//�^�C�g���V�[���𐶐�
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
