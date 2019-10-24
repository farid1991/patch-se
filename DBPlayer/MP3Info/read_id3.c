/* 
 * ID3 read library
 * Created by Tim O'Brien, t413.com
 * Oct 28, 2010
 *
 * * Releaced under the Creative Commons Attribution-ShareAlike 3.0
 * * You are free 
 * *  - to Share, copy, distribute and transmit the work
 * *  - to Remix — to adapt the work
 * * Provided 
 * *  - Attribution (my name and website in the comments in your source)
 * *  - Share Alike - If you alter, transform, or build upon this work, 
 * *      you may distribute the resulting work only under 
 * *      the same or similar license to this one
 *
 * if you are unfamiliar with the terms of this lisence,
 *  would like to see the full legal code of the license,
 *  or have any questions please email me (timo@t413.com) or visit:
 *  http://creativecommons.org/licenses/by-sa/3.0/us/   for details
 */

//#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "read_id3.h"

#ifdef __arm__  // for an embedded enviroment, using FatFs from chan
#include "../fat/ff.h"				// FAT File System Library
#include "../fat/diskio.h" 			// Disk IO Initialize SPI Mutex
#define file_seek_absolute(file,position) f_lseek(file, position)
#define file_seek_relative(fi,pos) f_lseek(fi,fi->fptr+pos)
#define file_read(f,str,l,rea) f_read(f,str,(l),&(rea))
#else
//#include <iostream>
#define file_seek_absolute(file,position) fseek (file , position , SEEK_SET)
#define file_seek_relative(fi,pos) fseek(fi,pos,SEEK_CUR)
#define file_read(f,str,l,rea) rea=fread(str,1,l,f)
#endif

#define min(a,b) ((a>b)?(b):(a))

// now used like this: 
//    read_ID3_info( TITLE, str, sizeof(str), &fp);

unsigned char read_ID3_info(const unsigned char tag_name,char * output_str, unsigned int res_str_l, FIL *fp)
{
	//here we've got macros to define the tagname for each data frame
	// add new ones if you want. every four characters is a new tag type
	//-----------------     ttl|alb|art|trk|yea|len|
	const char id3v2_3[] = "TIT2TALBTPE1TRCKTYERTLEN";  //id3, v2, spec 3 uses 4 byte ID
	const char id3v2_2[] = "TT2 TAL TP1 TRK TYE TLE ";  //id3, v2, spec 2 uses 3 byte ID
	//-----------------   |title| |artist| |year|
	//-----------------       |album| |track|  |len|

	unsigned char common_header[10];
	unsigned int bytesRead = 0;
	file_seek_absolute(fp,0);
	file_read(fp,common_header,sizeof(common_header),bytesRead);
	if ((common_header[0]!='I')||(common_header[1]!='D')||(common_header[2]!='3')) return 0;
	
	if (common_header[3] <= 0x04) {   //recognized id3 v2
		unsigned int tag_size = (common_header[9]) | (common_header[8] << 7) | (common_header[7] << 14) | (common_header[6] << 28);
		
		const char * compare_tagname = ((common_header[3] == 0x03)||(common_header[3] == 0x04))? (id3v2_3+(tag_name*4)) : (id3v2_2+(tag_name*4));
		int just_safe = 30;  //to avoid an infinite loop limit the number of iterations.
		while (tag_size && just_safe--) {
			unsigned char frame_header[10];
			unsigned int fr_hdr_bytes = 0;
			//the size of the data frames depends on the version varriant. 03=10 bytes, 02=6 bytes.
			unsigned int frame_header_size = ((common_header[3] == 0x03)||(common_header[3] == 0x04))? 10 : ((common_header[3]==0x02)? 6:6);
			file_read(fp,frame_header,frame_header_size,fr_hdr_bytes);
			tag_size -= fr_hdr_bytes;
			//check to make sure this TAG name is really a tag name.
			unsigned int tagname_size = ((common_header[3] == 0x03)||(common_header[3] == 0x04))? 4 : ((common_header[3]==0x02)? 3:3);
			for (int jj=0;jj<tagname_size;jj++) if ((frame_header[jj]>'Z')||(frame_header[jj]<'0')) return 0;
			unsigned long frame_size;
			if ((common_header[3] == 0x03)||(common_header[3] == 0x04))
				frame_size = (frame_header[7]) | (frame_header[6] << 8) | (frame_header[5] << 16) | ((frame_header[4] << 16) << 16);
			else //if (common_header[3] == 0x02)
				frame_size = (frame_header[5]) | (frame_header[4] << 8) | (frame_header[3] << 16);
			
			//check to see if we've got the right tag as was asked for:
			if (0==strncmp((char*)frame_header,compare_tagname,tagname_size)){
				file_seek_relative(fp,1); //skip past empty byte.
				
				// UNICODE to ASCII conversion..
				unsigned int l_to_read = min(frame_size,res_str_l); //TODO: might need to be frame_size-1
				//printf("->[%s] of size %ld bytes, reading [%i]\n", frame_header,frame_size,l_to_read);
				
				if (l_to_read >= 2){
					unsigned int convert_read = 0;
					file_read(fp,output_str,2,convert_read);
					char start_utf[3] = {0xFF,0xFE};
					if (0 == strncmp( start_utf, output_str, 2)){  // unicode tags start with 01 FF FE
						//Unicode decode string:
						l_to_read = min((frame_size-3)/2,res_str_l-1);
						//printf(" unicode!-> frame_size=%ld, (have%i) reading [%i]\n", frame_size, res_str_l, l_to_read);
						for (unsigned int ii = 0; ii <= l_to_read; ii++) {
							file_read(fp,output_str+ii,1,fr_hdr_bytes);
							file_seek_relative(fp,1);
							if ((output_str[ii]>'~')||(output_str[ii]<' ')) output_str[ii] = '_';
						}
						output_str[l_to_read] = 0; //make sure there's a null terminator.
						return 1;
					}
					//not unicode, go back to the beginning.
					file_read(fp,output_str+2,l_to_read-3,fr_hdr_bytes);
					output_str[l_to_read-1] = 0; //make sure there's a null terminator.
					//printf(" non unicode -> %s\n",output_str);
					return 1;
				}
				// copy non-unicode string to the string.
				file_read(fp,output_str,l_to_read,fr_hdr_bytes);
				output_str[l_to_read-1] = 0; //make sure there's a null terminator.
				//printf(" non unicode -> %s\n",output_str);
				return 1;
			}
			else {
				file_seek_relative(fp,frame_size);
				tag_size -= frame_size;
			}
		}
		return 0;
	}
	else return 0;
}
