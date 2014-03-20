int wrongWay()
{
  char *pBuffer; //<--nothing allocated yet (excluding the pointer itself, which is allocated here on the stack).
  int b = 1; // Allocated on the stack.
  if(b)
  {
    //Create 500 bytes on the stack
    char buffer[500];

    //Create 500 bytes on the heap
	char *pBuffer = (char * ) malloc( sizeof(char) * ( 500 ) );
		// Alternatively: 
		//char should be 1 byte in almost all cases, but convention dictates the use of sizeof() - A good habit!
		//char *pBuffer = malloc( 500 );	

	// Do stuff with pBuffer here such as iterating the array or otherwise making use of the memory
	
   }//<-- buffer is deallocated here, pBuffer is not
}//<--- oops there's a memory leak, I should have called free( pBuffer );

int rightWay()
{
  char *pBuffer; //<--nothing allocated yet (excluding the pointer itself, which is allocated here on the stack).
  int b = 1; // Allocated on the stack.
  if(b)
  {
    //Create 500 bytes on the stack
    char buffer[500];

    //Create 500 bytes on the heap
	char *pBuffer = (char * ) malloc( sizeof(char) * ( 500 ) );

	// Do stuff with pBuffer here such as iterating the array or otherwise making use of the memory

	// Free the dynamically-allocated memory
	free (pBuffer);	//<-- pBuffer is deallocated here
	
   }//<-- buffer is deallocated here
}

//http://stackoverflow.com/questions/79923/what-and-where-are-the-stack-and-heap

//(Modified from C++ to C)
