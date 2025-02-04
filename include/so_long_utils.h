#ifndef SO_LONG_UTILS_H
#define SO_LONG_UTILS_H

#include "structers_and_includes.h"

/*func to handle images*/ 
unsigned int get_pixel_img(t_img src, int x, int y);
void put_pixel_img(t_img *dest, int pixel, int x, int y);
void put_img_to_img(t_img *dest, t_img *src, int x, int y);
t_img	new_file_img(char *path, t_data data);

/*func to handle keys*/
int key_press(int keycode, void *data);
int key_release(int keycode, void *data);
int keys_function(void *param);

/*helper functions*/
void init_player_pos(t_data *data);
int object_counter(t_data *data, char object);

/*clean up function*/
void clean_up(t_data *data);

/*get next line function*/
char	*get_next_line(int fd);

/*to read and render the map*/
int check_line_length(char *line, int width);
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
int map_checker(t_data *data);

/*for the counter*/
void graphic_counter(t_data *data);

/*Animation*/
void load_frames(t_data *data);
int animation(t_data *data);
int animate(t_data *data);
#endif