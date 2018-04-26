#include <stdio.h>

int main(void)
{
	unsigned int x = 3;
	int z = 4;

    printf("\n3/4 using integral types: %d.\n", x/z);
    printf("3/4 using float cast: %f\n", (float) x/z);
    printf("The average of %d and %d is %d.\n", x, z, (1/2)*(x+z));
    printf("The average of %d and %d is %d.\n", x, z, (1.0/2)*(x+z));
    printf("The average of %d and %d is %f.\n\n", x, z, (1.0/2)*(x+z));

    x = 0x0F;
    z = 0xF0;
    printf("x is %d (%02X);  z is %d (%02X); x&z is %d (%02X).\n",
			x, x, z, z, x&z, x&z);
    printf("x is %d (%02X);  z is %d (%02X); x|z is %d (%02X).\n",
			x, x, z, z, x|z, x|z);
    printf("x is %d (%02X);  z is %d (%02X); x^z is %d (%02X).\n\n",
			x, x, z, z, x^z, x^z);

    x = 0xF0;
    printf("x is %d (%02X);  z is: %d (%02X); x^z is: %d (%02X).\n",
			x, x, z, z, x^z, x^z);
    printf("x is %d (%02X);  x<<2 is: %d (%02X).\n", x, x, x<<2, x<<2);
    printf("x is %d (%02X);  x>>1 is: %d (%02X).\n\n", x, x, x>>1, x>>1);

    x = 3;
    z = 2;
    x += z;
    printf("%d\n", x);
    x *= z;
    printf("%d\n", x);
    x *= z+1;
    printf("%d\n", x);
    x *= z++;
    printf("%d\n", x);
    x *= ++z;
    printf("%d\n\n", x);

	return 0;
}
