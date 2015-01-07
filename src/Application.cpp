#include "Application.h"
#include "Menu.h"
#include "AssetManager.h"

Application::Application()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	mRenderer = &Renderer(800, 600, &window);

	mInputManager = &InputManager(&window);

	AssetManager assetManager;

	Menu mainMenu;

	while (window.isOpen()) {
		window.clear();
		//Perform rendering here
		window.draw(mainMenu.sprite);

		window.display();
		mInputManager->handleInput();
	}
}


Application::~Application()
{
}
