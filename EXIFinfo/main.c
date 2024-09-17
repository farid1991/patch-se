#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "main.h"
#include "nanoexif.h"
#include "tag_list.h"
#include "tag_parser.h"

void *malloc(int size)
{
#if defined(DB2020)
  return memalloc(NULL, size, 1, 5, "ExIf", NULL);
#elif defined(A2)
  return memalloc(-1, size, 1, 5, "ExIf", NULL);
#else
  return memalloc(size, 1, 5, "ExIf", NULL);
#endif
}

void mfree(void *mem)
{
  if (mem)
#if defined(DB2020)
    memfree(NULL, mem, "ExIf", NULL);
#elif defined(A2)
    memfree(NULL, mem, "ExIf", NULL);
#else
    memfree(mem, "ExIf", NULL);
#endif
}

bool tagid_and_shortdata_to_name(uint16_t tag_id, uint16_t data, char *name, char *value)
{
  bool skip = false;
  switch (tag_id)
  {
  case NANOEXIF_TAG_ORIENTATION:
    strcpy(name, "Orientation");
    strcpy(value, get_orientation(data));
    break;
  case NANOEXIF_TAG_RES_UNIT:
    strcpy(name, "Resolution Unit");
    strcpy(value, get_resolution_unit(data));
    break;
  case NANOEXIF_TAG_YCbCrPOSITIONING:
    strcpy(name, "YCbCr Positioning");
    strcpy(value, (data == 1) ? "Centered" : "Co-sited");
    break;
  case NANOEXIF_TAG_EXPOSURE_PROGRAM:
    strcpy(name, "Exposure Program");
    strcpy(value, get_exposure_program(data));
    break;
  case NANOEXIF_TAG_ISO_SPEED:
    strcpy(name, "ISO Speed");
    snprintf(value, 16, "ISO-%d", data);
    break;
  case NANOEXIF_TAG_METERING_MODE:
    strcpy(name, "Metering Mode");
    strcpy(value, get_metering_mode(data));
    break;
  case NANOEXIF_TAG_LIGHT_SOURCE:
    strcpy(name, "Light Source");
    strcpy(value, get_light_source(data));
    break;
  case NANOEXIF_TAG_FLASH_MODE:
    strcpy(name, "Flash Mode");
    strcpy(value, get_flash_mode(data));
    break;
  case NANOEXIF_TAG_CUSTOM_RENDERED:
    strcpy(name, "Custom Rendered");
    strcpy(value, get_custom_render(data));
    break;
  case NANOEXIF_TAG_EXPOSURE_MODE:
    strcpy(name, "Exposure Mode");
    strcpy(value, get_exposure_mode(data));
    break;
  case NANOEXIF_TAG_COLORSPACE:
    strcpy(name, "Colorspace");
    strcpy(value, get_colorspace(data));
    break;
  case NANOEXIF_TAG_SENSING_METHOD:
    strcpy(name, "Sensing Method");
    strcpy(value, get_sensing(data));
    break;
  case NANOEXIF_TAG_WHITE_BALANCE:
    strcpy(name, "White Balance");
    strcpy(value, data ? "Manual" : "Auto");
    break;
  case NANOEXIF_TAG_SCENE_CAPTURE_TYPE:
    strcpy(name, "Scene Capture Type");
    strcpy(value, get_scene(data));
    break;
  case NANOEXIF_TAG_CONTRAST:
    strcpy(name, "Contrast");
    strcpy(value, get_contrast_saturation(data));
    break;
  case NANOEXIF_TAG_SATURATION:
    strcpy(name, "Saturation");
    strcpy(value, get_contrast_saturation(data));
    break;
  case NANOEXIF_TAG_SHARPNESS:
    strcpy(name, "Sharpness");
    strcpy(value, get_sharpness(data));
    break;
  default:
    skip = true;
    break;
  }
  return skip;
}

