#pragma once
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <experimental/filesystem>
#include <fstream>
#include <iostream>
#include <vector>
using std::string;
using std::vector;

class AssetManager
{
public:
	AssetManager();
	~AssetManager();

	static void loadTextures();

	static std::unordered_map<std::string, sf::Texture> textures;
private:
	static vector<string> getAssetFiles(string dir);
};
