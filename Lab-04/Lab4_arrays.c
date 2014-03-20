#include <stdio.h>

int main()
{
	// Use an integer to determine the size of our arrays
	int arraySize = 32;

	// Create empty arrays
	int arrayOne[arraySize];
	double arrayTwo[arraySize];
	
	// Array counter variable
	int i = 0;
	
	// Array assignment example:
	// Iterate through the arrays (from 0 to (arraySize - 1)) and assign (i+1) to to the slots in the array
	// i begins at 0 and will increase by one on each iteration of the loop; until it is no longer less-than arraySize
	for(i = 0; i < arraySize; i++)
	{
		// Go to the position 'i' of the array and store a value of (i+1)
		// E.g: when i is zero, we store '1' at position zero in the array. When i is 10, we store '11' at position 10 in the array.
		arrayOne[i] = i + 1;
		arrayTwo[i] = (double)i + 1.0;	// Type-cast i to a double
	}
	
	// Array value retrieval example:
	// Iterate through the arrays again to print the values back out
	for(i = 0; i < arraySize; i++)
	{
		// Print a message, retrieving our values from the arrays with the notation arrayName[index]
		printf("Value at position %d of arrayOne: %d\n", i, arrayOne[i]);
		printf("Value at position %d of arrayTwo: %lf\n", i, arrayTwo[i]);	// Note the use of %lf as the format specifier for printing a double.
		printf("\n");
	}	

	return 0;
}