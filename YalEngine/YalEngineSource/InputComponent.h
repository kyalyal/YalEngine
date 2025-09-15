#pragma once
#include "Component.h"
#include "CommonInclude.h"


enum class EKeyState
{
	Down,
	Pressed,
	Up,
	None
};


enum class EKeyCode
{
	A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, SIZE
};



class InputComponent : public Component
{

public:
	struct Key
	{
		EKeyCode KeyCode;
		EKeyState State;
		bool bPressed;
	};

	


	virtual void Initalize() override;
	virtual void Tick() override;

	static void InitInputComponent();
	static void InputComponentUpate();
	
	static bool GetKeyDown(EKeyCode code) { return _Keys[(UINT)code].State == EKeyState::Down; }
	static bool GetKeyUp(EKeyCode code) { return _Keys[(UINT)code].State == EKeyState::Up; }
	static bool GetKey(EKeyCode code) { return _Keys[(UINT)code].State == EKeyState::Pressed; }


	

private:

	

private:

	static std::vector<Key> _Keys;
};

