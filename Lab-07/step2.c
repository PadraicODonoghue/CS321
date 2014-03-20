#include <stdio.h>
#include <stdlib.h>

int main()
{	
	// Initialise size as -1 to trigger while
	int size = -1;
	
	printf("Enter a value for size:\n");
	// Repeatedly ask user for an integer until they give one > 0
	while (size < 0){
		scanf("%d", &size);
	}

	// Allocate memory for array of size size
	int *pointer[] = (int *[]) malloc( sizeof(int) * ( size ));
	// char *pBuffer = (char * ) malloc( sizeof(char) * ( 500 ) );
	printf("Allocated %d for an integer array of size %d \n", sizeof(*pointer), size);
	printf("Allocated %d for an integer array of size %d \n", sizeof(int) * size, size);
	// Free up allocated memory
	free(pointer);
	return 0;
}