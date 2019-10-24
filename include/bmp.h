
typedef unsigned short btype_t;

typedef struct {
    btype_t type;			/* Magic identifier            */
    size_t	size;			/* File size in bytes          */
    size_t	reserved;
    size_t	offset;			/* Offset to image data, bytes */
} BITMAPFILEHEADER;

typedef struct {
    size_t	size;			/* Header size in bytes		*/
    int 	width;			/* Width of image 			*/
	int		height;			/* Height of image			*/
    btype_t	planes;			/* Number of colour planes	*/
    btype_t	bits;			/* Bits per pixel			*/
    size_t	compression;	/* Compression type			*/
    size_t	imagesize;		/* Image size in bytes		*/
    int		xresolution		/* Pixels per meter			*/
	int		yresolution;	/* Pixels per meter			*/
    size_t	ncolours;		/* Number of colours		*/
    size_t importantcolours;/* Important colours		*/
} BITMAPINFOHEADER;

typedef struct {
    unsigned char r,g,b,junk;
} COLOURINDEX;

unsigned char *LoadBitmapFile(char *filename, BITMAPINFOHEADER *bitmapInfoHeader)
{
    FILE *filePtr; //our file pointer
    BITMAPFILEHEADER bitmapFileHeader; //our bitmap file header
    unsigned char *bitmapImage;  //store image data
    int imageIdx=0;  //image index counter
    unsigned char tempRGB;  //our swap variable

    //open filename in read binary mode
    filePtr = fopen(filename,"rb");
    if (filePtr == NULL)
        return NULL;

    //read the bitmap file header
    fread(&bitmapFileHeader, sizeof(BITMAPFILEHEADER),1,filePtr);

    //verify that this is a bmp file by check bitmap id
    if (bitmapFileHeader.type != ('M'*256+'B') /*0x4D42*/ )
    {
        fclose(filePtr);
        return NULL;
    }

    //read the bitmap info header
    fread(bitmapInfoHeader, sizeof(BITMAPINFOHEADER),1,filePtr); // small edit. forgot to add the closing bracket at sizeof

    //move file point to the begging of bitmap data
    fseek(filePtr, bitmapFileHeader.offset, SEEK_SET);

    //allocate enough memory for the bitmap image data
    bitmapImage = (unsigned char*)malloc(bitmapInfoHeader->size);

    //verify memory allocation
    if (!bitmapImage)
    {
        free(bitmapImage);
        fclose(filePtr);
        return NULL;
    }

    //read in the bitmap image data
    fread(bitmapImage,bitmapInfoHeader->size,filePtr);

    //make sure bitmap image data was read
    if (bitmapImage == NULL)
    {
        fclose(filePtr);
        return NULL;
    }

    //swap the r and b values to get RGB (bitmap is BGR)
    for (imageIdx = 0; imageIdx < bitmapInfoHeader->size; imageIdx+=3) // fixed semicolon
    {
        tempRGB = bitmapImage[imageIdx];
        bitmapImage[imageIdx] = bitmapImage[imageIdx + 2];
        bitmapImage[imageIdx + 2] = tempRGB;
    }

    //close file and return bitmap iamge data
    fclose(filePtr);
    return bitmapImage;
}