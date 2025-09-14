#include "InputComponent.h"

static std::vector<InputComponent::Key> _Keys = {};

void InputComponent::Initalize()
{

	for (size_t i = 0; i < (UINT)EKeyCode::SIZE; i++)
	{
		Key key = {};
		key.bPressed = false;
		key.State = EKeyState::None;
		key.KeyCode = (EKeyCode)i;

		_Keys.push_back(key);
	}
}

void InputComponent::Tick()
{
}
