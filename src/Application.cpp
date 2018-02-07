#include "Application.h"
#include "Menu.h"
#include "AssetManager.h"
#include "Renderer.h"
#include "Game.h"
#include "Client.h"
#include "SettingsManager.h"
#include <iostream>
Application::Application()
{
	AssetManager assetManager; //Static class instantiation
	SettingsManager settings; //Static class
	sf::RenderWindow window(sf::VideoMode(settings.screenWidth, settings.screenHeight), "firefight", sf::Style::Default);

	window.setVerticalSyncEnabled(settings.verticalSync);
	window.setFramerateLimit(settings.framerateLimit);

	mRenderer = new Renderer(settings.screenWidth, settings.screenHeight, settings.resolutionX, settings.resolutionY, &window);
	mInputManager = new InputManager(&window);

	Menu mainMenu; //Temporary

	Client client;
	client.connect();
	while (window.isOpen()) {
		window.clear();
		//Perform rendering here
		window.draw(mainMenu.sprite);

		client.game.render(mRenderer);
		client.game.update();
		client.update();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			window.close();
			else if (event.type == sf::Event::Resized)
			{
				window.setSize(sf::Vector2<unsigned int>(event.size.width, event.size.height));
				mRenderer->setWindowSize(event.size.width, event.size.height);
			}
		}

		window.display();
		mInputManager->handleInput();
	}
}


Application::~Application()
{
}
