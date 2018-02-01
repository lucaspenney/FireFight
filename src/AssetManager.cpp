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
	string path = "sprites/";
	vector<string> files = AssetManager::getAssetFiles(path);
	for (string f : files) {
		string name = f.substr(path.length());
		name = name.substr(0,name.length() - 4); //TODO: This hardcodes 3-char file extensions
		sf::Texture texture;
		if (texture.loadFromFile(f)) {
			AssetManager::textures[name] = texture;
		}
	}
}

vector<string> AssetManager::getAssetFiles(string dir) {
	namespace stdfs = std::experimental::filesystem;

	vector<string> filenames;

	// http://en.cppreference.com/w/cpp/experimental/fs/directory_iterator
	const stdfs::directory_iterator end{};

	for(stdfs::directory_iterator iter{dir}; iter != end; ++iter)
	{
			// http://en.cppreference.com/w/cpp/experimental/fs/is_regular_file
			if(stdfs::is_regular_file(*iter)) // comment out if all names (names of directories tc.) are required
					filenames.push_back(iter->path().string()) ;
	}

	return filenames ;
}
