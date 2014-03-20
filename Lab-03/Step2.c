#include <stdio.h>

int main(int argc, char const *argv[])
{
	//Initialize variable
	int a = 13;

	if (a%2 == 0) 	//Remainder equals zero iff even
	{
		printf("%d is even\n", a);
	} else {		//Otherwise odd
		printf("%d is odd\n", a);
	}
	return 0;
}