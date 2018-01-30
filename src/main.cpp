#include "Application.h"
#include "GameServer.h"
#include <iostream>
#include <thread>


int main(int argc, char* argv[])
{
	std::string param = "";
	if (argc > 1) {
		std::string arg1(argv[1]);
		param = arg1;
	}
	//Launch server only
	if (param.compare("server") == 0) {
		std::cout << "Starting gameserver... \n";
		GameServer server;
	}
	else {
		//Run the game server locally
		std::thread serverThread(createServer);
		serverThread.detach();
		Application game;
	}
	return 0;
}
