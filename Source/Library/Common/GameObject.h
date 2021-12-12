#pragma once
#include <string>

class GameObject 
{
public:
	GameObject();
	~GameObject();
	virtual void Update();
	virtual void Draw();
	void SetTag(const std::string& _tag) { tag = _tag; }
	const std::string& GetTag() { return tag; }
private:
	std::string tag;
};