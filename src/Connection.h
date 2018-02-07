#include <SFML/Network.hpp>
#include <string>


class Connection {
public:
	Connection(sf::IpAddress ip, short port);
	sf::IpAddress ipAddress;
	unsigned short port;
};
