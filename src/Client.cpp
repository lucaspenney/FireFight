#include "Client.h"

Client::Client() {
    server = "127.0.0.1";
}

void Client::connect() {
    socket.setBlocking(false);
    if (socket.bind(clientPort) != sf::Socket::Done) {
        //Error connecting to socket
    }
}

void Client::update() {
    std::string sendData = "{}";
    sf::Packet sendPacket;
    sendPacket << sendData;
    if (socket.send(sendPacket, server, serverPort) != sf::Socket::Done) {
        //Error
    } else {

    }

    sf::Packet receivePacket;
    sf::IpAddress sender;
    unsigned short receivedPort;
    if (socket.receive(receivePacket, sender, receivedPort)) {
        //Error
    } else {
        std::string receiveData;
        receivePacket >> receiveData;
    }
}
