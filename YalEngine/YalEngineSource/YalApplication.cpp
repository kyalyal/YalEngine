#include "YalApplication.h"

namespace yal
{
	Application::Application() :
		_hwnd(nullptr),
		_hdc(nullptr),
		_speed(0.f),
		_x(0.f),
		_y(0.f)
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

		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			_x -= 0.01f;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			_x += 0.01f;
		}
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			_y -= 0.01f;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			_y += 0.01f;
		}

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

		//��� ����
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255)); // ��� ����
		HBRUSH oldBrush = (HBRUSH)SelectObject(_hdc, brush); //����

		//�� ����
		HPEN redPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0)); //������ ����
		HPEN oldPen = (HPEN)SelectObject(_hdc, redPen); //����
		

		Rectangle(_hdc, 100 + _x, 100+_y, 200+_x , 200+_y ); // �׸� �׷��ֱ�


		//������
		DeleteObject(brush); // �޸𸮿� �����ʰ� ����
		SelectObject(_hdc, oldBrush); // �ٽ� �Ͼ��� ����

		//�����
		SelectObject(_hdc, oldPen);
		DeleteObject(redPen);

	}
}

