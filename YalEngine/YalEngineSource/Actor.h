#pragma once
#include "GameObject.h"

struct Location
{
	float _X;
	float _Y;
	float _Z;
};

class Actor : public GameObject
{
public:

	Actor();
	~Actor();

	
	virtual void Tick() override;
	virtual void PostTick() override;
	virtual void Render(HDC hdc) override;

	void SetActorLocation(Location newLocation)
	{
		_Location._X = newLocation._X;
		_Location._Y = newLocation._Y;
		_Location._Z = newLocation._Z;
	}

	Location GetActorLocation() { return _Location; };


protected:

	Location _Location;

};

