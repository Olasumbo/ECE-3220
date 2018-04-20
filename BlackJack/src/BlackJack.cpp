//============================================================================
// Name        : BlackJack.cpp
// Author      : Ola and Seth
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

#include "Card.h"
#include "Deck.h"
#include "Dealer.h"
#include "Player.h"
#include "System.h"

using namespace std;


int main()
{
	int num_player;
	cout << "" << endl; // prints 
	cout << "Welcome to Casino 3220, Lets Play some BlackJack" << endl; // prints
	//cout << "***********************GAME ON*******************************" << endl;
	cout << "Rules of the Game" << endl;
	System();
	cout << "How many Player would you like to play with today" << endl;
	cin >> num_player;
	while(num_player >= 4)
	{
		cout << "You can only play with a Maximum of 5 People including the Computer" << endl;
		cin >> num_player;
	}

    cout << "1. View rules" << endl;
	cout << "2. Play Blackjack" << endl;
	cout << "3. Go to main menu" << endl;
	return 0;


}
