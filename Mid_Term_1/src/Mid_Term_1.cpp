//============================================================================
// Name        : Mid_Term_1.cpp
// Author      : Ola
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int x = 2;

int f_one(int &y){
	int x = 1;
	y++;
	x = x + y;
	return x;
}

void f_two(int *p){
	*p = 1;
	x += 7;

}

int main(void){
	int a;
	x = 3;
	a = f_one(x);
	cout << x << ", " << a << endl;
	a = f_one(x);
	cout << x << ", " << a << endl;
	f_two(&x);
	cout << x << endl;
	return 0;
}
