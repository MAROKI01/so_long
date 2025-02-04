#include "../include/utils.h"
#include "../include/sprite.h"
#include "../include/libft.h"
#include "../../include/so_long_utils.h"

// int	update(t_list * list) {
// 	if (!list)
// 		return 1;
// 	ft_lstiter(list, update_animaiton_anim);
// 	return 0;
// }

int update_animations(void *ptr) {
    t_data *data = (t_data *)ptr;

    t_list *animation_node = data->sprite.animations;
    while (animation_node) {
        t_animation *a = (t_animation *)animation_node->content;

        if (a->_tmp_delay++ == a->delay) {
            a->_tmp_delay = 0;
            a->current_frame_num++;
            a->current_frame_num %= ft_lstsize(a->frames);

            t_img *img = (t_img *)ft_lstget_anim(a->frames, a->current_frame_num)->content;
			
			render_map(data);

			render_player(data, img ,data->player.p_x ,data->player.p_y);
			
            mlx_put_image_to_window(img->win.mlx_ptr, img->win.win_ptr, data->background.ptr, 0, 0);
        }
        animation_node = animation_node->next;
    }
	return(0);
}

int animate(t_data *data)
{
 	t_win	tutorial;
	
	tutorial = data->window;
	if (!tutorial.win_ptr)
		return (2);
	{
		/* Sprites */
		t_sprite s1 = new_sprite_anim("link", "sprite.xpm", &tutorial);
		if (!s1.sprite_img.ptr) {
			destroy_sprite_anim(s1);
			destroy_window_anim(tutorial);
			return (1);
		}
		sprite_slice slice1 = (sprite_slice){0, 0, 109, 109};
		ft_lstadd_back(&s1.animations, ft_lstnew(slice_sprite_anim(data,s1, slice1, 11, 10000, PLAYER)));
		printf("Sprite %s [%d %d], loaded %d animations\n", s1.name, s1.width, s1.height, ft_lstsize(s1.animations));
		data->sprite = s1;
		mlx_loop_hook(tutorial.mlx_ptr, update_animations, data);
	}
	mlx_loop(data->mlx);
	destroy_window_anim(tutorial);
	return (0);
}
