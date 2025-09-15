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
		//키가 눌렸는지 아닌지
		if (GetAsyncKeyState(ASCII[i]) & 0x8000)
		{
			//이미 눌려있는 상태다
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
		else //키가 안눌렸다.
		{
			//이미 눌려있는 상태다
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


