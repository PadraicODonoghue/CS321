#include <stdio.h> // printf(), scanf()
#include <stdlib.h> // rand(), srand()
#include <time.h> // time()

int main ()

{

	int offset, range, number;

	printf("Please enter the first integer: \n");
	scanf("%d", &offset);

	printf("Please enter the second integer: \n");
	scanf("%d", &range);

	number = rand() % (offset + range);

	printf("Here is a random number generated between %d and %d (inclusive): %d\n", offset, range, number);

	return 0;
}