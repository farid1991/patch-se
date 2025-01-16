#ifndef __ID3V2_H__
#define __ID3V2_H__

#define ID3V2_2 2
#define ID3V2_2_BYTE 3
#define ID3V2_3 3
#define ID3V2_4 4
#define ID3V2_X_BYTE 4

#define ID3_HEADER_ID_LENGTH 3
#define ID3_HEADER_TAG_SIZE 4
#define ID3_HEADER_SIZE 10
#define ID3_EXTENDED_HEADER_SIZE 4
#define ID3_EXTENDED_HEADER_FLAGS 2
#define ID3_EXTENDED_HEADER_PADDING_SIZE 4

#define ID3_FRAME_ID_SIZE 4
#define ID3_FRAME_SIZE 4
#define ID3_FRAME_FLAGS_SIZE 2
#define ID3_FRAME_ENC_SIZE 1
#define ID3_FRAME_LYRIC_LNG_SIZE 3
#define ID3_FRAME_SYNC 0x7FF

#define ID3_RESERVED_VERSION 1
#define ID3_INVALID_LAYER 0
#define ID3_INVALID_BITRATE 15
#define ID3_INVALID_FREQ 3

// Lookup table for bitrate values (depends on version and layer)
static const uint8_t bitrate_table[2][3][16] = {
    {
        // MPEG 2 & 2.5
        {0, 4, 8, 12, 16, 20, 24, 28, 32, 40, 48, 56, 64, 72, 80, 0},    // Layer III
        {0, 4, 8, 12, 16, 20, 24, 28, 32, 40, 48, 56, 64, 72, 80, 0},    // Layer II
        {0, 16, 24, 28, 32, 40, 48, 56, 64, 72, 80, 88, 96, 112, 128, 0} // Layer I
    },
    {
        // MPEG 1
        {0, 16, 20, 24, 28, 32, 40, 48, 56, 64, 80, 96, 112, 128, 160, 0},     // Layer III
        {0, 16, 24, 28, 32, 40, 48, 56, 64, 80, 96, 112, 128, 160, 192, 0},    // Layer II
        {0, 16, 32, 48, 64, 80, 96, 112, 128, 144, 160, 176, 192, 208, 224, 0} // Layer I
    }};

static const uint8_t frequency_table[5][5] = {
    {32, 16, 8},  // MPEG 2.5
    {0, 0, 0},    // reserved
    {22, 24, 16}, // MPEG 2
    {44, 48, 32}  // MPEG 1
};

int get_bitrate(uint32_t header);
int get_frequency(uint32_t header);
const char *get_mode(uint32_t header);
uint32_t id3v2_read_header(const wchar_t *path, const wchar_t *name, uint32_t *tagsize, uint32_t *version, uint32_t *fpos);

#endif
