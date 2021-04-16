/*
Introducing the Cards Program
Th is chapter’s project, Cards, is a collection of classes that can serve
as a foundation for a card game.Th e code includes classes for cards,
players, and even dealers.While there isn’t a game presented in this
chapter, the project takes the classes for a spin, demonstrating how
they might be used in a game of cards.Take a look at Figure 13 - 1 to
see the project in action.

*/

// Cards - foundation for card game
// Main function
#include <iostream>
#include "player.h"
#include "dealer.h"
using namespace std;
int main()
{
	cout << "\tWelcome to Cards!" << endl << endl;
	//dealer
	Dealer dlr;
	dlr.Display();
	cout << endl << endl;
	//shuffl e deck
	dlr.Shuffle();
	dlr.Display();
	cout << endl << endl;
	//single player
	Player plyr("Mike");
	plyr.Display();
	cout << endl << endl;
	//deal fi ve cards to single player
	dlr.Deal(plyr, 5);
	plyr.Display();
	cout << endl << endl;
	dlr.Display();
	cout << endl << endl;
	//group of players
	vector<Player> plyrs;
	plyrs.push_back(Player("Moe"));
	plyrs.push_back(Player("Larry"));
	plyrs.push_back(Player("Curly"));
	//deal fi ve cards to each player in group
	dlr.Deal(plyrs, 5);
	vector<Player>::const_iterator iter;
	for (iter = plyrs.begin(); iter != plyrs.end(); ++iter)
	{
		iter->Display();
		cout << endl << endl;
	}
	dlr.Display();
	cout << endl << endl;
	//player returns a card to dealer
	plyr.TransferCard(dlr);
	plyr.Display();
	cout << endl << endl;
	dlr.Display();
	cout << endl << endl;
	return 0;
}