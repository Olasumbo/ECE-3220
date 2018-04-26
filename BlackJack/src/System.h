/*
 * System.h
 *
 *  Created on: Apr 10, 2018
 *      Author: obaba
 */
#include <vector>
#include <iostream>
#include <string>

#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Dealer.h"

using namespace std;


#ifndef SYSTEM_H_
#define SYSTEM_H_


class System : public Player
{
private:
	/*Deck cards;
	Player *players;
	Dealer game_delear;
	int num_of_players;*/

public:
	System();
	~System();
	char choice();

	void start();

};


#endif /* SYSTEM_H_ */
