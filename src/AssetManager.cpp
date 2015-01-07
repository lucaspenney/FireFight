#include "AssetManager.h"
std::unordered_map<std::string, sf::Texture> AssetManager::textures;
AssetManager::AssetManager()
{
	AssetManager::loadTextures();
}


AssetManager::~AssetManager()
{
}


void AssetManager::loadTextures() {
	//TODO: Loop through the sprites directory instead of manually specifying
	sf::Texture texture;
	if (texture.loadFromFile("sprites/fire_extinguisher.png")) {
		AssetManager::textures["fire_extinguisher"] = texture;
	}
}