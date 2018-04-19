/*
 * System.cpp
 *
 *  Created on: Apr 13, 2018
 *      Author: obaba
 */
#include "System.h"

System::System()
{
		num_of_players = 0;
		players = 0;
	    cout<< "Your aim is to achieve a hand where all the cards add up as close as possible but do not exceed 21.";
	    cout<< "\nAll face cards are worth 11 points. This includes jacks, queens and kings, regardless of suit.";
	    cout<< "\nAn ace is worth either 1 or 10 depending on your strategy.";
	    cout<< "\nCards 2 through 10 are their face value.";

	    cout<< "\n\nAs the dealer gains more cards, they must draw on 16 and stand on all 17's.";
	    cout<< "\nThen the player (YOU) can keep his/her hand as it is (stand) or take more cards from the";
	    cout<< "\ndeck (hit), one at a time, until either the player judges that the hand is strong";
	    cout<< "\nenough to go up against the dealer's hand and stands, or until it goes over 21, in";
	    cout<< "\nwhich case the player immediately loses (busts).";

	    cout<< "\n\nWhen all players have finished their actions, either decided to stand or busted, the dealer";
	    cout<< "\nturns over his hidden hole card. If the dealer has a natural 21 (blackjack) with his two";
	    cout<< "\ncards, he won't take any more cards. All players lose, except players who also have a";
	    cout<< "\nblackjack, in which case it is a push - the bet is returned to the player.";
	    cout<< "\nIf the dealer doesn't have a natural, he hits (takes more cards) or stands depending on the";
	    cout<< "\nvalue of the hand. Contrary to the player, though, the dealer's action is completely dictated ";
	    cout<< "\nby the rules. The dealer must hit if the value of the hand is lower than 17, otherwise the dealer ";
	    cout<< "\nwill stand.";
	    cout<< "In this game, the dealer will stand on a soft 17 (where there is an ace being counted for 11 points).";

	    cout<< "\n\nIn this game, you can take as many cards as you want until you bust.";
	    cout<< "This rule may not be the same in all playing environments.";

	    //Later add insurance, surrender, splitting and doubling down if we chose to allow gambling.
}

System::~System()
{

}
void System:: start()
{
	cout << "******Game Start!******"<<endl;
	//choice();

}


