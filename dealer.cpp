// Cards - foundation for card game
// Dealer implementation - dealer in a card game
#include "dealer.h"
#include <iostream>
#include <algorithm>
#include "card.h"
using namespace std;
Dealer::Dealer(const string& name) :Player(name)
{
	Populate();
}
//creates a standard deck of 52 cards
void Dealer::Populate()
{
	m_Cards.clear();
	//create standard deck
	for (int s = Card::CLUBS; s <= Card::SPADES; ++s)
	{
		for (int r = Card::ACE; r <= Card::KING; ++r)
		{
			AddCard(Card(static_cast<Card::rank>(r),
				static_cast<Card::suit>(s)));
		}
	}
}

//shuffl es cards
void Dealer::Shuffle()
{
	random_shuffle(m_Cards.begin(), m_Cards.end());
}

//transfers number of cards to a player
void Dealer::Deal(Player& aPlayer, int numCards)
{
	if (static_cast<int>(m_Cards.size()) < numCards)
	{
		cout << "Not enough cards to deal." << endl;
		return;
	}
	for (int i = 0; i < numCards; ++i)
	{
		TransferCard(aPlayer);
	}
}

//transfers equal number of cards to players in a group
void Dealer::Deal(vector<Player>& players,
	int numCardsEach)

{
	if (m_Cards.size() < players.size() * numCardsEach)
	{
		cout << "Not enough cards to deal." << endl;
		return;
	}
	for (int i = 0; i < numCardsEach; ++i)
	{
		//iterate over vector, passing each element
		//to TransferCard()
		vector<Player>::iterator iter;
		for (iter = players.begin();
			iter != players.end();
			++iter)
		{
			TransferCard(*iter);
		}
	}
}