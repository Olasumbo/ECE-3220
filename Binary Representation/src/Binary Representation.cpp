//============================================================================
// Name        : Binary.cpp
// Author      : Ola
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
using namespace std;

unsigned short Arithmetic (unsigned short x , unsigned short store[]);
unsigned short Bitwise (unsigned short x , unsigned short store[]);

int main()
{
	cout << "Enter 1 for Arithmetic \nEnter 2 for Bitwise" << endl; // prints
	unsigned short num;
	int choice;
	cout << "Choice = ";
	cout << "Enter a num: ";
	cin >> num;
	unsigned short safe[16] = { 0 };
	cin >> choice;

	Arithmetic (num , safe);
	//Bitwise (num, safe);

	return 0;
}

unsigned short Arithmetic (unsigned short x , unsigned short store[])
{
	int i = 0;
	//int rem;
	while( x > 0)
	{
		store[i] = (x % 2);
		x = (x / 2);
		if(x == 0)
		{
			break;
		}
		i++;
	}
	for(i = 15; i>= 0; i--)
	{
		cout << store[i];
	}
	return 0;
}

/*unsigned short Bitwise (unsigned short x , unsigned short store[])
{
			int i;
			for(i = 0;i < 16; i++)
				store[16 - i - 1] = (x & (1 << i)) >> i; //the formula you want to see
			//printf("Your number in binary is: ");
			for(i = 0; i < 15; i++) //trim leading zeros
				if(store[i] == 1)
					break;
			for(;i<16;i++)
			{
				cout << store[i];
			}

	  return 0;
}
*/
