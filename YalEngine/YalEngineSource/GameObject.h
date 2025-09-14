#pragma once
#include "CommonInclude.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	virtual void Tick();
	virtual void PostTick();
	virtual void Render(HDC hdc);

private:

};


