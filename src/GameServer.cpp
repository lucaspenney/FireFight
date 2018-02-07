#include "GameServer.h"

GameServer::GameServer() {
	std::cout << "starting gameserver";
	mSocket = new sf::UdpSocket;
	mSocket->setBlocking(false); //Don't want to block on the socket
	// bind the socket to a port
	if (mSocket->bind(serverPort) != sf::Socket::Done)
	{
	    //Error binding to port
		std::cout << "Unable to bind socket to port" << std::endl;
	}
	while (true) {
		this->tick();
		usleep(1000 * (1000/tickRate));
	}
}

GameServer::~GameServer() {

}

void GameServer::tick() {
	//Receive new data
	sf::IpAddress sender;
	unsigned short port;
	sf::Packet receivePacket;
	if (mSocket->receive(receivePacket, sender, port)) {
		//Error
	} else {
		std::string receiveData;
		receivePacket >> receiveData;
		if (std::find_if(clients.begin(), clients.end(), [&sender](Connection& c) {
			return c.ipAddress == sender;
		}) == clients.end()) {
			clients.push_back(Connection(sender, port));
		}
		std::cout << sender << ":" << port << " said: " << receiveData << std::endl;
	}

	//Send data to clients
	for (auto con : clients) {
		sf::Packet sendPacket;
		std::string sendData = "{}";
		sendPacket << sendData;
		if (mSocket->send(sendPacket, con.ipAddress, con.port) != sf::Socket::Done) {
			//Error
		} else {

		}
	}
}

void GameServer::log(std::string str) {
	auto t = std::time(nullptr);
	auto tm = *std::localtime(&t);
	std::ofstream file;
	file.open("server.log", std::ios::app);
	file << "[" << std::put_time(&tm, "%Y-%m-%d %H-%M-%S") << "]: " << str << "\n";
	file.close();
}
