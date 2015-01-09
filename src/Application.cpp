#include "Application.h"
#include "Menu.h"
#include "AssetManager.h"
#include "Renderer.h"
#include "Level.h"
#include "Player.h"
#include "Game.h"

Application::Application()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);
	mRenderer = new Renderer(800, 600, &window);

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
