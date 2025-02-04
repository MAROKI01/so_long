#include "../include/utils.h"


void update_animaiton_anim(void * ptr) {
	t_animation * a;
	t_img *	img;

	a = (t_animation *)ptr;
	if (!a)
		return ;
	if (a->_tmp_delay++ == a->delay) {
		a->_tmp_delay = 0;
		a->current_frame_num++;
		a->current_frame_num %= ft_lstsize(a->frames);
		img = (t_img *)ft_lstget_anim(a->frames, a->current_frame_num)->content;
		mlx_put_image_to_window(img->win.mlx_ptr, img->win.win_ptr, img->ptr, 150, 150);
	}
}