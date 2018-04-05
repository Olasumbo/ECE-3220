//============================================================================
// Name        : Assignment_5.cpp
// Author      : Ola
// Version     :
// Copyright   : Your copyright notice
// Description : Inheritance
//============================================================================
// g++ Lab4_strings.cpp -o Lab4_strings -std=c++11

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>

using namespace std;

// --------- BaseSig class and methods ------------------------------
class BaseSig
{
	private:
		// neither derived classes nor other users
		// can access private members

	protected:	// accessible by derived classes, not by other users.
		int length;
		double Max_Num;
		vector<double> raw_data;
		void populate (int x);

	public:
		BaseSig();		// default constructor.
		BaseSig(int L);	// parametric constructor
		virtual ~BaseSig();		// virtual destructor
		int getLength() { return length; };
		int getRawValue(int pos);
		static int numObjects;	// static, only one member for the entire hierarchy
		virtual void printInfo();	// virtual function

};

int BaseSig::numObjects = 0;	// initialize static data member

// Base class constructor
BaseSig::BaseSig()
{
	length = 0;
	Max_Num = 0;
	numObjects++;
	populate (1);
}

// Base class parametric constructor
BaseSig::BaseSig(int L)
{
	Max_Num = 0;
	length = 0;
	numObjects++;
	populate (L);
}

// Base class destructor
BaseSig::~BaseSig()
{
	cout << "Goodbye, BaseSig." << endl;
}

int BaseSig::getRawValue(int pos)
{
	if(pos < 0)			// invalid index
		return(raw_data[0]);
	else if(pos >= length)	// invalid index
		return(raw_data[length-1]);
	else
		return(raw_data[pos]);
}

void BaseSig::populate (int x)
{
		ostringstream fileNumStream;
		fileNumStream << setw(2) << setfill('0') << to_string(x);
		ifstream myfile ( "Raw_data_" + fileNumStream.str() + ".txt" );

		int i = 0;
		Max_Num = 0;
		length = 0;

		if ( myfile.is_open() )
		{
			myfile >> length >> Max_Num;
			myfile.ignore( 1,'\n' );
			//cout << "Length: " << length << " | Max: " << Max_Num << endl;
			string line;
			while ( i < length )
			{
				getline( myfile, line );
				raw_data.push_back( atof( line.c_str() ) );
				//data.push_back( raw_data[i] );
				i++;
			}
			myfile.close();
		}
		else
		{
			cerr << "Could not open the file "<< endl;
		}
	}

void BaseSig::printInfo()
{
	cout << "\nLength: " << length << endl;
}
// ------------------------------------------------------------------



// --------- ProcessedSignal class and methods ----------------------------
class ProcessedSignal  : public BaseSig{ // ProcessedSignal  is derived from class BaseSig
//BaseSig is a public base class
	private:
		double average;
		vector<double> data;
		double Max_Num;
		double Min_Num;

	public:
		ProcessedSignal (int L);	//derived classes need a new constructor
		~ProcessedSignal ();

		// define new member functions
		double getValue(int pos);
		int setValue(int pos, double val);
		double getAverage();
		void getMax(void);
		void getMin(void);
		void normalize();
		double Print_Normalized();

		// redefine member function. Virtual keyword not needed
		void printInfo();	// new standard: explicit "override" keyword can be used
};

ProcessedSignal::ProcessedSignal(int L): BaseSig(L)
{
	ostringstream fileNumStream;
	fileNumStream << setw(2) << setfill('0') << to_string(L);
	ifstream myfile ( "Raw_data_" + fileNumStream.str() + ".txt" );

	int i = 0;
	average = 0;
	Max_Num = 0;
	Min_Num = 0;
	length = 0;

	if ( myfile.is_open() )
	{
		myfile >> length >> Max_Num;
		myfile.ignore( 1,'\n' );
		cout << "Length: " << length << " | Max: " << Max_Num << endl;
		string line;
		while ( i < length )
		{
			getline( myfile, line );
			data.push_back( atof( line.c_str() ) );
			raw_data.push_back( data[i] );
			cout << "Data " << i << " : " << data[i] << endl;
			i++;
		}
		myfile.close();
	}
	else
	{
		cerr << "Could not open the file "<< endl;
	}
}

ProcessedSignal::~ProcessedSignal()
{
	//delete data;
	cout << "Goodbye, ProcessedSig." << endl;
}

double ProcessedSignal::getValue(int pos)
{
	if(pos < 0)			// invalid index
		return(data[0]);
	else if(pos >= length)	// invalid index
		return(data[length-1]);
	else
		return(data[pos]);
}

int ProcessedSignal::setValue(int pos, double val) {
	if((pos < 0) || (pos >= length))
		return(-1);	// invalid index
	else {
		data[pos] = val;
		average = getAverage();
		return(0);	// success
	}
}
void ProcessedSignal::getMax()
{
	Max_Num = 0;
	for(int i = 0; i<length; i++)
	{
		if(data[i] > Max_Num)
		{
			Max_Num = data[i];
		}
	}
}

void ProcessedSignal::getMin()
{
	Min_Num = Max_Num;
	for(int i = 0; i<length; i++)
	{
		if( data[i] < Min_Num )
		{
			Min_Num = data[i];
		}
	}
}

void ProcessedSignal::normalize()
{
	getMax();
	for(int i = 0; i < length; i++)
	{
		data[i] /= Max_Num;
	}
	getAverage();
	getMax();
}

void ProcessedSignal::printInfo()
{
	cout << "\nLength: " << length << endl
		 << "Average: " << average << endl
		 << "Maximum Number: " << Max_Num << endl
		 << "Minimum Number: " << Min_Num << endl;
}

double ProcessedSignal::getAverage()
{
	average = 0;
	for(int i = 0; i<length; i++)
	{
		average = average + data[i];
	}
	average = (average/(length));

	return 0;
}

// To be able to print undated values in the vector
double ProcessedSignal::Print_Normalized()
{
	int i = 0;
	while(i < length)
	{
		cout << "Data " << i << " : " << data[i] << raw_data[i] << endl;
		i++;
	}
	return 0;
}

// Main function. A few examples
int main()
{
	int num = 0;
	cout << "Enter the number of your file\n";
	cin >> num;
	while(num < 1 || num > 4)
	{
		cerr<<"Error!, Please enter a FILE NUM between 1 and 4" <<endl;
		cin >> num;
	}
	ProcessedSignal Psig1(num);
	cout <<"Testing my functions " << endl;
	cout << "# of objects created: " << Psig1.numObjects << endl;
	cout << "Raw Value: " << Psig1.getRawValue(7) << endl;
	cout << "Set Value: "<< Psig1.setValue(7, 2.5) << endl;
	cout << "Get Value: " << Psig1.getValue(7) << endl;
	cout << "--------------------------------------------" << endl;

	Psig1.getAverage();
	Psig1.getMax();
	Psig1.getMin();
	Psig1.printInfo();
	cout << "--------------------------------------------" << endl;
	cout << endl;

	cout <<"After Normalization";
	Psig1.normalize();
	Psig1.Print_Normalized();
	Psig1.printInfo();
	cout << "--------------------------------------------" << endl;

	return 0;
}
