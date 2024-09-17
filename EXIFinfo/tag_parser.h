#ifndef _TagParser_H_
#define _TagParser_H_

const char *get_colorspace(int color);
const char *get_contrast_saturation(int val);
const char *get_custom_render(int render);
const char *get_exposure_mode(int mode);
const char *get_exposure_program(int program);
const char *get_flash_mode(int flash);
const char *get_light_source(int light_source);
const char *get_metering_mode(int mode);
const char *get_orientation(int orientation);
const char *get_resolution_unit(int unit);
const char *get_scene(int scene);
const char *get_sensing(int sense);
const char *get_sharpness(int sharp);

#endif
