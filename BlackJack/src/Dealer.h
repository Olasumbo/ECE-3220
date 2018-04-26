/*
 * Dealer.h
 *
 *  Created on: Apr 5, 2018
 *      Author: obaba
 */
#include <vector>
#include <iostream>

#include "Card.h"
using namespace std;

#ifndef DEALER_H_
#define DEALER_H_

class Dealer
{
	private:
		//vector<int> hand;
		void Deal();
		Deck mainDeck;

	public:
		Dealer() { };
		~Dealer() { };
		int dealer_hand;
		int dealer_cardtotal;
		int CheckHand();
		int CheckWin();
		void Shuffle();
};


#endif /* DEALER_H_ */
