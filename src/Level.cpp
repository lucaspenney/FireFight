#include "Level.h"
#include "AssetManager.h"
#include <fstream>
#include <rapidjson/document.h>

Level::Level()
{

}


Level::~Level()
{
}

void Level::render(Renderer* renderer) {
	for (std::vector<Tile*>::iterator it = tiles.begin(); it != tiles.end(); ++it) {
		Tile* tile = (*it);
		tile->render(renderer);
	}
}

void Level::update(Game* game) {

}

bool Level::loadLevelFile(std::string filePath) {
	std::string fileContents;

	std::ifstream file(filePath);
	if (file.fail()) {
		return false;
	}
	std::string s;
	while (getline(file, s)) {
		fileContents.append(s);
	}
	file.close();

	rapidjson::Document jsonDoc;

	jsonDoc.Parse(fileContents.c_str());

	width = jsonDoc["height"].GetInt();
	height = jsonDoc["width"].GetInt();

	rapidjson::Value& layers = jsonDoc["layers"];
	//First, load in the tile layers
	for (rapidjson::SizeType i = 0; i < layers.Size(); i++) {
		rapidjson::Value& data = layers[i]["data"];
		rapidjson::Value& layerName = layers[i]["name"];
		std::string name = layers[i]["name"].GetString();
		if (name.find("Tile") != std::string::npos) {
			for (rapidjson::SizeType k = 0; k < data.Size(); k++) {
				tiles.push_back(new Tile(data[k].GetInt(), (k % width)*32, (k / width)*32));
			}
		}
	}
	//Now load the collision layers, and retroactively apply solidity to tiles
	for (rapidjson::SizeType i = 0; i < layers.Size(); i++) {
		rapidjson::Value& data = layers[i]["data"];
		rapidjson::Value& layerName = layers[i]["name"];
		std::string name = layers[i]["name"].GetString();
		if (name.find("Collision") != std::string::npos) {
			for (rapidjson::SizeType k = 0; k < data.Size(); k++) {
				bool isSolid = (bool)data[k].GetInt();
				if (isSolid) {
					for (std::vector<Tile*>::iterator it = tiles.begin(); it != tiles.end(); ++it) {
						Tile* tile = (*it);
						if (tile->x == (k % width)*32 && tile->y == (k / width)*32) {
							tile->solid = true;
						}
					}
				}
			}
		}
	}
	return true;
}
