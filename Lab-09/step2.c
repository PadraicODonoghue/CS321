#include <stdio.h> 
#include <stdlib.h> 
#include <sndfile.h> 

// A macro to easily set/change the size of our buffers
#define BUFFRAMES 512

// Main entrypoint
int main(int argc, char** argv) 
{
	// Soundfile pointers (input file, output file)
	SNDFILE *psf_in, *psf_out;
	
	// Soundfile information structts (input, output)
	SF_INFO *psfinfo_in, *psfinfo_out;
	
	// Buffer of floats
	float *buffer;
	
	// Counter variable (for keeping track of processed frames/samples)
	sf_count_t count = 0; 
	
	// Number of channels
	int numChannels;

	// Allocate memory for SF_INFO structures dynamically
	psfinfo_in = (SF_INFO *) malloc( sizeof(SF_INFO) );
	psfinfo_out = (SF_INFO *) malloc( sizeof(SF_INFO) );
	
	// Open input file for reading
	// argv[1] is passed as the path to the input file
	//		i.e. the first argument typed after the program's name by the user

	if( !(psf_in = sf_open(argv[1], SFM_READ, psfinfo_in)) )
	{ 
		printf("Error opening input file\n"); 
		exit(-1); 
	} 
	
	// Set psfinfo_out equal to psfinfo_in

	// Change path in psfinfo_out to argv[2]

	// Dynamically allocate buffer memory (BUFFRAMES macro by the size of our data type)
	buffer = (float *) malloc( sizeof(float) * BUFFRAMES );
	
	psfinfo_out->frames = psfinfo_in->frames;
    psfinfo_out->samplerate = psfinfo_in->samplerate;
	psfinfo_out->channels = psfinfo_in->channels;
	psfinfo_out->format = psfinfo_in->format;
	psfinfo_out->sections = psfinfo_in->sections;
	psfinfo_out->seekable = psfinfo_in->seekable;
	
	numChannels =  psfinfo_in->channels;
		
	// Open the output file
	if( !( psf_out = sf_open(argv[2], SFM_WRITE,psfinfo_out) ) )
	{ 
		printf("error opening output file\n"); 
		exit(-1); 
	} 
	
	float target;
	// If no 4th argument
	if (argc < 4) {
		// Use scanf to get a value to muptiply by from the user
		printf("Enter a value between -1 and 1.\n");
		scanf("%f", &target);
		printf("Multiplier of %f will be applied.\n", target);
	} else {
		target = strtof(argv[3], NULL);
	}

	// Copy the data from one to the other, frame by frame
	// Do-while loop ensures that at least one attempt is made
	// Loop keeps going until count returns 0 (i.e.; Ran out of samples from input file [Reached end of file] )
	do 
	{ 
		// Store the number of frames read in the count variable
		// sf_readf_float reads the samples in frames of floats from psf_in
		// A buffer of 512 will hold 256 stereo frames
		// Divide buffer size by the number of frames to tell libsndfile how many frames (items) to grab
		count = sf_readf_float(psf_in, buffer, BUFFRAMES / numChannels);
		
		// Limit = number of channels * number of frames = number of samples
		int limit = count * numChannels;

		// Iterate over samples in buffer
		for (int i = 0; i < limit; ++i)
		{
			float old = *(buffer + i);
			// Multiply each sample by the user input
			*(buffer + i) = old*target;
		}

		// Take the samples that we just read from the buffer and write them to the output file (psf_out)
		// We write 'count' samples to the output, since that's how many we grabbed at the input
		sf_writef_float(psf_out, buffer, count); 
	} 
	while(count);
	
	// Close both of the files since we're done with them
	sf_close(psf_in);
	sf_close(psf_out);
	
	// Free the memory that we allocated dynamically
	free(psfinfo_in);	// Free input info struct memory
	free(psfinfo_out);	// Free output info struct memory
	free(buffer); 		// Free the buffer memory
	
	// Return 0 for success
	return 0;
}