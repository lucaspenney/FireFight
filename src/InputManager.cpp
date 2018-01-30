#include "InputManager.h"
#include <SFML/Window.hpp>

InputManager::InputManager(sf::RenderWindow* window) {
	mRenderWindow = window;
}


InputManager::~InputManager() {
}


void InputManager::handleInput() {
	sf::Event event;
	while (mRenderWindow->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			mRenderWindow->close();
		}
	}
}
