#include "Application.h"
#include "Menu.h"
#include "AssetManager.h"
#include "Renderer.h"
#include "Level.h"
#include "Player.h"

Application::Application()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	window.setVerticalSyncEnabled(true);
	mRenderer = new Renderer(800, 600, &window);

	mInputManager = new InputManager(&window);

	AssetManager assetManager; //Static class instantiation

	Menu mainMenu; //Temporary
	Player p;
	Level level;
	level.entities.insert(level.entities.begin(), &p);

	while (window.isOpen()) {
		window.clear();
		//Perform rendering here
		window.draw(mainMenu.sprite);
		level.render(mRenderer);
		level.update();

		window.display();
		mInputManager->handleInput();
	}
}


Application::~Application()
{
}
