#pragma once
#include "../res/UdpSocket.h"

class GameManager
{

public:
	unsigned short port;
	IpAddress address;
	std::string userName;
	UdpSocket sock;
	GameManager();
	GameManager(std::string _address, unsigned short _port);
	~GameManager();

	void Update();
};