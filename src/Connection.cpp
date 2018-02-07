
#include "Connection.h"

Connection::Connection(sf::IpAddress ip, short port) {
  this->ipAddress = sf::IpAddress(ip);
  this->port = port;
}
