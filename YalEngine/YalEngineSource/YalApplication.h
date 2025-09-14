#pragma once
#include "CommonInclude.h"

namespace yal
{
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
		float _x;
		float _y;
	};
}


