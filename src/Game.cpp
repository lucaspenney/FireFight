#include "Game.h"
#include <string>
Game::Game() {
	std::string s = "assets/levels/test.json";
	bool loaded = level.loadLevelFile(s);
}

Game::~Game() {

}

void Game::update() {
	level.update();
	player.update();
}

void Game::render(Renderer* renderer) {
	level.render(renderer);
	player.render(renderer);
}