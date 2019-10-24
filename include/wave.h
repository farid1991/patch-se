// WAVE file header format

typedef struct _WAVE {
 byte riff[4];					// "RIFF" string
 unsigned int overall_size ;	// overall size of file in bytes
 byte wave[4];					// "WAVE" string
 char fmt_chunk_marker[4];		// fmt string with trailing null char
 unsigned int length_of_fmt;	// length of the format data
 uint16 format_type;			// format type. 1-PCM, 3- IEEE float, 6 - 8bit A law, 7 - 8bit mu law
 uint16 channels;				// no.of channels
 unsigned int sample_rate;		// sampling rate (blocks per second)
 unsigned int byterate;			// SampleRate * NumChannels * BitsPerSample/8
 uint16 block_align;			// NumChannels * BitsPerSample/8
 uint16 bits_per_sample;		// bits per sample, 8- 8bits, 16- 16 bits etc
 byte data_chunk_header [4];	// DATA string or FLLR string
 unsigned int data_size;		// NumSamples * NumChannels * BitsPerSample/8 - size of the next chunk that will be read
} WAVE;