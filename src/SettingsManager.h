#pragma once

class SettingsManager {
public:
	SettingsManager();
	~SettingsManager();
	int screenWidth;
	int screenHeight;
	int resolutionX;
	int resolutionY;
	int framerateLimit;
	bool verticalSync;
private:

};
