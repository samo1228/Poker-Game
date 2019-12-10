
#include "dealer.h"

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>


const int number_of_players = 5;
// --------------------------------------------------------------------------
//! Constructor
// --------------------------------------------------------------------------
DEALER::DEALER()
{
	m_deck = std::make_unique<DECK>();
	
	for ( auto i = 0; i < number_of_players; i++)
	{
		auto player = std::make_unique<PLAYER>();
		player_list.push_back( std::move(player) );
	}
}

// --------------------------------------------------------------------------
//! Draw the top n cards
// --------------------------------------------------------------------------
void DEALER::draw( const int number_to_draw )
{
	int num_drawn = 0;
	while ( num_drawn < number_to_draw )
	{
		for ( auto i = 0; i < number_of_players; i++ )
		{
			const auto card = m_deck->at(num_drawn + (i * 5)).get();
			player_list[i]->add_card( card );
		}
		num_drawn++;
	}

	int winning_player;
	int best_hand = -1;

	for ( auto i = 0; i < number_of_players; i++ )
	{
		auto hand = player_list[i]->calculate_hand();
		player_list[i]->print_hand();

		if (hand > best_hand )
		{
			best_hand= hand;
			winning_player = i;
		}
	}

	std::cout << std::endl << "* Player " << ( winning_player + 1 ) << " wins" << std::endl;


	for ( auto i = 0; i < number_of_players; i++ )
	{
		player_list[i]->reset_hand();
	}

}

// --------------------------------------------------------------------------
//! Takes our deck and mixes it up
// --------------------------------------------------------------------------
void DEALER::shuffle()
{
	std::cout << std::endl << "* Shuffle *" << std::endl;
	std::random_device seed;
	std::shuffle( m_deck->begin(), m_deck->end(), seed );
}

void DEALER::swap()
{
	shuffle();
	
// 	//TODO ADD USER INPUT FOR SWAPPING CARDS LIKE WEST HAM EXAMPLE
// 	int hand_index_to_swap = 0;
// 	const auto card = m_deck->at( 0 ).get();
// 	m_player->swap_card(hand_index_to_swap, card);
	//m_player->print_hand();
}
