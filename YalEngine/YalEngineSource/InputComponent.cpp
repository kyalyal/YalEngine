#include "InputComponent.h"


std::vector<InputComponent::Key> InputComponent::_Keys;


int ASCII[(UINT)EKeyCode::SIZE + 4] =
{
	'A', 'B', 'C', 'D', 'E', 'F', 'G',
	'H', 'I', 'J','K', 'L', 'M', 'N', 'O', 'P',
	'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
	VK_LEFT, VK_RIGHT,VK_DOWN, VK_UP
};


void InputComponent::Initalize()
{

	
}

void InputComponent::InitInputComponent()
{

	for (size_t i = 0; i < (UINT)EKeyCode::SIZE; i++)
	{
		Key key = {};
		key.bPressed = false;
		key.State = EKeyState::None;
		key.KeyCode = static_cast<EKeyCode>(i);

		_Keys.push_back(key);
	}
}

void InputComponent::InputComponentUpate()
{
	for (size_t i = 0; i < _Keys.size(); i++)
	{
		//Ű�� ���ȴ��� �ƴ���
		if (GetAsyncKeyState(ASCII[i]) & 0x8000)
		{
			//�̹� �����ִ� ���´�
			if (_Keys[i].bPressed == true)
			{
				_Keys[i].State = EKeyState::Pressed;
			}
			else
			{
				_Keys[i].State = EKeyState::Down;
			}

			_Keys[i].bPressed = true;
		}
		else //Ű�� �ȴ��ȴ�.
		{
			//�̹� �����ִ� ���´�
			if (_Keys[i].bPressed == true)
			{
				_Keys[i].State = EKeyState::Up;
			}
			else
			{
				_Keys[i].State = EKeyState::None;
			}

			_Keys[i].bPressed = false;
		}

	}
}

void InputComponent::Tick()
{


}


