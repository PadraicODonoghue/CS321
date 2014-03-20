#include <stdio.h>

int main(int argc, char const *argv[])
{
	printf("Size of a char is %d bytes\n", sizeof(char));
	printf("Size of an int is %d bytes\n", sizeof(int));
	printf("Size of a float is %d bytes\n", sizeof(int));
	printf("Size of a double is %d bytes\n", sizeof(double));
	printf("Size of an array of 512 ints is %d bytes\n", sizeof(int)*512);
	printf("Size of a 2D array of 2x512 doubles is %d bytes\n", sizeof(double)*2*512);
	return 0;
}