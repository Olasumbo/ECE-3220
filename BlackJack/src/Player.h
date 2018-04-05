/*
 * Player.h
 *
 *  Created on: Apr 5, 2018
 *      Author: obaba
 */
#include <vector>

#ifndef PLAYER_H_
#define PLAYER_H_

class Player
{
	private:
//	vector<int> hand;
	void Deal();

	public:
	void Hit();
	int CheckHand();
	void Stay();
	void Double();
	void Split();
	char choice();

};




#endif /* PLAYER_H_ */
