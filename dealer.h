#pragma once
// Cards - foundation for card game
// Dealer defi nition - dealer in a card game
#ifndef DEALER_H
#define DEALER_H
#include "player.h"
using namespace std;
class Dealer : public Player
{
public:
	Dealer(const string & = "Dealer");
	//creates a standard deck of 52 cards
	void Populate();
	//shuffl es cards
	void Shuffle();
	//transfers number of cards to a player
	void Deal(Player& aPlayer, int numCards = 1);
	//transfers equal number of cards to players in a group
	void Deal(vector<Player>& players, int numCardsEach = 1);
};
#endif
