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
int keys_function(int keycode, void *param);

/*func to handle physics*/
void gravity(t_data *data);

/*clean up function*/
void clean_up(t_data *data);

/*get next line function*/
char	*get_next_line(int fd);

/*to render the map*/
int    render_map(t_data *data);
int read_map(t_data *data, char *filename);
void load_textures(t_data *data);
void    render_tile(t_data *data, t_img *tile, int x, int y);
void    render_player(t_data *data, t_img *tile, int x, int y);

/*manage hooks*/
void manage_hooks(t_data *data);

/*func to count the number of each element*/
int object_counter(t_data *data, char object);

/*parsing map algo*/
void bfs(char **map, int width, int height, int p_x, int p_y, 
         int *collectibles, int *exit_found);
#endif