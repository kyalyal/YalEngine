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
	//배경 선택
	HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255)); // 배경 변경
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush); //선택

	//펜 선택
	HPEN redPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0)); //빨간펜 변경
	HPEN oldPen = (HPEN)SelectObject(hdc, redPen); //선택

	Rectangle(hdc, 100 + _Location._X , 100 + _Location._Y, 200 + _Location._X, 200 + _Location._Y); // 네모 그려주기


	//배경삭제
	DeleteObject(brush); // 메모리에 남지않게 삭제
	SelectObject(hdc, oldBrush); // 다시 하얀배경 선택

	//펜삭제
	SelectObject(hdc, oldPen);
	DeleteObject(redPen);
}
