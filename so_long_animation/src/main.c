#include "../include/utils.h"
#include "../include/sprite.h"
#include "../include/libft.h"

int	update(t_list * list) {
	if (!list)
		return 1;
	ft_lstiter(list, update_animaiton);
	return 0;
}

int main(void)
{
 	t_win	tutorial;
	
	tutorial = new_window(600, 500, "animations");
	if (!tutorial.win_ptr)
		return (2);
	{
		/* Sprites */
		t_sprite s1 = new_sprite("link", "sprite.xpm", &tutorial);
		if (!s1.sprite_img.img_ptr) {
			destroy_sprite(s1);
			destroy_window(tutorial);
			return (1);
		}
		sprite_slice slice1 = (sprite_slice){0, 0, 256, 256};
		ft_lstadd_back(&s1.animations, ft_lstnew(slice_sprite(s1, slice1, 10, 10000, PLAYER)));
		printf("Sprite %s [%d %d], loaded %d animations\n", s1.name, s1.width, s1.height, ft_lstsize(s1.animations));
		mlx_loop_hook(tutorial.mlx_ptr, update, s1.animations);
	}
	mlx_loop(tutorial.mlx_ptr);
	destroy_window(tutorial);
	return (0);
}