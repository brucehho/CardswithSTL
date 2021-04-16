// Cards - foundation for card game
// Player implementation - player in a card game
#include "player.h"
#include <iostream>
#include <vector>
#include "card.h"
using namespace std;

Player::Player(const string& name) :
	m_Name(name)
{}

//returns name
const string& Player::GetName() const
{
	return m_Name;
}
//displays name and all cards
void Player::Display() const
{
	cout << m_Name << ":\t";
	//if no cards, display message and end function call
	if (m_Cards.empty())
	{
		cout << "<no cards>";
	}
	//otherwise, display cards
	else
	{
		//iterate over vector, displaying each Card object
		vector<Card>::const_iterator iter;
		for (iter = m_Cards.begin();
			iter != m_Cards.end();
			++iter)
		{
			iter->Display();
			cout << "\t";
		}
	}
}

//adds a card
void Player::AddCard(const Card& aCard)
{
	//add new Card object to vector
	m_Cards.push_back(aCard);
}

//transfer card to other player
void Player::TransferCard(Player& other)
{
	if (m_Cards.empty())
	{
		cout << "Out of cards!";
		return;
	}
	//give copy of card to other player
	other.AddCard(m_Cards.back());
	//remove card from own vector
	m_Cards.pop_back();
}