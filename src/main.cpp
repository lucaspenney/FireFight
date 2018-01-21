#include "Application.h"
#include "GameServer.h"
#include <iostream>
#include <thread>
#include <boost/program_options.hpp>


int main(int argc, char* argv[])
{
	if (argc > 1) {
		std::string arg1(argv[1]);
		std::cout << arg1;
	}



	//Launch server only
	if (false) {

	}
	else {
		//Run the game server locally
		std::thread serverThread(createServer);
		serverThread.detach();
	}
	Application game;
	return 0;
}
