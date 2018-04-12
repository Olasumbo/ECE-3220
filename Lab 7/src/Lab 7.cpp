//============================================================================
// Name        : Lab7.cpp
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
#include <vector>
#include <iomanip>

using namespace std;

string Letters = "abcdefghijklmnopqrstuvwxyz";
string mCode[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };


class Message
{
protected:
	//vector< string > Store;
	string message;

public:
	Message(); //The empty constructor prompt user for the message
	Message(string mssg); // The parametric constructor takes in the message when the object is
	//declared/allocated and initialized.
	virtual ~Message(); // To free any memory
	virtual void Print();
};

//********************* MESSAGE CLASS *************************
Message::Message()
{
	cout << "Enter a message" << endl;
	getline( cin, message );
}

Message::Message(string mssg)
{
	/*getline(cin, mssg);
	mssg = message;*/
	//*** I don't think the lines above make sense. For this constructor you want to create a new Message object with the message given in the constructor.
	message = mssg;
}

Message::~Message()
{
	cout << "Goodbye Message - No Memory Allocated" << endl;
}

void Message::Print()
{
	cout << "The untranslated string is " << message << endl;
}
//********************* MESSAGE CLASS DONE *************************

//********************* MORSE CODE *************************
class MorseCode : public Message
{
private:
	string Translate;

public:
	void Print(); // Overrides Virtual Print
	void Translatemssg(); // translate input message into Morse code (called during initialization)
	MorseCode();
	MorseCode( string mssg );
	~MorseCode();
};

MorseCode::MorseCode()
{
	//Translate = new string( message.length(), ' ' );
	Translatemssg();
}


MorseCode::MorseCode( string mssg ) : Message(mssg)
{
	// message = mssg;
	//cout << endl << "Morse Code Constructor" << endl;
	cout << message << endl;
	//Translate = new string( message.length(), ' ' );
	Translatemssg();
	//cout << endl << "End Of Morse Code Constructor" << endl;

}

void MorseCode::Translatemssg( )
{
	//cout << "Imma do this thingy like " << message.length() << " times." << endl;

	for( auto & c : message ) c = tolower( c );
	for( unsigned int i = 0; i < message.length(); i++)

	{
		for( int j = 0; j < 26; j++ )
		{
			if( message[i] == Letters[j] )
			{
				//cout << mCode.length() << endl;
				//Translate[i] = mCode[j];
				Translate += " " + mCode[j];
				break;
			}
		}
	}
	cout << "I just translated this cute little message: " << Translate << endl;
}

void MorseCode::Print()
{
	cout << "Original text: " << message << endl;
	cout << "Morse code: " << Translate << endl;
}

MorseCode::~MorseCode()
{
	cout << "Goodbye MorseCode" << endl;
}

//********************* MORSE CODE DONE *************************

//********************* MESSAGESTACK CODE *************************
class MessageStack
{
private:
	//Message * stack[10];
	vector<Message*> stack;
	int num;
	int stacktop;

public:
	MessageStack(Message *M);
	//MessageStack();
	~MessageStack(){};
	void Push(Message *M);
	void Pop();
	void Printstack();
	int menu();
};

MessageStack::MessageStack(Message *M)
{
	num = 0;
	Push(M);
}

void MessageStack::Push(Message *M)
{
	stack.push_back(M);
}
;
void MessageStack::Pop()
{
	if( stack.size() == 0 )
	{
		cout << "Stack empty\n";
		return;
	}
	else
	{
		stack.pop_back();
	}
}

void MessageStack::Printstack()
{
	cout << "Stack top index: " << stack.size() << endl;
	cout << "-------------------" << endl;

	for(int i = ( stack.size() - 1 ); i >= 0; i-- )
	{
		//cout << "Current index: " << i << endl << endl;
		stack[i]->Print();
	}
}

int MessageStack::menu()
{

	int x;

	Message * newMessage = NULL;

	do
	{
		cout << "\n\n\n\nSelect a message from the menu " << endl;
		cout << "\n1) Enter Text " << endl;
		cout << "2) Print Stack" << endl;
		cout << "3) Push" << endl;
		cout << "4) Pop" << endl;
		cout << "5) Exit" << endl;

		cin >> x;
		cin.ignore();

		switch(x)
		{

		case 1:
		{
			//string input_mssg;
			int y;

			//Message();
			//Message(input_mssg);
			// Here you'll want to use the default constructor and get yourself a pointer to it.
			string newName;

			//Read in new name for Message.
			cout << "Enter your message: " << endl;
			getline( cin, newName );

			cout << "Enter 1 if you would like to Translate this message to Morse\nEnter 2 for NO translate" << endl;
			cin >> y;
			cin.ignore();

			switch(y)
			{
				case 1: // Doesnt work
				{
					//Translate
					newMessage = new MorseCode( newName ); //I'm casting this as a type message so that it can be pushed to the stack
					break;
				}
				case 2:
				{
					//Do Not Translate
					newMessage = new Message( newName );
					break;
				}
				default:
				{
					cout << "Invalid option" << endl;
					break;
				}
			}

			break;
		}
		case 2:
		{
			//PRINT STACK
			Printstack();
			break;
		}

		case 3:
		{
			//PUSH
			if( newMessage != NULL )
			{
				cout << "Pushing!" << endl;
				Push( newMessage );// Takes in an object of Message
				newMessage = NULL;
			}
			else
			{
			cout << "Not pushing!";
			}
			break;
		}
		case 4:
		{
			//POP
			Pop();
			break;
		}
		case 5:
		{
			exit(EXIT_SUCCESS);
			break;
		}
		default:
		{
			cout << "Invalid option" << endl;
			break;
		}
		}
	}while(x <= 5);
	return 0;
}
//********************* MESSAGESTACK CODE DONE *************************


int main()
{
	//cout << "The Program is Running!!!!" << endl; // prints

	//Create MessageStack
	Message * inTheBeginning = new Message( "wasTheWord!" );
	MessageStack Olasumbo( inTheBeginning );

	Olasumbo.menu();

	Message * letThere = new Message( "BE LIGHT!" );
	Olasumbo.Push( letThere );

	//delete inTheBeginning;


	return 0;
}
