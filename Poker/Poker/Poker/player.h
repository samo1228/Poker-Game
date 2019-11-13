#pragma once
#include "card.h"

const int PLAYER_HAND_SIZE = 5;

class PLAYER
{
public:
	PLAYER();
	const CARD* hand[PLAYER_HAND_SIZE];

	void print_hand();

	void reset_hand();
	void add_card( const CARD* card );
	void swap_card( int card_to_swap, const CARD* card );
	void calculate_hand();
private:

	
};