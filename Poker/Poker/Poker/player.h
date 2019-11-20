#pragma once
#include "card.h"
#include <array>

constexpr int PLAYER_HAND_SIZE = 5;

enum HAND_TYPE : int
{
	FIVE_OF_A_KIND = 1,
	STRAIGHT_FLUSH = 2,
	FOUR_OF_A_KIND = 4,
	FULL_HOUSE = 8,
	FLUSH = 16,
	STRAIGHT = 32,
	THREE_OF_A_KIND = 64,
	TWO_PAIR = 128,
	ONE_PAIR = 256,
	HIGH_CARD = 512
};
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
    std::array <const CARD*, PLAYER_HAND_SIZE> hand;
};
