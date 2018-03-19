//============================================================================
// Name        : Lab5.cpp
// Author      : Ola
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <limits.h>
#include <vector>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Signal
{
private:
	double length;
	double Max_Num;
	double Min_Num;
	double Avg;
	vector<double> data;
	vector<double> updateddata;
	void getAverage(void);
	void getMax(void);

public:
	void offset(double x);
	void scale(double x);
	void center();
	void normalize();
	void statistics();
	void menu();
	void Sig_info();
	void Save_file(int n);

	//Constructors
	Signal():Signal(0){}; // default file
	Signal(int n); // when given just a number it opens the file
	Signal(string filename);

	// Destructor
	~Signal(){};

};

int main(int argc, char*argv[])
{
	int filenum;
	string filename;
	if(argc == 1)
	{
		Signal(0);
	}
	if (argc >= 3)
	{
		for( int i = 1; i <= argc; i++ )
		{
			if((argv[i][0] == '-') && (argv[i][1] == 'n'))
			{
				filenum = atoi(argv[2]);
				Signal input( filenum );
				cout << "File value: " << filenum << endl;
				input.menu();
				delete &input;
				break;
			}
			else if ((argv[i][0] == '-') && (argv[i][1] == 'f'))
			{
				filename = argv[2];
				Signal input(filename);
				cout << "Filename: " << filename << endl;
				input.menu();
				delete &input;
				break;
			}
		}
	}
	else
	{
		cerr << "Error! Wrong number of argument "<< endl;
	}
	cout << "Everything is done!" << endl;
	return 0;
}

void Signal::menu()
{
	int opt;
	do
	{

		cout << "Welcome to a complicated life"<< endl;
		cout << "Here is a list of things you can do, Please pick your choices appropriately"<< endl;
		cout << "\n1) Offset " << endl;
		cout << "2) Scale" << endl;
		cout << "3) Center" << endl;
		cout << "4) Normalize" << endl;
		cout << "5) Statistics" << endl;
		cout << "6) Print Signal" << endl;
		cout << "7) Save Signal" << endl;
		cout << "8) Exit" << endl;

		cout << "Select an option: " <<endl;
		cin >> opt;

		switch(opt)
		{
			case 1:
			{
				cout << "\nEnter the offset value: ";
				double val;
				cin >> val;
				offset(val);
				break;
			}
			case 2:
			{
				cout << "\nEnter the scale value: ";
				double val;
				cin >> val;
				scale(val);
				break;
			}
			case 3:
			{
				center();
				break;
			}
			case 4:
			{
				normalize();
				break;
			}
			case 5:
			{
				statistics();
				break;
			}
			case 6:
			{
				Sig_info();
				break;
			}
			case 7:
			{
				cout << "Enter a filenumber: ";
				double num;
				cin >> num;
				Save_file(num);
				//delete num;
				break;
			}
			case 8:
			{
				exit(EXIT_SUCCESS);
			}
			default:
			{
				cout << "Invalid option" << endl;
				break;
			}
		}
	}
	while(opt <= 8);
}

void Signal::offset(double x)
{
	for(int i = 0; i<length; i++)
	{
		cout << "Offset["<< i << "] -> "<< updateddata[i] << " by " << x << endl;
		updateddata[i] = updateddata[i] + x;
	}
	getAverage();
	getMax();
}

void Signal::scale(double x)
{
	for(int i = 0; i<length; i++)
	{
		cout << "Scaled[" << i << "] ->"<< updateddata[i] << " by " << x << endl;
		updateddata[i] = updateddata[i] * x;
	}
	getAverage();
	getMax();
}

void Signal::getAverage()
{
	Avg = 0;
	for(int i = 0; i<length; i++)
	{
		Avg = Avg + updateddata[i];
	}
	Avg = (Avg/(length));
}

void Signal::getMax()
{
	Max_Num = 0;
	for(int i = 0; i<length; i++)
	{
		if(updateddata[i] > Max_Num)//*(data+i) is an actual value in the vector/ or array
		{
			Max_Num = updateddata[i];
		}
	}
	//cout<<"Maxvalue is: "<< max << endl;
}

void Signal::center()
{
	getAverage();
	for(int i = 0; i<length; i++)
	{
		updateddata[i] -= Avg;
	}
	getAverage();
	getMax();
}

void Signal::statistics()
{
	cout<<"Maxvalue is: "<< Max_Num<< endl;
	cout <<"Average is: " << Avg << endl;
}

void Signal::normalize()
{
	getMax();
	for(int i = 0; i<length; i++)
	{
		updateddata[i] /= Max_Num;
	}
	getAverage();
	getMax();
}

void Signal::Sig_info()
{
	Min_Num = Max_Num;
	for(int i = 0; i<length; i++)
	{
		if( updateddata[i] < Min_Num )//*(data+i) is an actual value in the vector/ or array
		{
			Min_Num = updateddata[i];
		}
	}
	int i = 0;
	while ( i < length )
	{
		cout << "DATA[" << i << "] -> " << data[i] << " --> " << updateddata[i] << endl;
		i++;
	}
	cout << "\nSignal length: " << length << endl;
	cout << "Maximum val:" << Max_Num << endl;
	cout << "Minimum val:" << Min_Num << endl;
	cout << "Average val:" << Avg << endl;
}

void Signal::Save_file(int n)
{
	/*FILE *fp_w = fopen(filename, "w");
		if(fp_w != NULL)
		{
			fprintf(fp_w, "%lf %0.4lf\n", length, Max_Num);
			for(int i = 0; i < length; i++)
			{
				fprintf(fp_w, "%0.4lf\n", *(data+i));
			}
			fclose(fp_w);
		}*/
	string test = "Raw_data_0" + to_string(n) + ".txt";
	ofstream myfile ("Raw_data_0" + to_string(n) + ".txt");
	//myfile >> length >> Max_Num;
	//myfile.ignore( 1,'\n' );
	cout << "Length: " << length << " | Max: " << Max_Num << endl;

	if(myfile.is_open())
	{
		cerr << "Could not open file "<< endl;
	}
	int i = 0;
	string line;
	while ( i < length )
	{
		//getline( myfile, line );
		updateddata.push_back( atof( line.c_str() ) );
		cout << "Read the data for " << i << " : " << data[i] << endl;
		i++;
		myfile << updateddata[i++];
	}

	myfile.close();
}

Signal::Signal(int n) /// It reads in my file.
{

	string test = "Raw_data_0" + to_string(n) + ".txt";
	cout << test << endl;
	ifstream myfile ("Raw_data_0" + to_string(n) + ".txt");

	int i = 0;
	length = 0;

	if ( myfile.is_open() )
	{
		//cout << "I opened a file! I so cool!" << endl;
		myfile >> length >> Max_Num;
		myfile.ignore( 1,'\n' );
		cout << "Length: " << length << " | Max: " << Max_Num << endl;

		string line;
		while ( i < length )
		{
			//myfile >> test[i];
			getline( myfile, line );
			data.push_back( atof( line.c_str() ) );
			updateddata.push_back( data[i] );
			cout << "Read the data for " << i << " : " << data[i] << endl;
			i++;
		}
		myfile.close();
	}
	else
	{
		cerr << "Could not open the file "<< endl;
	}

	Avg = 0;
	Max_Num = 0;
	Min_Num = 0;
}

Signal::Signal(string filename)
{
	ifstream myfile(filename);
	int i = 0;
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			myfile >> data[i++];
		}
		myfile.close();
	}
	else
	{
		cerr << "Could not open the file "<< endl;
	}

	Avg = 0;
	Max_Num = 0;
	Min_Num = 0;
}

