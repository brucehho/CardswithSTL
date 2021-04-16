// Cards - foundation for card game
// Card defi nition - playing card
#ifndef CARD_H
#define CARD_H
class Card
{
public:
	enum rank {
		ACE, TWO, THREE, FOUR,
		FIVE, SIX, SEVEN, EIGHT,
		NINE, TEN, JACK, QUEEN, KING
	};
	enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };
	Card(rank r = ACE, suit s = SPADES);
	//returns rank
	rank GetRank() const;
	//returns suit
	suit GetSuit() const;
	//displays card
	void Display() const;
protected:
	rank m_Rank; //rank
	suit m_Suit; //suit
};
#endif