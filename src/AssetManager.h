#pragma once
#include <unordered_map>
#include <SFML/Graphics.hpp>
class AssetManager
{
public:
	AssetManager();
	~AssetManager();

	static void loadTextures();

	static std::unordered_map<std::string, sf::Texture> textures;
};

