#include "SettingsManager.h"

#include <rapidjson/document.h>
#include <fstream>

SettingsManager::SettingsManager()
	:screenWidth(800), screenHeight(600), framerateLimit(60), verticalSync(true)
{
	//TODO: Read in settings from config file
	std::string fileContents;
	std::ifstream file("config/settings.json");
	if (file.fail()) {
		return;
	}
	std::string sBuffer;
	while (getline(file, sBuffer)) {
		fileContents.append(sBuffer);
	}
	file.close();

	rapidjson::Document jsonDoc;

	jsonDoc.Parse(fileContents.c_str());

	if (jsonDoc["screenWidth"].IsInt()) {
		screenWidth = jsonDoc["screenWidth"].GetInt();
	}
	if (jsonDoc["screenHeight"].IsInt()) {
		screenHeight = jsonDoc["screenHeight"].GetInt();
	}
	if (jsonDoc["framerateLimit"].IsInt()) {
		framerateLimit = jsonDoc["framerateLimit"].GetInt();
	}
	if (jsonDoc["verticalSync"].IsBool()) {
		verticalSync = jsonDoc["verticalSync"].GetBool();
	}
}

SettingsManager::~SettingsManager() {
	
}