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
	Playersname = "Joel Abshier";

}

void Player::Deal()
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

	vector<Card> tempDeck;

	int i, x;
	for( i = 0; i < 2; i++ )
	{
		x = rand() % 52;
		move( tempDeck.begin() + x, tempDeck.begin() + x, hand.begin() );
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
		if( i.getRank() == Card::ACE )
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
	cout << " Blackjack, Hit, Stay, Double or Split ?" << endl;
	cout << "Press H to get a more card\n, Press S to Stay\n Press D to Double\n Press SP to Split" << endl;
	char c = ' ';
	cin >> c;
	/*if(c != H)
	{
		cerr <<"Invalid Input"<<endl;
	}*/
	return c;
}

void Player:: Hit() // need work
{
	//Deal 2 more cards to player or system
	Deal();
}

int Player::player_hands() // This calculate the total number of the player's hand
{
	for(auto i:hand)
	{
		card_total += i.getValue();
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

void Player::Split()// need work
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




