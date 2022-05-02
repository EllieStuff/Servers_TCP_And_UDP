#pragma once
#include "../res/IpAddress.h"
#include <time.h>

class ClientData
{
	unsigned short port;
	IpAddress address;
	std::string name;
	int clientSALT, serverSALT, clientID;
	clock_t timeStamp;

	int tries;

	void GenerateSALT(int &value, int numOfBytes);

public:
	ClientData() {}
	ClientData(unsigned short _port, IpAddress _address, std::string _name);

	bool CheckChallengeResult(int _salt);

	void SetClientID(int _id) { clientID = _id; }

	IpAddress GetAddress() { return address; }

	unsigned short GetPort() { return port; }

	std::string GetName() { return name; }
};