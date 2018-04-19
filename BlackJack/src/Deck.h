/*
 * Deck.h
 *
 *  Created on: Apr 10, 2018
 *      Author: obaba
 */

#include "Card.h"
#ifndef DECK_H_
#define DECK_H_


class Deck
{
	private:
		vector <Card> Deckholder;
		int num_cards;

	public:
		Deck() { };
		~Deck() { };
};





#endif /* DECK_H_ */
