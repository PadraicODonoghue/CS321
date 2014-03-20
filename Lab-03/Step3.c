#include <stdio.h>

int main(int argc, char const *argv[])
{
	//Initialize Variables
	int a;
	int b;

	//Take input from user
	printf("Enter an integer:\n");
	scanf("%d", &a);
	printf("Enter another integer:\n");
	scanf("%d", &b);

	if (a < b) //Case 1
	{
		printf("%d is smaller than %d\n", a, b);
	} else if(a > b){ //Case 2
		printf("%d is bigger than %d\n", a, b);
	} else { //Case 3
		printf("%d is equal to %d\n", a, b);
	}

	return 0;
}