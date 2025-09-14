#include "Pawn.h"

void Pawn::Tick()
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		_Location._X -= 0.01f;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		_Location._X += 0.01f;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		_Location._Y -= 0.01f;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		_Location._Y += 0.01f;
	}
}

void Pawn::PostTick()
{

}

void Pawn::Render(HDC hdc)
{
	//��� ����
	HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255)); // ��� ����
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush); //����

	//�� ����
	HPEN redPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0)); //������ ����
	HPEN oldPen = (HPEN)SelectObject(hdc, redPen); //����

	Rectangle(hdc, 100 + _Location._X , 100 + _Location._Y, 200 + _Location._X, 200 + _Location._Y); // �׸� �׷��ֱ�


	//������
	DeleteObject(brush); // �޸𸮿� �����ʰ� ����
	SelectObject(hdc, oldBrush); // �ٽ� �Ͼ��� ����

	//�����
	SelectObject(hdc, oldPen);
	DeleteObject(redPen);
}
