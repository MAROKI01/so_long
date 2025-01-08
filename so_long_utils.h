#ifndef SO_LONG_UTILS_H
#define SO_LONG_UTILS_H

#include "structers.h"

unsigned int get_pixel_img(t_img src, int x, int y);
void put_pixel_img(t_img *dest, int pixel, int x, int y);
void put_img_to_img(t_img *dest, t_img *src, int x, int y);
t_img	new_file_img(char *path, t_data data);

#endif