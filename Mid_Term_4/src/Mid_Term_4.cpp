//============================================================================
// Name        : Mid_Term_4.cpp
// Author      : Ola
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class MidTerm{
	private:
		int *x;
		int n;
	public:
		MidTerm();
		MidTerm(int);
		~MidTerm();

};

MidTerm::MidTerm()
{
	x = new int;
	x = NULL;
	n = 0;
	cout << "Msg1" << endl;
}

MidTerm::MidTerm(int L)
{
	x = (int *) malloc( L * sizeof(int) );
	cout << "Msg2" << endl;
}

MidTerm::~MidTerm()
{
	delete x;
	cout << "Msg3" << endl;
}

int main(){
	MidTerm obj1(5), obj2;
	MidTerm *obj3 = new MidTerm(2);

	cout << "A" << endl;
	{
		MidTerm obj4;
	}
	cout << "B" << endl;
	delete obj3;
	cout << "C" << endl;
	//cout << obj1.n << endl;
	return 0;
}
