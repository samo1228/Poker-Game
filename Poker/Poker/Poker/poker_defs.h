
#pragma once

constexpr int PLAYER_HAND_SIZE = 5;
typedef std::array <const CARD*, PLAYER_HAND_SIZE> PLAYER_HAND;

enum class HAND_TYPE : int
{
	HIGH_CARD,
	PAIR,
	TWO_PAIR,
	THREE_OF_A_KIND,
	STRAIGHT,
	FLUSH,
	FULL_HOUSE,
	FOUR_OF_A_KIND,
	STRAIGHT_FLUSH,
	ROYAL_FLUSH
};