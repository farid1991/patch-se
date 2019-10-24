/* $Id: common.c,v 1.4 2005/01/18 15:56:45 snelg Exp $ */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <ctype.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

#ifdef HAVE_FCNTL_H
#include <fcntl.h>
#endif

#ifdef macintosh
#include   <types.h>
#include   <stat.h>
#else
#include  <sys/types.h>
#include  <sys/stat.h>
#endif

#include "common.h"

#ifdef WITH_DMALLOC
#include <dmalloc.h>
#endif

#ifdef __BEOS__
#include <bsd_mem.h>
#endif /* __BEOS__ */

// In C++ the array first must be prototyped, why ?

extern const int tabsel_123 [2] [3] [16];

const int tabsel_123 [2] [3] [16] = {
   { {0,32,64,96,128,160,192,224,256,288,320,352,384,416,448,},
     {0,32,48,56, 64, 80, 96,112,128,160,192,224,256,320,384,},
     {0,32,40,48, 56, 64, 80, 96,112,128,160,192,224,256,320,} },

   { {0,32,48,56,64,80,96,112,128,144,160,176,192,224,256,},
     {0,8,16,24,32,40,48,56,64,80,96,112,128,144,160,},
     {0,8,16,24,32,40,48,56,64,80,96,112,128,144,160,} }
};

const long freqs[9] = { 44100, 48000, 32000,
                        22050, 24000, 16000,
                        11025, 12000,  8000 };

int bitindex;
unsigned char *wordpointer;
unsigned char *pcm_sample;
int pcm_point = 0;


#if defined( USE_LAYER_1 ) || defined ( USE_LAYER_2 )
  real muls[27][64];
#endif

#if 0
static void get_II_stuff(struct frame *fr)
{
  static const int translate [3] [2] [16] =   /* char ? */
   { { { 0,2,2,2,2,2,2,0,0,0,1,1,1,1,1,0 } ,
       { 0,2,2,0,0,0,1,1,1,1,1,1,1,1,1,0 } } ,
     { { 0,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0 } ,
       { 0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0 } } ,
     { { 0,3,3,3,3,3,3,0,0,0,1,1,1,1,1,0 } ,
       { 0,3,3,0,0,0,1,1,1,1,1,1,1,1,1,0 } } };

  int table,sblim;
  static const struct al_table2 *tables[5] = 
       { alloc_0, alloc_1, alloc_2, alloc_3 , alloc_4 };
  static int sblims[5] = { 27 , 30 , 8, 12 , 30 };

  if(fr->lsf)
    table = 4;
  else
    table = translate[fr->sampling_frequency][2-fr->stereo][fr->bitrate_index];
  sblim = sblims[table];

  fr->alloc = tables[table];
  fr->II_sblimit = sblim;
}
#endif

#define HDRCMPMASK 0xfffffd00


int head_check(unsigned long head,int check_layer)
{
  /*
    look for a valid header.  
    if check_layer > 0, then require that
    nLayer = check_layer.  
   */

  /* bits 13-14 = layer 3 */
  int nLayer=4-((head>>17)&3);

  if( (head & 0xffe00000) != 0xffe00000) {
    /* syncword */
	return FALSE;
  }
#if 0
  if(!((head>>17)&3)) {
    /* bits 13-14 = layer 3 */
	return FALSE;
  }
#endif

  if (3 !=  nLayer) 
  {
	#if defined (USE_LAYER_1) || defined (USE_LAYER_2)
	  if (4==nLayer)
		  return FALSE;
	#else
		return FALSE;
    #endif
  }

  if (check_layer>0) {
      if (nLayer != check_layer) return FALSE;
  }

  if( ((head>>12)&0xf) == 0xf) {
    /* bits 16,17,18,19 = 1111  invalid bitrate */
    return FALSE;
  }
  if( ((head>>10)&0x3) == 0x3 ) {
    /* bits 20,21 = 11  invalid sampling freq */
    return FALSE;
  }
  return TRUE;
}


/*
 * the code a header and write the information
 * into the frame structure
 */
