#include "YalApplication.h"

namespace yal
{
	Application::Application() : _hwnd(nullptr), _hdc(nullptr), _speed(0.01)
	{

	}

	Application::~Application()
	{

	}

	void Application::Initialize(HWND hwnd)
	{
		_hwnd = hwnd;
		_hdc = GetDC(hwnd);
	}

	void Application::Tick()
	{
		_speed += 0.01;
	}

	void Application::PostTick()
	{

	}

	void Application::Run()
	{
		Tick();
		PostTick();
		Render();
	}

	void Application::Render()
	{

		//배경 선택
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255)); // 배경 변경
		HBRUSH oldBrush = (HBRUSH)SelectObject(_hdc, brush); //선택

		//펜 선택
		HPEN redPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0)); //빨간펜 변경
		HPEN oldPen = (HPEN)SelectObject(_hdc, redPen); //선택
		

		Rectangle(_hdc, 100 + _speed, 100, 200 + _speed, 200); // 네모 그려주기


		//배경삭제
		DeleteObject(brush); // 메모리에 남지않게 삭제
		SelectObject(_hdc, oldBrush); // 다시 하얀배경 선택

		//펜삭제
		SelectObject(_hdc, oldPen);
		DeleteObject(redPen);

	}
}

