/*
 * System.h
 *
 *  Created on: Apr 10, 2018
 *      Author: obaba
 */
#include <vector>
#include <iostream>
#include <string>
#include <Cards.h>
#include <Deck.h>
#include <Player.h>
#include <Dealer.h>

using namespace std;


#ifndef SYSTEM_H_
#define SYSTEM_H_


class System
{
private:
	Deck cards;
	Player *players;
	Dealer game_delear;
	int num_of_players;
public:
	System();
	~System();
	void start();

};


#endif /* SYSTEM_H_ */