int decode_header(struct frame *fr,unsigned long newhead)
{


    if( newhead & (1<<20) ) {
      fr->lsf = (newhead & (1<<19)) ? 0x0 : 0x1;
      fr->mpeg25 = 0;
    }
    else {
      fr->lsf = 1;
      fr->mpeg25 = 1;
    }

    
    fr->lay = 4-((newhead>>17)&3);
    if( ((newhead>>10)&0x3) == 0x3) {
      fprintf(stderr,"Stream error\n");
      fclose(stdout);
      fclose(stderr);
      exit(1);
    }
    if(fr->mpeg25) {
      fr->sampling_frequency = 6 + ((newhead>>10)&0x3);
    }
    else
      fr->sampling_frequency = ((newhead>>10)&0x3) + (fr->lsf*3);

    fr->error_protection = ((newhead>>16)&0x1)^0x1;

    if(fr->mpeg25) /* allow Bitrate change for 2.5 ... */
      fr->bitrate_index = ((newhead>>12)&0xf);

    fr->bitrate_index = ((newhead>>12)&0xf);
    fr->padding   = ((newhead>>9)&0x1);
    fr->extension = ((newhead>>8)&0x1);
    fr->mode      = ((newhead>>6)&0x3);
    fr->mode_ext  = ((newhead>>4)&0x3);
    fr->copyright = ((newhead>>3)&0x1);
    fr->original  = ((newhead>>2)&0x1);
    fr->emphasis  = newhead & 0x3;

    fr->stereo    = (fr->mode == MPG_MD_MONO) ? 1 : 2;

    switch(fr->lay)
    {
#ifdef USE_LAYER_1
      case 1:
		fr->framesize  = (long) tabsel_123[fr->lsf][0][fr->bitrate_index] * 12000;
		fr->framesize /= freqs[fr->sampling_frequency];
		fr->framesize  = ((fr->framesize+fr->padding)<<2)-4;
		fr->down_sample=0;
		fr->down_sample_sblimit = SBLIMIT>>(fr->down_sample);
        break;
#endif
#ifdef USE_LAYER_2
      case 2:
		fr->framesize = (long) tabsel_123[fr->lsf][1][fr->bitrate_index] * 144000;
		fr->framesize /= freqs[fr->sampling_frequency];
		fr->framesize += fr->padding - 4;
		fr->down_sample=0;
		fr->down_sample_sblimit = SBLIMIT>>(fr->down_sample);
        break;
#endif
      case 3:
#if 0
        fr->do_layer = do_layer3;
        if(fr->lsf)
          ssize = (fr->stereo == 1) ? 9 : 17;
        else
          ssize = (fr->stereo == 1) ? 17 : 32;
#endif

#if 0
        if(fr->error_protection)
          ssize += 2;
#endif
	if (fr->bitrate_index==0)
	  fr->framesize=0;
	else{
          fr->framesize  = (long) tabsel_123[fr->lsf][2][fr->bitrate_index] * 144000;
          fr->framesize /= freqs[fr->sampling_frequency]<<(fr->lsf);
          fr->framesize = fr->framesize + fr->padding - 4;
	}
        break; 
      default:
        fprintf(stderr,"Sorry, layer %d not supported\n",fr->lay); 
        return (0);
    }
    /*    print_header(fr); */

    return 1;
}


#if 1
void print_header(struct frame *fr)
{
	static const char *modes[4] = { "Stereo", "Joint-Stereo", "Dual-Channel", "Single-Channel" };
	static const char *layers[4] = { "Unknown" , "I", "II", "III" };

	fprintf(stderr,"MPEG %s, Layer: %s, Freq: %ld, mode: %s, modext: %d, BPF : %d\n", 
		fr->mpeg25 ? "2.5" : (fr->lsf ? "2.0" : "1.0"),
		layers[fr->lay],freqs[fr->sampling_frequency],
		modes[fr->mode],fr->mode_ext,fr->framesize+4);
	fprintf(stderr,"Channels: %d, copyright: %s, original: %s, CRC: %s, emphasis: %d.\n",
		fr->stereo,fr->copyright?"Yes":"No",
		fr->original?"Yes":"No",fr->error_protection?"Yes":"No",
		fr->emphasis);
	fprintf(stderr,"Bitrate: %d Kbits/s, Extension value: %d\n",
		tabsel_123[fr->lsf][fr->lay-1][fr->bitrate_index],fr->extension);
}

void print_header_compact(struct frame *fr)
{
	static const char *modes[4] = { "stereo", "joint-stereo", "dual-channel", "mono" };
	static const char *layers[4] = { "Unknown" , "I", "II", "III" };
 
	fprintf(stderr,"MPEG %s layer %s, %d kbit/s, %ld Hz %s\n",
		fr->mpeg25 ? "2.5" : (fr->lsf ? "2.0" : "1.0"),
		layers[fr->lay],
		tabsel_123[fr->lsf][fr->lay-1][fr->bitrate_index],
		freqs[fr->sampling_frequency], modes[fr->mode]);
}

#endif

unsigned int getbits(int number_of_bits)
{
  unsigned long rval;

  if(!number_of_bits)
    return 0;

  {
    rval = wordpointer[0];
    rval <<= 8;
    rval |= wordpointer[1];
    rval <<= 8;
    rval |= wordpointer[2];
    rval <<= bitindex;
    rval &= 0xffffff;

    bitindex += number_of_bits;

    rval >>= (24-number_of_bits);

    wordpointer += (bitindex>>3);
    bitindex &= 7;
  }
  return rval;
}

unsigned int getbits_fast(int number_of_bits)
{
  unsigned long rval;

  {
    rval = wordpointer[0];
    rval <<= 8;	
    rval |= wordpointer[1];
    rval <<= bitindex;
    rval &= 0xffff;
    bitindex += number_of_bits;

    rval >>= (16-number_of_bits);

    wordpointer += (bitindex>>3);
    bitindex &= 7;
  }
  return rval;
}


int set_pointer( PMPSTR mp, long backstep)
{
  unsigned char *bsbufold;

  if(mp->fsizeold < 0 && backstep > 0) {
//    fprintf(stderr,"Can't step back %ld!\n",backstep);
    return MP3_ERR; 
  }
  bsbufold = mp->bsspace[1-mp->bsnum] + 512;
  wordpointer -= backstep;
  if (backstep)
    memcpy(wordpointer,bsbufold+mp->fsizeold-backstep,(size_t)backstep);
  bitindex = 0;
  return MP3_OK;
}
