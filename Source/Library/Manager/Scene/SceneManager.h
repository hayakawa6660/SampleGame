#pragma once
#include "../../Common/SceneBase.h"
#include <string>
#include <typeinfo>

class SceneManager 
{
public:
	/// <summary>
	/// シングルトン
	/// </summary>
	static SceneManager* GetInstance();

	SceneManager();
	/// <summary>
	/// シーンをロードする
	/// </summary>
	/// <returns>シーン</returns>
	template<class C>
	C* LoadScene()
	{
		if (m_scene)
		{
			delete m_scene;
			m_scene = nullptr;
		}
		auto createScene = new C();
		m_scene = createScene;
		//クラス名取得
		m_scene->SetSceneName(typeid(&m_scene).name());
		return createScene;
	}
	void Update();
	void Draw();
private:
	~SceneManager();
	SceneBase* m_scene;
};