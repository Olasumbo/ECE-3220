//============================================================================
// Name        : Lab.cpp
// Author      : Ola Babalola
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cout << "Lab 1B" << endl; // prints Lab 1B
	string product; // Creating a character space of 15 to store the product
	double Costprice, Sellingprice = 0; // initializing
	cout << " What are you trying to sell: ";
	cin >> product ;
	cout << " What is the Cost Price of " << product << endl;
	cin >> Costprice;
	while (Costprice <= 0)
			{
				cout << "Error, Please enter a valid price";
				cin >> Costprice;
			}

	cout << " What is the Selling Price of " << product << endl;
	cin >> Sellingprice;
	while (Sellingprice <= 0 )
		{
			cout << "Error, Please enter a valid price";
			cin >> Sellingprice;
		}

	if (Sellingprice > Costprice)
	{
		cout << "WOW,you have made some profit\n";
		cout << "This is how much profit you made -- $" << (Sellingprice -Costprice) << endl;
	}
	else
	{
		cout << "Sorry,you inquired some loss\n";
		cout << "This is how much you loss you had -- $" << (Sellingprice -Costprice) << endl;
	}
	if (Sellingprice == Costprice)
		cout << "Sorry,you made no loss nor gain" << endl;



	return 0;
}
