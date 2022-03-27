#pragma once
#include "Player.h"
#include <mutex>
#include <list>
#include "../res/InputMemoryStream.h"
#include "../res/TcpSocket.h"
#include "../res/TcpListener.h"

class TcpSocket;

class GameManager
{
	TcpListener listener;
	unsigned int localPort = 0;

	std::list<TcpSocket*>* socks = new std::list<TcpSocket*>();
	Player* player = new Player();
	Deck* deck = new Deck();
	Table* table = new Table();
	int* currentTurn = new int(0);
	bool* endRound = new bool(false);
	std::mutex mtx;
	int* gameMaxSize = new int(0);

	bool ready = false;
	int* playersReady = new int();

	std::vector<Pair_Organ_Player> playerTurnOrder;

	void UpdateTurn(bool plus);
	void ReceiveMessages(InputMemoryStream in1);
	void AcceptConnections(int* _sceneState);
	void SendReady();

public:
	GameManager() {}
	~GameManager();

	void ListEnemiesWithTheirCards();

	bool Threatment();

	bool PlaceInfection();

	bool VaccineOrgan();

	void CheckArray();

	void sendMSG(std::string message);

	void CalculateOrganQuantity();
	void ConnectP2P(TcpSocket* _serverSock, int* _sceneState);

	bool Update();
	void Start();

	void SetReady();

	void CreateGame(TcpSocket* _serverSock);
	void ListCurrentGames(TcpSocket* _serverSock);
	void JoinGame(TcpSocket* _serverSock, bool& _aborted);

	void SetPort(unsigned int _port) { localPort = _port; };
	void SetEndRound(bool _round) { *endRound = _round; }
	void SetGameSize(int _gameMaxSize) { *gameMaxSize = _gameMaxSize; }
	int GetPlayersNum() { return socks->size() + 1; };
	int GetGameSize() { return *gameMaxSize; }

	bool GetReady() { return ready; }
	int GetPlayersReady() { return *playersReady; }
};