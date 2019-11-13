#include "dealer.h"
#include "card.h"
#include "player.h"

PLAYER::PLAYER()
{
	reset_hand();
}

void PLAYER::add_card( const CARD* card)
{
	for ( auto i = 0; i < PLAYER_HAND_SIZE; i++ )
	{
		if ( hand[i] == nullptr )
		{
			hand[i] = card;
			break;
		}
		
    }
}

void PLAYER::swap_card( int card_to_swap, const CARD* card )
{
	if ( card_to_swap < PLAYER_HAND_SIZE )
	{
		hand[card_to_swap] = card;
	}
}

void PLAYER::calculate_hand()
{

}

void PLAYER::print_hand()
{
	for ( auto i = 0; i < PLAYER_HAND_SIZE; i++ )
	{
		card_utilities::print_card_info( hand[i]);
	}
}

void PLAYER::reset_hand()
{
	for ( auto i = 0; i < PLAYER_HAND_SIZE; i++ )
	{
		hand[i] = nullptr;
	}
}