#pragma once
#include "../../Library/Common/SceneBase.h"

class TitleScene : public SceneBase
{
public:
	TitleScene();
	~TitleScene();
	void Update()override;
	void Draw()override;
private:
	enum SelectStatus : int
	{
		GameStart = 0,
		Option,
		Exsit,
	};
	/// <summary>
	/// Œˆ’è
	/// </summary>
	void Decision();

	SelectStatus selectStatus;
	const char* selectStr[SelectStatus::Exsit + 1];
	bool lastPush;
};