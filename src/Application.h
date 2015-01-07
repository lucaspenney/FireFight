#pragma once
#include "Renderer.h"
#include "InputManager.h"
class Application
{
public:
	Application();
	~Application();

private:
	Renderer* mRenderer = nullptr;
	InputManager* mInputManager = nullptr;
};

