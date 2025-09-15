#pragma once
#include "Actor.h"

class Pawn : public Actor
{
public:

	Pawn();

	virtual void Tick() override;
	virtual void PostTick() override;
	virtual void Render(HDC hdc) override;


private:
	

};

