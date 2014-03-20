#include <stdio.h>
int main(int argc, char const *argv[])
{
	typedef struct type 
	{ 
		int a;
		char b;
		float c; 
	} types; 

	types str;
	str.a = 12;
	str.b = 'c';
	str.c = 12.01;

	printf("Struct a: %d\n", str.a);
	printf("Struct b: %c\n", str.b);
	printf("Struct c: %f\n", str.c);
	return 0;
}