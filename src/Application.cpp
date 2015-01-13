#include "Application.h"
#include "Menu.h"
#include "AssetManager.h"
#include "Renderer.h"
#include "Game.h"
#include "SettingsManager.h"

Application::Application()
{
	SettingsManager settings;
	sf::RenderWindow window(sf::VideoMode(settings.screenWidth, settings.screenHeight), "SFML works!");
	window.setVerticalSyncEnabled(settings.verticalSync);
	window.setFramerateLimit(settings.framerateLimit);
	mRenderer = new Renderer(settings.screenWidth, settings.screenHeight, &window);

	mInputManager = new InputManager(&window);

	AssetManager assetManager; //Static class instantiation

	Menu mainMenu; //Temporary

	Game game;
	while (window.isOpen()) {
		window.clear();
		//Perform rendering here
		window.draw(mainMenu.sprite);

		game.render(mRenderer);
		game.update();

		window.display();
		mInputManager->handleInput();
	}
}


Application::~Application()
{
}
