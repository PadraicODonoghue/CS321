#include <stdio.h>

int main(int argc, char const *argv[])
{
	//Initialize variables
	int a = 10;
	int b = 15;

	if (a < b) //Case 1
	{
		printf("%d is smaller than %d\n", a, b);
	} else if(a > b){ //Case 2
		printf("%d is bigger than %d\n", a, b);
	} else { //Case 3
		("%d is equal to %d\n", a, b);
	}

	return 0;
}