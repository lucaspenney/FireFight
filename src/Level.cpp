#include "Level.h"
#include "Player.h"
#include "Tile.h"

#include <fstream>
#include <rapidjson/document.h>
#include <iostream>

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

	for(std::vector<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it) {
		(*it)->render(renderer);
	}
}

void Level::update() {
	for(std::vector<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it) {
		(*it)->update();
	}
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
	std::cout << fileContents;
	rapidjson::Document jsonDoc;
	
	jsonDoc.Parse(fileContents.c_str());

	width = jsonDoc["height"].GetInt();
	height = jsonDoc["width"].GetInt();
	
	rapidjson::Value& layers = jsonDoc["layers"];
	for (rapidjson::SizeType i = 0; i < layers.Size(); i++) {
		rapidjson::Value& data = layers[i]["data"];
		for (rapidjson::SizeType i = 0; i < data.Size(); i++) {

			tiles.push_back(new Tile(i / 32, i % 32));
			
			std::cout << "Creating tile at " << i % 32 << " " << i / 32 << std::endl;
		}
	}
	return true;
}
