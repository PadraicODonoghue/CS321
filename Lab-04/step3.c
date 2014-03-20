#include<stdio.h>	// printf(), scanf()
#include<stdlib.h>	// rand(), srand()
#include<time.h>	// time()

int main ()
{
	// Declare variables
	int range, offset;
	
	// Seed the RNG with the current time in seconds since 01/01/1970 00:00
	srand ( time(NULL) );
	
	// Generate a random number from 1 to 10
	// To generate random numbers within a specific range, we store the modulo of our rand() number plus the starting value (offset)
	/* Examples: 
		rand() % 10; 		--> Gives: 0-9
		rand() % 10 + 1; 	--> Gives: 1-10
		rand() % 100; 		--> Gives: 0-99
		rand() % 100 + 1;	--> Gives: 1-100
		rand() % 150 + 1;	--> Gives: 1-150		
	*/

	// Assign values to variables
	int a,b;

	printf("Enter an integer:\n");
	scanf("%d", &a);
	
	printf("Enter an integer:\n");
	scanf("%d", &b);

	//Determine which integer should be the range
	if (a > b) { 
		range = a-b;
		offset = b;
	} else {
		range = b-a;
		offset = a;
	}

	//Determine how many numbers to print
	int quantity;

	printf("How many random numbers do you want?\n");
	scanf("%d", &quantity);

	
	int randoms[quantity];
	for (int i = 0; i < quantity; ++i)
	{
		// Generate random number, assign the value to slot 'i' of array randoms
		randoms[i] = rand() % range + offset;
	}

	for (int i = 0; i < quantity; ++i)
	{
		// Cycle through the array of randoms and print each in order
		printf("Random number between %d and %d (inclusive): %d\n", a, b, randoms[i]);
	}

	return 0;
}