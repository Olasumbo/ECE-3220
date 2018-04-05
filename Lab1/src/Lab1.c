#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1415

int main(void)
{
	puts("Welcome");
	double radius = 0;
	puts("What is the radius of your circle\t");
	scanf("%lf", &radius);
	double Area = 0;
	Area = (PI*(radius*radius));
	printf("The area of radius %f is %.2lf\n", radius,Area );

	return EXIT_SUCCESS;
}
