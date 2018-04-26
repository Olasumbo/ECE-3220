/*
 ============================================================================
 Name        : Assingment1.c
 Author      : Ola
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int multiple (int x);
int power (int x);

int main(void)
{
	int input = 0;
	int step =0;
	printf("Enter a number between 1 and 10\n"); /* prints prompt */
	scanf("%d", &input);
	while (input < 1 || input > 10)
	{
		printf("Error!!! Please Enter a number between 1 and 10:\n");
		scanf("%d", &input);
	}
	printf("Enter 1 to calculate Multiples or 2 to calculate Powers:\n");
	scanf("%d", &step);
	while (step < 1 || step > 2)
		{
			printf("Error!!! Please enter a VALID option\n");
			scanf("%d", &step);
		}
	if (step == 1)
	{
		multiple(input);
	}
	else
	{
		power (input);
	}
	return EXIT_SUCCESS;
}

int multiple (int x)
{
	int i = 0;
	printf("The Multiples of %d are\n", x);
	for( i = 0; i < 12; i++)
	{
		//if(i % x == 0)
		printf("%d\n", (x*(i+1)));
	}
		return 1;
}
int power (int x)
{
	int i = 0;
	printf("The Power of %d are\n", x);
	for( i = 1; i < 16; i++)
	{
		printf("%1.0lf\n", pow (x,i));
	}
	return 0;
}
