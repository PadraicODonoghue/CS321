#include <stdio.h>

int main()
{
	//declare array to hold 20 integers
	double array[20];

	//iterate through every forth element of the array
	for (int i = 0; i < 20; i=i+4)
	{	
		//set first equal to 1.0
		array[i] = 1.0;
		//set second equal to 1.0
		array[i+1] = 2.0;
		//set third equal to 1.0
		array[i+2] = 4.0;
		//set forth equal to 1.0
		array[i+3] = 8.0;
	}

	//iterate through array
	for (int i = 0; i < 20; ++i)
	{
		//print each element multiplied by its index and its array index	
		printf("Element %d is %G. \n", i, array[i]*i);
	}

	return 0;
}
