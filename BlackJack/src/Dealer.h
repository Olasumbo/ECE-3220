/*
 * Dealer.h
 *
 *  Created on: Apr 5, 2018
 *      Author: obaba
 */
#include <vector>
#ifndef DEALER_H_
#define DEALER_H_

class Dealer
{
	private:
	//vector<int> hand;
	void Deal();

	public:
	void Hit();
	int CheckHand();
	void Shuffle();

};



#endif /* DEALER_H_ */
