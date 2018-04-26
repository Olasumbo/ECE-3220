/* ECE3220 Lab9_example.cpp
 * Author: Luis Rivera
 * 
 * This program shows how to use wiringPi on the Raspberri Pi 3 to turn on and off
 * an LED on the auxiliary board.

  Compile using -lwiringPi
	g++ Lab9_example.c -o Lab9_example -lwiringPi
		or
	add wiringPi to the linker (-l), if using Eclipse
 */
 
#include <iostream>
#include <unistd.h>		// sleep, usleep functions
#include <wiringPi.h>	// needed for the wiringPi functions

#define LED1  8		// wiringPi number corresponding to GPIO2.
					//Check Figures 2 and 3 in the Lab9 guide.

int main(int argc, char **argv)
{
	wiringPiSetup();	// wiringPiSetupGpio() could be used. The numbers for the ports would
						// need to match the RPi GPIO pinout.
	
	pinMode(LED1, OUTPUT);	// Configure GPIO2, which is the one connected to the red LED.
	
	// The program will turn off the red LED, sleep for a while, then on, sleep, off, on and off.
	// You could use loops, if you wanted/needed.
	digitalWrite(LED1, LOW);
	sleep(1);	// How can you sleep for less than a second?
	digitalWrite(LED1, HIGH);
    sleep(1);
    digitalWrite(LED1, LOW);
	sleep(1);
    digitalWrite(LED1, HIGH);
	sleep(2);
	digitalWrite(LED1, LOW);
    
    return 0;
}
