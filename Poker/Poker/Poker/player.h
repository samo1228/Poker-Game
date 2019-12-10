#pragma once

#include <array>
#include "card.h"
#include "poker_defs.h"



class PLAYER
{
public:
	PLAYER();


	void print_hand();

	void reset_hand();
	void add_card( const CARD* card );
	void swap_card( int card_to_swap, const CARD* card );
	int calculate_hand();

private:
	PLAYER_HAND hand;
};

namespace player_utilities
{
	static std::string get_name_of_hand_type( HAND_TYPE hand_type );
}
