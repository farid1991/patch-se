#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

const char *get_colorspace(int color)
{
  switch (color)
  {
  case 1:
    return "sRGB";
  case 2:
    return "Adobe RGB";
  case 0xfffd:
    return "Wide Gamut RGB";
  case 0xfffe:
    return "ICC Profile";
  default:
    return "Uncalibrated";
  }
}

const char *get_contrast_saturation(int val)
{
  switch (val)
  {
  case 1:
    return "Low";
  case 2:
    return "High";
  default:
    return "Normal";
  }
}

const char *get_custom_render(int render)
{
  switch (render)
  {
  case 1:
    return "Custom";
  case 2:
    return "HDR (no original saved)";
  case 3:
    return "HDR (original saved)";
  case 4:
    return "Original (for HDR)";
  case 6:
    return "Panorama";
  case 7:
    return "Portrait HDR";
  case 8:
    return "Portrait";
  default:
    return "Normal";
  }
}

const char *get_exposure_mode(int mode)
{
  switch (mode)
  {
  case 0:
    return "Auto";
  case 1:
    return "Manual";
  default:
    return "Auto bracket";
  }
}

const char *get_exposure_program(int program)
{
  switch (program)
  {
  case 1:
    return "Manual";
  case 2:
    return "Program AE";
  case 3:
    return "Aperture-priority AE";
  case 4:
    return "Shutter speed priority AE";
  case 5:
    return "Creative (Slow speed)";
  case 6:
    return "Action (High speed)";
  case 7:
    return "Portrait";
  case 8:
    return "Landscape";
  case 9:
    return "Bulb";
  default:
    return "Not Defined";
  }
}

const char *get_flash_mode(int flash)
{
  switch (flash)
  {
  case 0x1:
    return "Fired";
  case 0x5:
    return "Fired, Return not detected";
  case 0x7:
    return "Fired, Return detected";
  case 0x8:
    return "On, Did not fire";
  case 0x9:
    return "On, Fired";
  case 0xd:
    return "On, Return not detected";
  case 0xf:
    return "On, Return detected";
  case 0x10:
    return "Off, Did not fire";
  case 0x14:
    return "Off, Did not fire, Return not detected";
  case 0x18:
    return "Auto, Did not fire";
  case 0x19:
    return "Auto, Fired";
  case 0x1d:
    return "Auto, Fired, Return not detected";
  case 0x1f:
    return "Auto, Fired, Return detected";
  case 0x20:
    return "No flash function";
  case 0x30:
    return "Off, No flash function";
  case 0x41:
    return "Fired, Red-eye reduction";
  case 0x45:
    return "Fired, Red-eye reduction, Return not detected";
  case 0x47:
    return "Fired, Red-eye reduction, Return detected";
  case 0x49:
    return "On, Red-eye reduction";
  case 0x4d:
    return "On, Red-eye reduction, Return not detected";
  case 0x4f:
    return "On, Red-eye reduction, Return detected";
  case 0x50:
    return "Off, Red-eye reduction";
  case 0x58:
    return "Auto, Did not fire, Red-eye reduction";
  case 0x59:
    return "Auto, Fired, Red-eye reduction";
  case 0x5d:
    return "Auto, Fired, Red-eye reduction, Return not detected";
  case 0x5f:
    return "Auto, Fired, Red-eye reduction, Return detected";
  default:
    return "No Flash";
  }
}

const char *get_light_source(int light_source)
{
  switch (light_source)
  {
  case 0:
    return "Unknown";
  case 1:
    return "Daylight";
  case 2:
    return "Fluorescent";
  case 3:
    return "Tungsten (Incandescent)";
  case 4:
    return "Flash";
  case 9:
    return "Fine Weather";
  case 10:
    return "Cloudy";
  case 11:
    return "Shade";
  case 12:
    return "Daylight Fluorescent";
  case 13:
    return "Day White Fluorescent";
  case 14:
    return "Cool White Fluorescent";
  case 15:
    return "White Fluorescent";
  case 16:
    return "Warm White Fluorescent";
  case 17:
    return "Standard Light A";
  case 18:
    return "Standard Light B";
  case 19:
    return "Standard Light C";
  case 20:
    return "D55";
  case 21:
    return "D65";
  case 22:
    return "D75";
  case 23:
    return "D50";
  case 24:
    return "ISO Studio Tungsten";
  default:
    return "Other";
  }
}

const char *get_metering_mode(int mode)
{
  switch (mode)
  {
  case 0:
    return "Unknown";
  case 1:
    return "Average";
  case 2:
    return "Center-weighted average";
  case 3:
    return "Spot";
  case 4:
    return "Multi-spot";
  case 5:
    return "Multi-segment";
  case 6:
    return "Partial";
  default:
    return "Other";
  }
}

const char *get_orientation(int orientation)
{
  switch (orientation)
  {
  case 1:
    return "Normal";
  case 2:
    return "Flip Horizontal";
  case 3:
    return "Rotate 180";
  case 4:
    return "Flip Vertical";
  case 5:
    return "Transpose";
  case 6:
    return "Rotate 90 CW";
  case 7:
    return "Transverse";
  case 8:
    return "Rotate 90 CCW";
  default:
    return "Unknown";
  }
}

const char *get_resolution_unit(int unit)
{
  switch (unit)
  {
  case 1:
    return "none";
  case 2:
    return "inches";
  default:
    return "cm";
  }
}

const char *get_sensing(int sense)
{
  switch (sense)
  {
  case 2:
    return "One-chip color area";
  case 3:
    return "Two-chip color area";
  case 4:
    return "Three-chip color area";
  case 5:
    return "Color sequential area";
  case 7:
    return "Trilinear";
  case 8:
    return "Color sequential linear";
  default:
    return "Not defined";
  }
}

const char *get_scene(int scene)
{
  switch (scene)
  {
  case 0:
    return "Standard";
  case 1:
    return "Landscape";
  case 2:
    return "Portrait";
  case 3:
    return "Night";
  default:
    return "Other";
  }
}

const char *get_sharpness(int sharp)
{
  switch (sharp)
  {
  case 1:
    return "Soft";
  case 2:
    return "Hard";
  default:
    return "Normal";
  }
}
