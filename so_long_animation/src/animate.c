#include "../include/utils.h"
#include "../include/sprite.h"
#include "../include/libft.h"
#include "../../include/so_long_utils.h"

int animate_object(void *ptr, int object) {
    t_data *data = (t_data *)ptr;
    t_list *animation_node = data->sprites.coin.animations;

    if (object == 'C')
        animation_node = data->sprites.coin.animations;
    else if (object == 'A')
        animation_node = data->sprites.enemy.animations;

    while (animation_node) {
        t_animation *a = (t_animation *)animation_node->content;

        if (a->_tmp_delay++ == a->delay) {
            a->_tmp_delay = 0;
            a->current_frame_num++;
            a->current_frame_num %= ft_lstsize(a->frames);

            t_img *img = (t_img *)ft_lstget_anim(a->frames, a->current_frame_num)->content;
			// render_map(data);
                for (int row = 0; row < data->height; row++)
                  {
                     for (int col = 0; col < data->width; col++)
                         {
                            if (data->grid[row][col] == object)
                            {
                                // render_tile(data, img, col * IMG_SIZE, row * IMG_SIZE);
			                    render_player(data, img ,col * IMG_SIZE, row * IMG_SIZE);
                            }
                         }
                  }
			
            mlx_put_image_to_window(img->win.mlx_ptr, img->win.win_ptr, data->background.ptr, 0, 0);
        }
        animation_node = animation_node->next;
    }
	return(0);
}

int update_animations(void *ptr) {
    t_data *data = (t_data *)ptr;
    t_list *animation_node = data->current_sprite.animations;

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
        animate_object(data, 'C');
        animate_object(data, 'A');
	return(0);
}


t_sprite init_sprite(t_data *data, char *name, char *file_path, int frames, int width, int height)
{
    t_win tutorial = data->window;
    
    t_sprite s1 = new_sprite_anim(name, file_path, &tutorial);
    if (!s1.sprite_img.ptr) {
        destroy_sprite_anim(s1);
        destroy_window_anim(tutorial);
        return (s1);
    }
    sprite_slice slice1 = (sprite_slice){0, 0, width, height};
    ft_lstadd_back(&s1.animations, ft_lstnew(slice_sprite_anim(data, s1, slice1, frames, 10000, PLAYER)));
    printf("Sprite %s [%d %d], loaded %d animations\n", s1.name, s1.width, s1.height, ft_lstsize(s1.animations));
    data->sprite = s1;
    return (s1);
}

int intialize_animations(t_data *data)
{
    data->player.direction = LEFT;
        data->sprites.right = init_sprite(data, "right", "sprite_right.xpm",11,109,109);
        data->sprites.left = init_sprite(data, "left", "sprite_left.xpm",11,109,109);
        data->sprites.up = init_sprite(data, "up", "sprite_up.xpm",11,109,109);
        data->sprites.down = init_sprite(data, "down", "sprite_down.xpm",11,109,109);
        data->sprites.idle = init_sprite(data, "idle", "sprite_idle.xpm",25,109,109);
        data->sprites.coin = init_sprite(data, "coin", "coin.xpm",9,32,32);
        data->sprites.enemy = init_sprite(data, "enemy", "sprite_enemy.xpm",4,48,48);
    
    printf("data->direction %d\n", data->player.direction);
    return (0);
}

int animate(t_data *data)
{
 	if (!data->window.win_ptr)
        return (2);
    keys_function(data);
    // Update the animations; assume update_animations increments the frame and renders
    update_animations(data);
	return (0);
}
