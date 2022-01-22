/* Compute the size of some fundamental types. */

#include <stdio.h>

int main(void)
{
	printf("       char:%3ld\n", sizeof(char));
	printf("      short:%3ld\n", sizeof(short));
	printf("        int:%3ld\n", sizeof(int));
	printf("       long:%3ld\n", sizeof(long));
	printf("   unsigned:%3ld\n", sizeof(unsigned));
	printf("      float:%3ld\n", sizeof(float));
	printf("     double:%3ld\n", sizeof(double));
	printf("long double:%3ld\n", sizeof(long double));
	
	return 0;
}