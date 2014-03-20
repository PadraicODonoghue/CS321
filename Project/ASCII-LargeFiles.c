#include <stdlib.h> 
#include <unistd.h>
#include <sndfile.h> 
#include <math.h>
#include <ncurses.h>


// A macro to easily set/change the size of our buffers
#define BUFFRAMES 512

// Global variable
int multiplier;

// Prototype
int rounding(float value);

int main(int argc, char** argv) 
{
	// Initialize SNDFILE stuffs	
	// Soundfile pointers (input file, output file)
	SNDFILE *psf_in;
	// Soundfile information structts (input, output)
	SF_INFO *psfinfo_in;
	// Buffer of floats
	float *buffer;
	// Counter variable (for keeping track of processed frames/samples)
	sf_count_t count = 0; 
	// Allocate memory for SF_INFO structures dynamically
	psfinfo_in = (SF_INFO *) malloc( sizeof(SF_INFO) );

	if (argc < 2) {
		printf("Usage: %s InputFile.wav\n", argv[0]);
		exit(-1);
	}

	// Open input file for reading
	// argv[1] is passed as the path to the input file
	//		i.e. the first argument typed after the program's name by the user
	if( !(psf_in = sf_open(argv[1], SFM_READ, psfinfo_in)) )
	{
		printf("Error opening input file\n");
		exit(-1);
	}


	// Set channel to process and display
	int target = -1;
	// If only one channel then don't present a choice.
	if (psfinfo_in->channels == 1){
		target = 0;
	}
	// Keep prompting until you get a proper answer
	while (!(target < psfinfo_in->channels && target > -1)){
		printf("Please enter a channel number from zero to %d to process \n", (psfinfo_in->channels - 1));
		scanf("%d", &target);
	}

	
	// Change refresh rate to change how fast to display changes
	int refreshRate = 200000;
	// Ask user for input
	int userIn = -1;
	while (userIn < 0){
		printf("Please enter an integer to control how fast the screen is refreshed.\nHigher numbers mean a slower rate.\nReccomended is 200000.\n");
		scanf("%d", &userIn);
	}
	refreshRate = userIn;
	printf("Refresh Rate is %d.", refreshRate);

	
	// Initial screen setup
	// Initialize screen for ncurses
	initscr();
	// Don't show cursor
	curs_set(0);
	// Get terminal dimensions
	// Clear the screen
	clear();
	// Hold maximum x and y co-ordinates of the terminal
	int max_x, max_y;
	// Get terminal dimensions
	getmaxyx(stdscr, max_y, max_x);


	// Modify max_y to suit
	// Ensure max_y is odd so that there is an equal number of lines on each side of 0
	if (max_y % 2 == 0){
		max_y--;
	}
	// Multiplier is used in rounding()
	multiplier = (max_y - 1)/2;


	// Allocate buffers and create array for storing lines
	// Dynamically allocate buffer memory 
	buffer = (float *) malloc( sizeof(float) * BUFFRAMES);
	// Keep track of number of channels
	int numChannels =  psfinfo_in->channels;
	// Initialise a 2D array of character to represent the waveform
	char lines[max_y][max_x];


	// Prepare screen
	// Prompt user for input to start
	mvaddnstr(0,0,"Press Any Key", max_x);
	// Wait for a keypress before Starting
	getch();
	// Clear Screen
	clear();


	do
	{
		// Store the number of frames read in the count variable
		// sf_readf_float reads the samples in frames of floats from psf_in
		// A buffer of 512 will hold 256 stereo frames
		// Divide buffer size by the number of frames to tell libsndfile how many frames (items) to grab
		count = sf_readf_float(psf_in, buffer, max_x / numChannels);
		int limit = count * numChannels;


		// Fill with spaces
		for (int i = 0; i < max_x; i++) {
			for (int j = 0; j < max_y; ++j)
			{	
				lines[j][i] = ' ';
			}
		}


		// Take samples from the target channel
		// If i is n then channel n will be processed
		for (int i = target; i < limit; i= i+numChannels)
		{
			// rounding function provides line where the dash should appear
			int temp = rounding(buffer[i]);
			lines[temp][i] = '-';
		}


		// Print a string from lines of length max_x at point (n,0)
		// Work from top down
		for (int j = max_y-1; j >= 0; --j){
			// mvaddnstr(LineNo, ColumnNo, char, lengthToPrint)
			mvaddnstr(max_y-j,0,&lines[j][0], max_x);
		}


		refresh();
		//Rate at which screen is redrawn
		//Controls how quickly the text moves along the screen
		usleep(refreshRate);
	}
	while(count);


	// Shut down screen
	// Wait for a keypress before quitting
	getch();
	// Close window
	endwin();


	// Closing SNDFILE stuff
	// Close both of the files since we're done with them
	sf_close(psf_in);
	// Free the memory that we allocated dynamically
	free(psfinfo_in);	// Free input info struct memory
	free(buffer); 		// Free the buffer memory


	// Return 0 for success
	return 0;
}

int rounding(float value){
	//Multiplying by a constant and rounding it 
	value = value * multiplier;
	return roundf(value + multiplier);
}
