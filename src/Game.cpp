#include "Game.h"
#include "Player.h"
#include "Entity.h"
#include "Level.h"
#include <string>
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
}

void Game::render(Renderer* renderer) {
	level->render(renderer);
	player->render(renderer);
}