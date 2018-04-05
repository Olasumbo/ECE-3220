//============================================================================
// Name        : Mid_Term_3.cpp
// Author      : Ola
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int x = 5;
int fun(int y){
	x += y;
	return x;
}
int main(){
	int a = 10, z = 10;
	int &b = a;
	const int &c = a;
	int *d = &a;
	int *const e = &a;

	z = fun(a);
	cout << x << endl;
	cout << a << endl;
	cout << ++a << endl;
	cout << b << endl;
	cout << ++b << endl;
	cout << c << endl;
	//cout << ++c << endl;
	cout << d << endl;
	cout << ++d << endl;
	cout << e << endl;
	cout << *e << endl;
	cout << e+1 << endl;
	//e++;
	return 0;
}

