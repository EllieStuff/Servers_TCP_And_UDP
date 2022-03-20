#include "Deck.h"
#include <time.h>
#include <algorithm>

Deck::Deck()
{
	Card* newCard;
	//Organ
	for (size_t i = 0; i < 5; i++)
	{
		//Heart
		newCard = new Card(Card::CardType::ORGAN, Card::OrganType::HEART);
		deck.push_back(newCard);
		//Stomach
		newCard = new Card(Card::CardType::ORGAN, Card::OrganType::STOMACH);
		deck.push_back(newCard);
		//Brain
		newCard = new Card(Card::CardType::ORGAN, Card::OrganType::BRAIN);
		deck.push_back(newCard);
		//Skeleton
		newCard = new Card(Card::CardType::ORGAN, Card::OrganType::SKELETON);
		deck.push_back(newCard);
	}
	newCard = new Card(Card::CardType::ORGAN, Card::OrganType::NONE, true);
	deck.push_back(newCard);

	//Virus
	for (size_t i = 0; i < 4; i++)
	{
		//Heart
		newCard = new Card(Card::CardType::VIRUS, Card::OrganType::HEART);
		deck.push_back(newCard);
		//Stomach
		newCard = new Card(Card::CardType::VIRUS, Card::OrganType::STOMACH);
		deck.push_back(newCard);
		//Brain
		newCard = new Card(Card::CardType::VIRUS, Card::OrganType::BRAIN);
		deck.push_back(newCard);
		//Skeleton
		newCard = new Card(Card::CardType::VIRUS, Card::OrganType::SKELETON);
		deck.push_back(newCard);
	}
	newCard = new Card(Card::CardType::VIRUS, Card::OrganType::NONE, true);
	deck.push_back(newCard);

	//Medicine
	for (size_t i = 0; i < 4; i++)
	{
		//Heart
		newCard = new Card(Card::CardType::MEDICINE, Card::OrganType::HEART);
		deck.push_back(newCard);
		//Stomach
		newCard = new Card(Card::CardType::MEDICINE, Card::OrganType::STOMACH);
		deck.push_back(newCard);
		//Brain
		newCard = new Card(Card::CardType::MEDICINE, Card::OrganType::BRAIN);
		deck.push_back(newCard);
		//Skeleton
		newCard = new Card(Card::CardType::MEDICINE, Card::OrganType::SKELETON);
		deck.push_back(newCard);
		//Wildcard
		newCard = new Card(Card::CardType::MEDICINE, Card::OrganType::NONE, true);
		deck.push_back(newCard);
	}

	//Infection
	for (size_t i = 0; i < 2; i++)
	{
		newCard = new Card(Card::TreatmentType::INFECTION);
		deck.push_back(newCard);
	}

	for (size_t i = 0; i < 3; i++)
	{
		//Rober
		newCard = new Card(Card::TreatmentType::ROBER);
		deck.push_back(newCard);
		//Transplant
		newCard = new Card(Card::TreatmentType::TRANSPLANT);
		deck.push_back(newCard);
	}
	//Latex Gloves
	newCard = new Card(Card::TreatmentType::LATEX_GLOVES);
	deck.push_back(newCard);
	//Medical Error
	newCard = new Card(Card::TreatmentType::MEDICAL_ERROR);
	deck.push_back(newCard);

	srand((unsigned int)time(NULL));
	std::random_shuffle(deck.begin(), deck.end());
}

Deck::~Deck()
{
	for (size_t i = 0; i < deck.size(); i++)
	{
		delete deck[i];
	}

	deck.clear();
}