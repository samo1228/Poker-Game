#include "dealer.h"
#include "player.h"
#include "card.h"

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

// --------------------------------------------------------------------------
//! Constructor
// --------------------------------------------------------------------------
DEALER::DEALER()
{
	m_deck = std::make_unique<DECK>();
	m_player = std::make_unique<PLAYER>();
}

// --------------------------------------------------------------------------
//! Draw the top n cards
// --------------------------------------------------------------------------
void DEALER::draw( const int number_to_draw )
{
	int num_drawn = 0;
	while ( num_drawn < number_to_draw )
	{
		const auto card = m_deck->at( num_drawn ).get();
		m_player->add_card(card);
		num_drawn++;
	}
	m_player->calculate_hand();
	m_player->print_hand();
	m_player->reset_hand();
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
