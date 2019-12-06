
// --------------------------------------------------------------------------
//! The dealer class is in charge of card and chip distribution and retrieval.
// --------------------------------------------------------------------------

#pragma once

#include "player.h"
#include "deck.h"
#include <vector>
#include <memory>


class DEALER
{
public:
	DEALER();

	void draw( int number_to_draw );
	void shuffle();
	void swap();

private:
	std::unique_ptr<DECK> m_deck{ nullptr };
	std::vector<std::unique_ptr<PLAYER>> player_list;
};
