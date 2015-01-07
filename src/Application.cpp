#include "Application.h"
#include "Menu.h"
#include "AssetManager.h"
#include "Renderer.h"

Application::Application()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	mRenderer = new Renderer(800, 600, &window);

	mInputManager = new InputManager(&window);

	AssetManager assetManager; //Static class instantiation

	Menu mainMenu; //Temporary

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
