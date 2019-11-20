#include "dealer.h"
#include "card.h"
#include "player.h"
#include <iostream>

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

bool compare_name_func( const CARD* a, const CARD* b ) 
{
	return a->get_value() < b->get_value();
}

int PLAYER::calculate_hand()
{
	std::sort( hand.begin(), hand.end(), compare_name_func );
	int best_hand = 0;
	int first_pair_value = 0;
	int second_pair_value = 0;
	int first_triple_value = 0;

	//triple
	//check if there is a triple
	for ( auto i = 0; i < hand.size() - 1; i++ )
	{
		if ( hand[i]->get_value() == hand[i + 1]->get_value() && (i + 2 < hand.size() && hand[i]->get_value() == hand[i + 2]->get_value()) )
		{
			best_hand = HAND_TYPE::THREE_OF_A_KIND;
			first_triple_value = hand[i]->get_value();
			break;
		}
	}
	//Pair
			//check if two cards match
	for ( auto i = 0; i < hand.size() - 1; i++ )
	{
		if ( hand[i]->get_value() != first_triple_value && hand[i]->get_value() == hand[i+1]->get_value() &&  ( i + 2 >= hand.size() || hand[i]->get_value() != hand[i+2]->get_value() ) )
		{
			if ( best_hand == HAND_TYPE::THREE_OF_A_KIND )
			{
				best_hand = HAND_TYPE::FULL_HOUSE;
			}
			else
			{
				best_hand = HAND_TYPE::ONE_PAIR;
			}
			first_pair_value = hand[i]->get_value();

			break;
		}
	}
	// two pair
			//check if two sets of two card match
	if ( best_hand == HAND_TYPE::ONE_PAIR )
	{
		for ( auto i = 0; i < hand.size() - 1; i++ )
		{
			if ( hand[i]->get_value() != first_pair_value && hand[i]->get_value() == hand[i + 1]->get_value() && (i+2 >= hand.size() || hand[i]->get_value() != hand[i + 2]->get_value()) )
			{
				best_hand = HAND_TYPE::TWO_PAIR;
				second_pair_value = hand[i]->get_value();
				break;
			}
		}
	}



	std::cout << std::endl << "* Hand Value: *" << best_hand << std::endl;

	//check if have five of a kind
	   //loop through five cards check if all the same value
	//check if have straight flush
	    //look through all cards 
			// - check if same suit
			// check if numbers all together
	//check if have 4 of a kind

	//full house
	return 0;
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
