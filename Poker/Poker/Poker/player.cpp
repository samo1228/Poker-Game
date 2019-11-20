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

	bool is_flush = true; // creating a check to tell if the hand has a flush
	bool is_straight = true; //creating a check to tell if the hand has a straight

	// straight
	    // check if card is one less then the next card
	for ( auto i = 0; i < hand.size() - 1; i++ )
	{
		if ( hand[i]->get_value() != hand[i + 1]->get_value()-1 )
		{
			is_straight = false;
			break;
		}
	}

	// flush
	   // check if all five cards have the same suit
	for ( auto i = 0; i < hand.size() - 1; i++ )
	{
		if ( hand[i]->get_suit() != hand[i + 1]->get_suit() )
		{
			is_flush = false;
			break;
		}
	}

	// straight flush
   // check if 'is_flush' and 'is_straight' is true
	if ( is_flush && is_straight )
	{
		best_hand = HAND_TYPE::STRAIGHT_FLUSH;
	}
	else if ( is_flush )
	{
		best_hand = HAND_TYPE::FLUSH;
	}
	else if ( is_straight )
	{
		best_hand = HAND_TYPE::STRAIGHT;
	}




	std::cout << std::endl << "* Hand Value: *" << player_utilities::get_name_of_hand_type((HAND_TYPE)best_hand) << std::endl;

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

// --------------------------------------------------------------------------
//! Returns a readable name for the hand types
// --------------------------------------------------------------------------
std::string player_utilities::get_name_of_hand_type( const HAND_TYPE hand_type )
{
	switch ( hand_type )
	{
	case HAND_TYPE::FIVE_OF_A_KIND:
		return "Five of a kind";
	case HAND_TYPE::STRAIGHT_FLUSH:
		return "Straight Flush";
	case HAND_TYPE::FOUR_OF_A_KIND:
		return "Four Of A Kind";
	case HAND_TYPE::FULL_HOUSE:
		return "Full House";
	case HAND_TYPE::FLUSH:
		return "Flush";
	case HAND_TYPE::STRAIGHT:
		return "Straight";
	case HAND_TYPE::THREE_OF_A_KIND:
		return "Three Of A Kind";
	case HAND_TYPE::TWO_PAIR:
		return "Two Pair";
	case HAND_TYPE::ONE_PAIR:
		return "One Pair";
	case HAND_TYPE::HIGH_CARD:
		return "High Card";
	default:
		return "Nothing";
	}
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
