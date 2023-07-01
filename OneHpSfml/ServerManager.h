#pragma once
#include <SFML/Network.hpp>

class ServerManager
{
public:

	void StartServer();

protected:

	sf::UdpSocket udpSocket;

	void SendMessage();

private:

};

