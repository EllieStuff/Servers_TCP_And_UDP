#pragma once
#include <string>
#include <vector>

const int MAX_CARDS = 3;

enum class Status { DONE, NOT_READY, PARTIAL, DISCONNECTED, ERROR };

enum class Commands { CREATE_GAME = 1, GAME_LIST, JOIN_GAME, GAME_ID, INCORRECT_ID, CORRECT_PWD, INCORRECT_PWD, PWD_CHECK, PROTECTED, NOT_PROTECTED, PLAYER_READY,
	ORGAN_QUANTITY, UPDATE_TURN, END_ROUND, PLACE_ORGAN, PLACE_INFECTION, PLACE_MEDICINE, PLACE_TREATMENT, DISCARD_CARD};

struct PeerAddress {
	std::string ip;
	int port;
};

struct Game
{
	std::vector<PeerAddress> peers;

	int gameSize, gameId;
	std::string pwd = "", gameName = "";
};

struct Pair_Organ_Player
{
	int playerID, numOrgans;

	Pair_Organ_Player(int _playerID, int _numOrgans) : playerID(_playerID), numOrgans(_numOrgans)
	{

	}

	bool operator>(Pair_Organ_Player _other)
	{
		return numOrgans > _other.numOrgans;
	}

	bool operator<(Pair_Organ_Player _other)
	{
		return numOrgans < _other.numOrgans;
	}

	bool operator>=(Pair_Organ_Player _other)
	{
		return numOrgans > _other.numOrgans || (numOrgans == _other.numOrgans && playerID < _other.playerID);
	}

	bool operator<=(Pair_Organ_Player _other)
	{
		return numOrgans < _other.numOrgans || (numOrgans == _other.numOrgans && playerID < _other.playerID);
	}
};

inline bool ComparePlayers(Pair_Organ_Player _first, Pair_Organ_Player _second)
{
	return _first >= _second;
}

struct Card {
public:
	enum class CardType { ORGAN, MEDICINE, VIRUS, TREATMENT, COUNT, NONE };
	enum class OrganType { STOMACH, BRAIN, SKELETON, HEART, NONE };
	enum class TreatmentType { INFECTION, ROBER, TRANSPLANT, LATEX_GLOVES, MEDICAL_ERROR, NONE };

	CardType cardType;
	OrganType organType;
	TreatmentType treatmentType;
	bool isWildcard = false;

	Card(CardType _type, OrganType _organ, bool _isWildcard = false) 
	{
		cardType = _type;
		organType = _organ;
		isWildcard = _isWildcard;
		treatmentType = TreatmentType::NONE;
	}
	Card(TreatmentType _treatment, bool _isWildcard = false)
	{
		organType = OrganType::NONE;
		cardType = CardType::TREATMENT;
		treatmentType = _treatment;
		isWildcard = _isWildcard;
	}
};

struct VirusData {
	int playerId;
	int currTurn;
	bool hasStolen;	// Nota: passar cartes al principi de la principi
	// ToDo?
};

