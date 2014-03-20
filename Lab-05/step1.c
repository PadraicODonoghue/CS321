#include <stdio.h>

int main()
{
	//declare array to hold 20 integers
	double array[20];

	//iterate through every second element of the array
	for (int i = 0; i < 20; i=i+2)
	{
		//set evens equal to 1.0
		array[i] = 1.0;
		//set odds equal to 2.0
		array[i+1] = 2.0;
	}

	//iterate through array
	for (int j = 0; j < 20; ++j)
	{
		//print each element and its array index	
		printf("Element %d is %G. \n", j, array[j]);
	}

	return 0;
}