bool tagid_and_rationaldata_to_name(uint16_t tag_id, uint32_t *data, char *name, char *value)
{
  bool skip = false;
  switch (tag_id)
  {
  case NANOEXIF_TAG_XRES:
    strcpy(name, "X Resolution");
    snprintf(value, 32, "%d dpi", data[0] / data[1]);
    break;
  case NANOEXIF_TAG_YRES:
    strcpy(name, "Y Resolution");
    snprintf(value, 32, "%d dpi", data[0] / data[1]);
    break;
  case NANOEXIF_TAG_EXPOSURETIME:
    strcpy(name, "Exposure Time");
    snprintf(value, 32, "1/%d sec", data[1] / data[0]);
    break;
  case NANOEXIF_TAG_F_NUMBER:
    strcpy(name, "F-Number");
    snprintf(value, 32, "f/%.1f", (float)(data[0] / data[1]));
    break;
  case NANOEXIF_TAG_EXPOSURE_COMP:
    strcpy(name, "Exposure Compensation");
    snprintf(value, 32, "%d/%d", data[0], data[1]);
    break;
  case NANOEXIF_TAG_SUBJECT_DISTANCE:
    strcpy(name, "Subject Distance");
    snprintf(value, 32, "%.2fmm", (float)(data[0] / data[1]));
    break;
  case NANOEXIF_TAG_FOCAL_LENGTH:
    strcpy(name, "Focal Length");
    snprintf(value, 32, "%.2f", (float)(data[0] / data[1]));
    break;
  case NANOEXIF_TAG_DIGITALZOOM_RATIO:
    strcpy(name, "Digital Zoom");
    snprintf(value, 32, "%.1f", (float)(data[0] / data[1]));
    break;
  case NANOEXIF_TAG_GPS_LATITUDE:
    strcpy(name, "GPS Latitude");
    snprintf(value, 32, "%d° %d' %d.%d\"", data[0], data[1], data[2], data[3]);
    break;
  case NANOEXIF_TAG_GPS_LONGITUDE:
    strcpy(name, "GPS Longitude");
    snprintf(value, 32, "%d° %d' %d.%d\"", data[0], data[1], data[2], data[3]);
    break;
  case NANOEXIF_TAG_GPS_ALTITUDE:
    strcpy(name, "GPS Altitude");
    snprintf(value, 32, "%d %d", data[0], data[1]);
    break;
  case NANOEXIF_TAG_GPS_TIMESTAMP:
    strcpy(name, "GPS Timestamp");
    snprintf(value, 32, "%02d:%02d:%02d", data[0], data[1], data[2]);
    break;
  default:
    skip = true;
    break;
  }
  return skip;
}

bool tagid_to_name(uint16_t tag_id, char *name)
{
  bool skip = false;
  switch (tag_id)
  {
  case NANOEXIF_TAG_MAKE:
    strcpy(name, "Camera Make");
    break;
  case NANOEXIF_TAG_MODEL:
    strcpy(name, "Camera Model");
    break;
  case NANOEXIF_TAG_SOFTWARE:
    strcpy(name, "Software");
    break;
  case NANOEXIF_TAG_DATETIME:
    strcpy(name, "Modify Date");
    break;
  case NANOEXIF_TAG_COPYRIGHT:
    strcpy(name, "Copyright");
    break;
  case NANOEXIF_TAG_DATETIME_ORI:
    strcpy(name, "Date/Time Original");
    break;
  case NANOEXIF_TAG_LENSMAKE:
    strcpy(name, "Lens Make");
    break;
  case NANOEXIF_TAG_LENSMODEL:
    strcpy(name, "Lens Model");
    break;
  case NANOEXIF_TAG_GPS_LATITUDE_REF:
    strcpy(name, "GPS LatRef");
    break;
  case NANOEXIF_TAG_GPS_LONGITUDE_REF:
    strcpy(name, "GPS LonRef");
    break;
  case NANOEXIF_TAG_GPS_SATELLITES:
    strcpy(name, "GPS Satellites");
    break;
  default:
    skip = true;
    break;
  }
  return skip;
}

