#include<stdio.h>	// printf(), scanf()
#include<stdlib.h>	// rand(), srand()
#include<time.h>	// time()

int main ()
{
	// Declare variables
	int number, range, offset;
	
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
	range = 10;
	offset = 1;
	
	// Generate random number, assign the value to 'number'
	number 	= 	rand() % range + offset;
	
	printf("Random number between %d and %d (inclusive): %d\n", offset, range, number);
	
	return 0;
}