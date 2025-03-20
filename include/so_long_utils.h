/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntahadou <ntahadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 02:31:55 by ntahadou          #+#    #+#             */
/*   Updated: 2025/03/20 18:19:48 by ntahadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_UTILS_H
# define SO_LONG_UTILS_H

# include "structers_and_includes.h"

/*func to handle images*/
unsigned int	get_pixel_img(t_img src, int x, int y);
void			put_pixel_img(t_img *dest, int pixel, int x, int y);
void			put_img_to_img(t_img *dest, t_img *src, int x, int y);
t_img			new_file_img(char *path, t_data data);

/*func to handle keys*/
int				key_press(int keycode, void *data);
int				key_release(int keycode, void *data);
int				keys_function(void *param);

/*helper functions*/
void			init_player_pos(t_data *data);
int				object_counter(t_data *data, char object);

/*clean up function*/
void			clean_up(t_data *data);

/*get next line function*/
char			*get_next_line(int fd);

/*to read and render the map*/
int				check_line_length(char *line, int width);
int				render_map(t_data *data);
int				read_map(t_data *data, char *filename);
void			load_textures(t_data *data);
void			render_tile(t_data *data, t_img *tile, int x, int y);
void			render_player(t_data *data, t_img *tile, int x, int y);

/*manage hooks*/
void			manage_hooks(t_data *data);

/*func to count the number of each element*/
int				object_counter(t_data *data, char object);

/*parsing map algo*/
void			bfs(t_bfs_params params);
int				map_checker(t_data *data);
int				check_file(char *file);

/*for the counter*/
void			graphic_counter(t_data *data);

/*Animation*/
void			load_frames(t_data *data);
int				animation(t_data *data);
int				animate(t_data *data);
int				update_animations(void *ptr);
t_sprite		init_sprite(t_data *data, char *file_path, int frames,
					t_sprite_slice slice);
int				intialize_animations(t_data *data);

void			move_enemies(t_data *data);
void			initialize_enemies(t_data *data);
 int	is_valid_move(t_data *data, int new_x, int new_y);
 void	process_enemy_move(t_data *data, int i, int new_x, int new_y);
 void	change_enemy_direction(t_data *data, int i);
 void	calculate_new_position(t_data *data, int i, int *new_x, int *new_y);
 int	is_player_nearby(t_data *data, int enemy_x, int enemy_y);

void	free_sprites(t_data *data);
void	free_animation(t_data *data);
#endif