#pragma once
#include "Game.h"
#include <iostream>
#include <SFML/Network.hpp>

class Client {
public:
	Client();
	Game game;
	sf::IpAddress server;
	unsigned short clientPort = 27031;
	unsigned short serverPort = 27030;
	sf::UdpSocket socket;

	void connect();
	void update();
};
