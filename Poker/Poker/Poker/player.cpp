#include "dealer.h"
#include "card.h"
#include "player.h"

#include <map>
#include <iostream>

PLAYER::PLAYER()
{
	reset_hand();
}

void PLAYER::add_card( const CARD* card )
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
	HAND_TYPE best_hand = HAND_TYPE::HIGH_CARD;
	int first_value = 0;
	int second_value = 0;
	std::map<int, int> card_count;
	for ( auto card : hand )
	{
		auto find_ite = card_count.find( card->get_value() );
		if ( find_ite == card_count.end() )
		{
			card_count[card->get_value()] = 1;
		}
		else
		{
			find_ite->second++;
		}
	}

	const auto size_of_map = card_count.size();
	if ( size_of_map == 4 )
	{
		best_hand = HAND_TYPE::PAIR;

		for ( auto i = 0; i < hand.size() - 1; i++ )
		{
			if ( i + 1 < hand.size() && hand[i]->get_value() == hand[i + 1]->get_value() )
			{
				first_value = hand[i]->get_value();
				break;
			}
		}
	}
	else if ( size_of_map == 3 )
	{
		best_hand = HAND_TYPE::TWO_PAIR;
		for ( auto entry : card_count )
		{
			if ( entry.second == 3 )
			{
				best_hand = HAND_TYPE::THREE_OF_A_KIND;
				break;
			}
		}
		for ( auto i = hand.size() - 1; i >= 0; i-- )
		{
			if ( i - 1 >= 0 && hand[i]->get_value() == hand[i - 1]->get_value() )
			{
				if ( best_hand == HAND_TYPE::TWO_PAIR )
				{
					second_value = hand[i]->get_value();
				}
				else
				{
					first_value = hand[i]->get_value();
				}
				break;
			}
		}
	}
	else if ( size_of_map == 2 )
	{
		const auto first_entry_value = card_count.begin()->second;
		if ( first_entry_value == 1 || first_entry_value == 4 )
		{
			best_hand = HAND_TYPE::FOUR_OF_A_KIND;
		}
		else
		{
			best_hand = HAND_TYPE::FULL_HOUSE;
		}

		for ( auto i = hand.size() - 1; i >= 0; i-- )
		{
			if ( i - 1 >= 0 && hand[i]->get_value() == hand[i - 1]->get_value() )
			{
				if ( best_hand == HAND_TYPE::FULL_HOUSE )
				{
					second_value = hand[i]->get_value();
				}
				else
				{
					first_value = hand[i]->get_value();
				}
				break;
			}
		}
	}
	else if ( size_of_map == 5 )
	{
		bool is_flush = true; // creating a check to tell if the hand has a flush
		bool is_straight = true; //creating a check to tell if the hand has a straight

			// straight
		// check if card is one less then the next card
		for ( auto i = 0; i < hand.size() - 1; i++ )
		{
			if ( hand[i]->get_value() != hand[i + 1]->get_value() - 1 )
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
			// 		if ( hand.begin()->get_value() == 10 )
			// 		{
			// 			best_hand = HAND_TYPE::ROYAL_FLUSH;
			// 		}
			// 		else
			// 		{
			best_hand = HAND_TYPE::STRAIGHT_FLUSH;
			//}
		}
		else if ( is_flush )
		{
			best_hand = HAND_TYPE::FLUSH;
		}
		else if ( is_straight )
		{
			best_hand = HAND_TYPE::STRAIGHT;
		}

		first_value = hand[hand.size() - 1]->get_value();
	}




	std::cout << std::endl << "* Hand Value: *" << player_utilities::get_name_of_hand_type( (HAND_TYPE)best_hand ) << std::endl;

	return  ((int)best_hand * 1000) + first_value + second_value; // getting the best hand value and multiplying it by 1000 to get an easier value to work out. It then gets the int values in a case of a draw to work out who has the better hand
}

// --------------------------------------------------------------------------
//! Returns a readable name for the hand types
// --------------------------------------------------------------------------
std::string player_utilities::get_name_of_hand_type( const HAND_TYPE hand_type )
{
	switch ( hand_type )
	{
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
	case HAND_TYPE::PAIR:
		return "Pair";
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
		card_utilities::print_card_info( hand[i] );
	}
}

void PLAYER::reset_hand()
{
	for ( auto i = 0; i < PLAYER_HAND_SIZE; i++ )
	{
		hand[i] = nullptr;
	}
}

