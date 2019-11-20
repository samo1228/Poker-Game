#include "dealer.h"
#include <iostream>

int main()
{
	bool exit = false;
	std::string exit_game_string;
	DEALER* dealer = new DEALER();
	dealer->swap();
	dealer->draw( 5 );
	

	//dealer->draw( 5 );
	//dealer->shuffle();
	//dealer->draw( 5 );
	while ( !exit )
	{
		std::cout << "Press enter to play";
		std::getline( std::cin, exit_game_string );

		if ( exit_game_string == "exit" )
		{
			exit = true;
		}
		dealer->swap();
		dealer->draw( 5 );
	}
	delete dealer;
}
