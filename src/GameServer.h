#include <SFML/Network.hpp>
#include <vector>
#include <unistd.h>
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <algorithm>

#include "Game.h"
#include "Connection.h"

class GameServer {
public:
	GameServer();
	~GameServer();
	const unsigned short serverPort = 27030;
	const short tickRate = 5;
	unsigned long uptime;
	std::vector<Connection> clients;
	void tick();
private:
	sf::UdpSocket* mSocket;
	void log(std::string str);
	Game game;
};

//Global function to start local game server. Should only be called once, on it's own thread
inline void createServer() {
	GameServer server;
}
