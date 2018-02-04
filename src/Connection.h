#include <SFML/Network.hpp>
#include <string>
using std::string;

class Connection {
  Connection(string ip, short port);
  sf::IpAddress serverIp;
  
};
