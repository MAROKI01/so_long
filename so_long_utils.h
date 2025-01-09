#ifndef SO_LONG_UTILS_H
#define SO_LONG_UTILS_H

#include "structers.h"

/*func to handle images*/ 
unsigned int get_pixel_img(t_img src, int x, int y);
void put_pixel_img(t_img *dest, int pixel, int x, int y);
void put_img_to_img(t_img *dest, t_img *src, int x, int y);
t_img	new_file_img(char *path, t_data data);

/*func to handle keys*/
int key_press(int keycode, void *param);
int key_release(int keycode, void *param);
int keys_function(void *param);

/*func to handle physics*/
int gravity(t_data *data);

/*clean up function*/
void clean_up(void *param);
#endif