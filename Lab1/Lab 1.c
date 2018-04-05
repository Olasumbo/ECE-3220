/*
 ============================================================================
 Name        : Lab.c
 Author      : Ola Babalola
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.142

int main(void)
{
	puts("Lab 1"); /* prints Lab 1 */
	double radius, Area = 0;
	puts(" Enter the radius of the circle");
	scanf("%lf",&radius);
	while (radius <= 0)
	{
		puts("Error, Please enter a valid radius");
		scanf("%lf",&radius);
	}
	Area = (PI*(radius*radius));
	printf(" The area of %lf is %lf", radius, Area);
	return EXIT_SUCCESS;
}
