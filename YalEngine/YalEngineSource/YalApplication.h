#pragma once
#include "Pawn.h"


class Application
{
public:
	Application();
	~Application();

	void Initialize(HWND hwnd);
	void Run();
	void Tick();
	void PostTick();

	void Render();

private:

	HWND _hwnd;
	HDC _hdc;

	float _speed;
	Pawn _Player;
};


