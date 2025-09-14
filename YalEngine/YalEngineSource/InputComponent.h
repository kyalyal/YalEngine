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
	

private:

	EKeyState _State;
	static std::vector<Key> _Keys;
};

