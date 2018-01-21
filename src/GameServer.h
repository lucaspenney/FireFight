
#include <SFML/Network.hpp>
#include <vector>
#include <unistd.h>
class GameServer {
public:
	GameServer();
	~GameServer();
	const unsigned short serverPort = 27030;
	unsigned long uptime;
	std::vector<sf::IpAddress> clients;
	void tick();
private:
	sf::UdpSocket* mSocket;
};

//Global function to start local game server. Should only be called once, on it's own thread
inline void createServer() {
	GameServer server;
}
