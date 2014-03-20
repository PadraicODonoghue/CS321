#include <stdio.h> //Include stdio library to access print function

int adder(int x, int y); //Declare function so compiler knows it exists

int main() //Main function returns int
{
	//Declare first two ints
	int a;
	int b;

	//Get input for a
	printf("Enter a number.\n");
	scanf("%d", &a);

	//Get input for b
	printf("Enter a number.\n");
	scanf("%d", &b);

	//Set third int equal to sum of first two ints
	int c = adder(a, b);

	//Print new variable
	printf("Sum of %d and %d is %d\n", a, b, c);

	//Returns 0 to indicate success
	return 0;
}

int adder(int x, int y) //Declare new function and recast 'a' and 'b' as 'x' and 'y'
{
	return (x+y); //Return sum of x and y
}