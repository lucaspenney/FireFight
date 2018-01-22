#include "Game.h"
#include "Player.h"
#include "Entity.h"
#include "Level.h"
#include <string>
#include <chrono>
#include <iostream>
Game::Game() {
	std::string s = "assets/levels/test.json";
	level = new Level();
	player = new Player();
	bool loaded = level->loadLevelFile(s);
}

Game::~Game() {

}

void Game::update() {
	level->update(this);
	player->update(this);
	for (std::vector<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it) {
		(*it)->update(this);
	}
	this->tick++;
}

void Game::render(Renderer* renderer) {
	double start = getTimeMs();
	level->render(renderer);
	player->render(renderer);
	double end = getTimeMs();
	double delta = end - start;
	if (delta < 16) {
		double diff = 16 - delta;
		usleep (1000 * diff);
	}
	double fps = (double)1000 / (double)(delta+1);
	sf::Font* f = renderer->fonts["Roboto"];
	sf::Text text("FPS: " + std::to_string(fps), *f, 14);
	text.setPosition(20,20);
	renderer->getWindow()->draw(text);
}

double Game::getTimeMs() {
	auto now = std::chrono::system_clock::now();
	auto now_ms = std::chrono::time_point_cast<std::chrono::microseconds>(now);
	auto epoch = now_ms.time_since_epoch();
	auto value = std::chrono::duration_cast<std::chrono::microseconds>(epoch);
	return (double) (value.count() / 1000.0);
}
