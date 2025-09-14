#include "YalApplication.h"


Application::Application() :
	_hwnd(nullptr),
	_hdc(nullptr),
	_speed(0.f)
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
	_Player.Tick();
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
	_Player.Render(_hdc);

	

}


