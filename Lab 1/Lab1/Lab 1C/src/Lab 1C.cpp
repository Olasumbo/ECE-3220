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
	cout << "Welcome to simple calculator" << endl;
	cout << "What Operator will you like to invoke" << endl;
	char choice;
	double x, y = 0;
	cout << "Enter A- Addition, S-Subtraction, M- Multiplication, D- Division " << endl;
	cin >> choice;

	switch(choice)
	{
		case 'A':
		{
			cout << "What are the two operands you would like to add" << endl;
			cin >> x >> y;
			cout << x << " " <<"+" << " " << y << " " << "is" << " " << (x + y);
			break;
		}
		case 'S':
		{
			cout << "What are the two operands you would like to subtract" << endl;
			cin >> x >> y;
			cout << x << " " <<"-" << " " << y << " " << "is" << " " << (x - y);
			break;
		}
		case 'M':
		{
			cout << "What are the two operands you would like to multiply" << endl;
			cin >> x >> y;
			cout << x << " " <<"*" << " " << y << " " << "is" << " "  << (x * y);
			break;
		}
		case 'D':
		{
			cout << "What are the two operands you would like divide" << endl;
			cin >> x >> y;
			if (y == 0 )
				{
					cout << "Cannot divide by zero";
				}
			else
				{
				cout << x << " " <<"/" << " " << y << " " << "is" << " " << (x / y);
				}
			break;
		}
		default:
		{
			cout << "Error! Operator does not exist in this program";
			break;
		}
	}

return 0;
}