void jpg_read_exif_tag(LIST *list, nanoexif *ne, uint32_t ifd_offset, uint16_t *processed_tags, uint16_t *processed_count)
{
  uint32_t next_ifd_offset;
  nanoexif_ifd_entry *entries;
  TAG_LIST_ELEM *tag_list;
  do
  {
    uint16_t cnt;
    entries = nanoexif_read_ifd(ne, ifd_offset, &next_ifd_offset, &cnt);

    for (int i = 0; i < cnt; i++)
    {
      BOOL already_processed = FALSE;
      for (int j = 0; j < *processed_count; j++)
      {
        if (processed_tags[j] == entries[i].tag)
        {
          already_processed = TRUE;
          break;
        }
      }

      if (already_processed)
      {
        continue;
      }

      processed_tags[*processed_count] = entries[i].tag;
      (*processed_count)++;

      bool skip;

      switch (entries[i].type)
      {
      case NANOEXIF_TYPE_RATIONAL:
      {
        uint32_t *data = nanoexif_get_ifd_entry_data_rational(ne, &entries[i]);
        char *name = (char *)malloc(MAX_NAME);
        char *value = (char *)malloc(MAX_VALUE);
        skip = tagid_and_rationaldata_to_name(entries[i].tag, data, name, value);
        if (!skip)
        {
          tag_list = tag_list_create_elem(entries[i].tag, name, value);
          List_InsertLast(list, tag_list);
        }
        mfree(name);
        mfree(value);
        mfree(data);
        break;
      }
      case NANOEXIF_TYPE_ASCII:
      {
        char *name = (char *)malloc(MAX_NAME);
        char *value = nanoexif_get_ifd_entry_data_ascii(ne, &entries[i]);
        skip = tagid_to_name(entries[i].tag, name);
        if (!skip)
        {
          tag_list = tag_list_create_elem(entries[i].tag, name, value);
          List_InsertLast(list, tag_list);
        }
        mfree(name);
        mfree(value);
        break;
      }
      case NANOEXIF_TYPE_SHORT:
      {
        uint16_t *data = nanoexif_get_ifd_entry_data_short(ne, &entries[i]);
        char *name = (char *)malloc(MAX_NAME);
        char *value = (char *)malloc(MAX_VALUE);
        skip = tagid_and_shortdata_to_name(entries[i].tag, *data, name, value);
        if (!skip)
        {
          tag_list = tag_list_create_elem(entries[i].tag, name, value);
          List_InsertLast(list, tag_list);
        }
        mfree(name);
        mfree(value);
        mfree(data);
        break;
      }
      }

      if (entries[i].tag == NANOEXIF_TAG_EXIF_OFFSET || entries[i].tag == NANOEXIF_TAG_GPS_INFO)
      {
        uint32_t *data = nanoexif_get_ifd_entry_data_long(ne, &entries[i]);
        uint32_t offset = *data;
        mfree(data);

        jpg_read_exif_tag(list, ne, offset, processed_tags, processed_count);
      }
    }
    ifd_offset = next_ifd_offset;
  } while (next_ifd_offset != 0);

  mfree(entries);
}

LIST *jpeg_read_exif_to_list(const wchar_t *path, const wchar_t *name)
{
  int file = _fopen(path, name, FSX_O_RDONLY, FSX_S_IREAD, NULL);
  if (file < 0)
  {
    return NULL;
  }

  uint32_t ifd_offset;
  nanoexif *ne = nanoexif_init(file, &ifd_offset);
  if (ne == NULL)
  {
    fclose(file);
    return NULL;
  }

  uint16_t processed_tags[MAX_TAGS];
  uint16_t processed_count = 0;

  LIST *list = List_Create();

  jpg_read_exif_tag(list, ne, ifd_offset, processed_tags, &processed_count);
  nanoexif_free(ne);
  fclose(file);

  return list;
}

extern "C" TEXTID patch_brw_jpg_info(TEXTID text_id, SUB_EXECUTE *sub_exec)
{
  wchar_t *path = FILEITEM_GetPath(sub_exec->file_item);
  wchar_t *name = FILEITEM_GetFname(sub_exec->file_item);

  LIST *tag_list = jpeg_read_exif_to_list(path, name);
  if (!tag_list)
  {
    return text_id;
  }

  int list_count = List_GetCount(tag_list);
  int exif_info_size = (MAX_NAME + MAX_VALUE) * list_count;

  char *exif_info = (char *)malloc(exif_info_size);
  memset(exif_info, 0, exif_info_size);
  snprintf(exif_info, exif_info_size, "\n=EXIF Info=");

  for (int i = 0; i < list_count; i++)
  {
    TAG_LIST_ELEM *tag_elem = (TAG_LIST_ELEM *)List_Get(tag_list, i);
    strncat(exif_info, "\n", 2);
    strncat(exif_info, tag_elem->name, tag_elem->name_len);
    strncat(exif_info, ": ", 3);
    strncat(exif_info, tag_elem->value, tag_elem->value_len);
  }

  TEXTID new_textid[2];
  new_textid[0] = text_id;
  new_textid[1] = TextID_Create(exif_info, ENC_LAT1, strlen(exif_info));

  mfree(exif_info);
  tag_list_destroy(tag_list, tag_list_remove_elem);

  return TextID_Create(new_textid, ENC_TEXTID, 2);
}
