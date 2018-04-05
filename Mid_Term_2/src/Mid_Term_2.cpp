//============================================================================
// Name        : Mid_Term_2.cpp
// Author      : Ola
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	int a[2] = {5,6};
	double *b = new double[2];
	vector<int> c{1,3};
	string d("ECE");

	b[0] = 0.5*c.at(0);
	b[1] = 0.5*c.at(1);

	for(auto i = 0; i < 2; i++){
		cout << (a+i) << ", " << a[i] << ", " << *(a+i) << endl;
		cout << (b+i) << ", " << b[i] << ", " << *(b+i) << endl;
	}

	for(auto i : c){
		cout << i << endl;
	}

	for(auto i : d){
		cout << i << endl;
	}
	cout << "Size of String in d:= " << d.size() << endl;
	c.push_back(8);
	for(auto i : c)
	{
			cout <<"Element in Vector c:=" << i << endl;
	}
	free(b);
}
