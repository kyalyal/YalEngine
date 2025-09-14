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

		//��� ����
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255)); // ��� ����
		HBRUSH oldBrush = (HBRUSH)SelectObject(_hdc, brush); //����

		//�� ����
		HPEN redPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0)); //������ ����
		HPEN oldPen = (HPEN)SelectObject(_hdc, redPen); //����
		

		Rectangle(_hdc, 100 + _speed, 100, 200 + _speed, 200); // �׸� �׷��ֱ�


		//������
		DeleteObject(brush); // �޸𸮿� �����ʰ� ����
		SelectObject(_hdc, oldBrush); // �ٽ� �Ͼ��� ����

		//�����
		SelectObject(_hdc, oldPen);
		DeleteObject(redPen);

	}
}

