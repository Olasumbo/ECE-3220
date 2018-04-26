/*
 * Player.cpp
 *
 *  Created on: Apr 13, 2018
 *      Author: obaba
 */

#include "Player.h"

Player::Player()
{
	players_total = 0;
	card_total = 0;
	bet = 0;
	bank = 1000;
	Playersname = " ";

}

void Player::Deal( Deck theDeck )
{
	cerr << "Dealing Cards ......\n";

	/*
	 *
	 * Alrighty, so there's just a bit of logic to work out here. Right now, this is what's happening:
	 * 	You've created a loop that will run 52 times (for every card in the Deck).
	 *
	 * What you want is like what you told me the other day:
	 * 	1. Load all the cards into Deck
	 * 	2. Randomly select 2 cards, the easiest way to do that is going to be just generating a random number between 0-51.
	 *
	 */

	//vector<Card> tempDeck;
	int i, x;
	for( i = 0; i < 2; i++ )
	{
		x = rand() % 52;
		move( theDeck.getDeck().begin() + x, theDeck.getDeck().begin() + x, hand.begin() );
	}

	/*(for(auto i: Deck::Card)
	{
		hand.push_back(i);
		hand.push_back(i);
		Deck::Card.pop_back(); //I am not sure if this is write at all but what am tring to do is to deal to cards into the players hands,
		Deck::Card.popback(); // then pop those cards off the total card vector
	}*/

}

void Player::initBet()
{
	bet = 0;
	if(bank == 0)
	{
		cout << "You have no money in your account." << endl;
	}

	do
	{
		cout << setprecision(3) << "Current balance For " << Playersname << " is " << bank << endl;
		cout<<"How much would you like to bet? Enter amount now: ";
		cin >> bet;
		cin.clear();
		if(bet == 0)
		{
			cout << "You must bet to play" << endl;
		}
		else if(bet > bank)
		{
			cout << "You cannot bet more money than you have" << endl;
			bet = 0;
		}
	} while(bet == 0);
}

int Player::cansplit()
{
	int count = 0;

	for( auto i:hand )
	{
		if( i.getRank() == Card::TEN )
		{
			count++;
		}
		if( i.getRank() == Card::KING )
		{
			count++;
		}
		if( i.getRank() == Card::QUEEN)
		{
			count++;
		}
		if( i.getRank() == Card::JACK )
		{
			count++;
		}
	}

	if ( count == 2 )
	{
		cout << "Split Accepted" << endl;
		Split();

	}
	else
	{
		cout << "Sorry, You cannot Split your Hand" << endl;
	}
	return 0;
}

char Player::choice()
{
	cout << " Hit, Stay, Double, Split or Exit ?" << endl;
	cout << "Press H to get a card\n, Press S to Stay\n Press D to Double\n Press P to Split\n E for Exit" << endl;
	char c = ' ';
	cin >> c;
	switch(c)
	{
	case 'H':
	case 'h':
	{
		Hit(theDeck); // I need to pass players
		break;
	}
	case 'S':
	case 's':
	{
		Stay();
		break;
	}
	case 'D':
	case 'd':
	{
		Double();
		break;
	}
	case 'P':
	case 'p':
	{
		cansplit();
		break;
	}
	case 'E':
	case 'e':
	{
				exit(EXIT_SUCCESS);
				break;
	}
	default:
			cout << "Invalid Selection. Please try Again." << endl;
	}
	return 0;
}

void Player:: Hit( Deck theDeck ) // need work
{
	//Deal 1 card at a time to player or system
	int x;
	x = rand() % 52;
	move( theDeck.getDeck().begin() + x, theDeck.getDeck().begin() + x, hand.begin() );
}

int Player::player_hands() // This calculate the total number of the player's hand
{
	for(auto i:hand)
	{
		cout << " players hand is" << endl;
		i.printCard();
		card_total += i.getValue();
		cout << " players hand total = "<< card_total << endl;
	}
	if(card_total > 21)
	{
		for(auto i:hand)
		{
			if( i.getRank() == Card::TEN )
			{
				i.setRank( Card::ACE );
			}
			else
			{
				return 0;
			}
		}
	}
	return 0;
}

int Player::CheckWin()//This is where the win, lose or busted will take place
{
	// Check to see if player or system hand is 21
	if(dealer_cardtotal > 21)
	{										//Dealer bust conditions
		cout << "Dealer Busts with " << dealer_cardtotal << endl;
		if(card_total > 21)
		{
			cout << Playersname <<" Busts with " << card_total << endl;
			cout << "Dealer Wins Over " << Playersname << endl;
			bank -= bet;
		}
		else
		{
			cout << Playersname << " Wins" << endl;
			bank += bet;
			if(card_total == 21)
			{
				bank +=(bet/2);
			}
		}
	}
	else if(dealer_cardtotal == 21)
	{									//Dealer 21 conditions
		if(card_total > 21)
		{
			cout << Playersname << " Busts with " << card_total << endl;
			cout << "Dealer Wins Over " << Playersname << endl;
			bank -= bet;
		}
		else if(card_total == 21)
		{
			cout << "BLACKJACK " << Playersname << endl;
		}
		else
		{
			cout << "Dealer Wins Over " << Playersname << endl;
			bank -= bet;
		}
	}
	else
	{													//Dealer under 21 Conditions
		if(card_total > 21)
		{
			cout << Playersname << " Busts with " << card_total << endl;
			cout << "Dealer Wins Over " << Playersname << endl;
			bank -= bet;
		}
		else if(card_total > dealer_cardtotal)
		{
			cout << Playersname << " Wins with " << card_total << endl;
			bank += bet;
			if(card_total == 21)
			{
				bank +=(bet/2);
			}
		}
		else if(card_total == dealer_cardtotal)
		{
			cout << "Push at " << card_total << " For " << Playersname << endl;
		}
		else
		{
			cout << "Dealer Wins with " << dealer_cardtotal << " Over " << Playersname << endl;
			bank -= bet;
		}
	}
	return 0;
}
void Player:: Stay()
{
	//do nothing
}
void Player:: Double()
{
	//Double at anytime
	if(bet > 500)
	{
		cout<<"You cannot double you bet because you don't have enough fund" << endl;
	}
	else
	{
		bet = ( bet * 2 );
	}
}

void Player::Split()
{
	//If player_hand has an Ace and a JACK/Queen/King then they can split into two
	vector<Card> splithand;
	for(auto i = hand.begin(); i != hand.end();)
	{
		for(auto c: hand)//hand should only have 2 cards
		{
			splithand.push_back(c);
		}
		hand.erase(i);
	}

	// when we deal in this scenerio, we have to hit into both hand and split hand.
}

void Player::Rule()
{
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
	cout<< "In this game, the dealer will stand on a soft 17 (where there is an ace being counted for 10 points).";

	cout<< "\n\nIn this game, you can take as many cards as you want until you bust.";
	cout<< "This rule may not be the same in all playing environments.";

	//splitting and doubling down if we chose to allow gambling.
}




