#pragma once
#include "../../Common/SceneBase.h"
#include <string>
#include <typeinfo>

class SceneManager 
{
public:
	/// <summary>
	/// �V���O���g��
	/// </summary>
	static SceneManager* GetInstance();

	SceneManager();
	/// <summary>
	/// �V�[�������[�h����
	/// </summary>
	/// <returns>�V�[��</returns>
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
		//�N���X���擾
		m_scene->SetSceneName(typeid(&m_scene).name());
		return createScene;
	}
	void Update();
	void Draw();
private:
	~SceneManager();
	SceneBase* m_scene;
};