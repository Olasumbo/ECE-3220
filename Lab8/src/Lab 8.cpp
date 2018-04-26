//============================================================================
// Name        : Lab.cpp
// Author      : Ola
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <math.h>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include <sstream>

using namespace std;
#define PI 3.1416

class BaseConic
{
protected:
	double x = 0;
	double y = 0;

public:
	// Notice the default values. They don't need to be 0
	BaseConic(double x0 = 0, double y0 = 0){x = x0; y = y0;}
	virtual ~BaseConic(){};
	void Move(double nx, double ny){x = nx; y = ny;}
	virtual double Area() = 0; // a pure virtual function ==> ABC
	virtual void display() = 0;
};

class Ellipse : public BaseConic
{
private:
	double a; 	// semi-major axis
	double b; 	// semi-minor axis
	double angle; // orientation angle

public:
	Ellipse(double x0, double y0, double a0, double b0, double an0);
	~Ellipse(){}
	virtual double Area() {return PI*a*b;}
	void Rotate(double nang){angle += nang;}
	virtual void display();
	void Resize(double x, double y);//o modify the radius or semi-major/minor axis values, respectively;
	double* calcVertices();
};

// Notice the default values. Those are used if no parameter is given when
// an object is created.
// Notice how the BaseConic constructor can be called. If other constructors where defined,
// those could be used instead.
Ellipse::Ellipse(double x0=1,double y0=0,double a0=0,double b0=0,double an0=0) : BaseConic(x0,y0) {
	// x and y are set in the BaseConic constuctor
	a = a0;
	b = b0;
	angle = an0;
}

void Ellipse:: Resize(double x, double y)
{
	a = x;
	b = y;
}

void Ellipse::display()
{
	cout << "x = " << x << ", y = " << y << ", a = " << a << ", b = " << b
			<< ", angle = " << angle << ", Area = " << this->Area() << endl;
}

//Calculates where the vertices are and returns them as
// a list of 8 numbers. every two make a point.
double *Ellipse::calcVertices()
{
	double* vert = new double[ 8 ];

	vert[ 0 ] = a*cos( angle );
	vert[ 1 ] = a*sin( angle );
	vert[ 2 ] = -1 *b*sin( angle );
	vert[ 3 ] = b * cos( angle );
	vert[ 4 ] = -1*a *cos( angle );
	vert[ 5 ] = -1*a *sin( angle );
	vert[ 6 ] = b * sin( angle );
	vert[ 7 ] = -1*b*cos( angle );

	int i;
	for( i = 0; i < 8; i += 2 );
	{
		x += vert[ i ];
		y += vert[ i + 1 ];
	}
	cout<<"Horizontal Vertices: "<< x << endl;
	cout<<"Vertical Vertices: "<< y << endl;
	return vert;
}

class Circle : public BaseConic
{
private:
	double r; 	// radius

public:
	virtual double Area() {return PI*r*r;}
	Circle(double x0=1,double y0=1,double r0=1) : BaseConic(x0,y0){r = r0;}
	virtual void display();
	void Resize(double Newr);//o modify the radius or semi-major/minor axis values, respectively;
	bool inside(double x_in, double y_in);
	//void Display(double x = 0, double y = 0, double r = 0);
};

void Circle::display()
{
	cout << "x = " << x << ", y = " << y << ", r = " << r
			<< ", Area = " << this->Area() << endl;
}

bool Circle::inside( double x_in, double y_in )
{
	x = x_in;
	y = y_in;

	double distance = sqrt( x_in*x_in + y_in*y_in );

	if( distance < r )
	{
		return true;
	}
	else
	{
		return false;
	} // END if...else

}
void Circle::Resize(double Newr)
{
	r = Newr;
}

int main()
{
	//BaseConic b0;	// not possible to create an object of the ABC
	cout << "==========CIRCLE==========" << endl;
	Circle c0, c1(2,-1,5);
	c0.display();
	c1.display();

	c1.Move(-20,32);
	c1.display();
	cout << "Circle area: " << c1.Area() << endl;
	c1.Resize(54);
	c1.display();

	cout << endl << "==========ELLIPSE==========" << endl;
	Ellipse e0, e2(0.1,0.2,0.3,0.4,0.5);
	e2.display();
	e2.Move(10, 6);
	cout << "Ellipse area: " << e2.Area() << endl;
	e2.Resize(5, 4);
	e2.Rotate(45);
	e2.display();
	cout << "\n--------------------------------------------------------------\n" << endl;
	cout << endl << "==========Using ABC Pointers and References==========" << endl;
	// You CAN use ABC pointers and references
	BaseConic *bptr2 = new Ellipse(1,1,2,3,0.5);
	bptr2->display();

	BaseConic *bptr4 = new Circle(1,1,2);
	bptr4->display();

	cout << "\n--------------------------------------------------------------\n" << endl;
	int option;
	cout << "\nSelect Type of Object to Create: " << endl;
	cout << "1. Circle" << endl;
	cout << "2. Ellipse" << endl;
	cout << "3. Exit" << endl;
	cout << "--> ";
	cin >> option;

	if(option == 1)
	{
		int x, y, radius;
		Circle whynot;

		//making Circle
		cout<<" Enter your x, y and r for the circle"<< endl;
		cin >> x >> y >> radius;
		whynot = Circle(x, y, radius);
		whynot.display();

		/*// area
		cout<<"This prints out the area"<< endl;
		whynot.Area();
		whynot.display();*/

		//inside
		cout<<"Enter a new x, y axis for the inside function"<< endl;
		cin >> x >> y;
		whynot.inside(x,y);
		whynot.display();

		// Resize
		cout<<"Enter your a new radius for Rezise"<< endl;
		cin >> radius;
		whynot.Resize(radius);
		whynot.display();

		//Move
		cout<<"Enter your x, y axis to Move the Circle"<< endl;
		cin >> x >> y;
		whynot.Move(x, y);
		whynot.display();

	}
	if(option == 2) // Ellipse
	{
		int x, y,z,v,ang;
		int radius;
		Ellipse Ell;

		cout<<" Enter your 5 num for the Ellipse"<< endl;
		cin >> x >> y >> z >> v >> ang;
		Ell = Ellipse(x,y,z,v,ang);

		cout<<"Area of the Ellipse "<< endl;
		Ell.Area();
		Ell.display();

		cout<<"Enter an angle to rotate by"<< endl;
		cin >> ang;
		Ell.Rotate(ang);
		Ell.display();

		// Resize
		cout<<"Enter your a new z, v for Resize"<< endl;
		cin >> z >> v;
		Ell.Resize(z,v);
		Ell.display();

		//Move
		cout<<"Enter your x, y to move the Ellipse"<< endl;
		cin >> x >> y;
		Ell.Move(x, y);
		Ell.display();

		Ell.calcVertices();

	}
	if(option == 3)
	{
		exit(EXIT_SUCCESS);
	}
	else if(option < 1 || option > 3)
	{
		cout << "Inalid input" << endl;
	}

	cout << "\n--------------------------------------------------------------\n" << endl;
	cout << "\n--------------------------------------------------------------\n" << endl;

	delete bptr2;
	delete bptr4;

	return 0;

}
