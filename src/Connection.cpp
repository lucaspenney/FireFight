
#include "Connection.h"

Connection::Connection(string ip, short port) {
  this->serverIp = sf::IpAddress(ip);
}
