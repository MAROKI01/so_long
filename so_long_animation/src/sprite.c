#include "../include/utils.h"
#include "../include/sprite.h"

t_sprite	new_sprite_anim(char * name, char * file_path, t_win * win) {
	t_img	img;

	img = new_file_img_anim(file_path, *win);
	return (t_sprite){NULL, ft_strdup(name),
		ft_strdup(file_path), img, img.w, img.h, 0};
}

void	add_frame_anim(t_animation * a, t_sprite s, sprite_slice slice) {
	t_img *	frame;
	int i, j;

	frame = (t_img *)calloc(sizeof(t_img), 1);
	if (!frame)
		return ;
	*frame = new_img_anim(slice.width, slice.height, s.sprite_img.win);
	i = 0;
	while(i < slice.width) {
		j = 0;
		while(j < slice.height) {
//			put_pixel_img(*frame, slice.width - j, i, get_pixel_img(s.sprite_img, slice.x + j, slice.y + i));
			put_pixel_img_anim(frame, j, i, get_pixel_img_anim(s.sprite_img, slice.x + j, slice.y + i));
			j++;
		}
		i++;
	}
	ft_lstadd_back(&a->frames, ft_lstnew(frame));
}

t_animation *	slice_sprite_anim(t_sprite s, sprite_slice slice, int frames, int delay, enum entity e) {
	int i;
	t_animation *	a;

	a = (t_animation *)calloc(sizeof(t_animation), 1);
	if (!a)
		return NULL;
	*a = (t_animation){NULL, slice.width, slice.height, delay, 0, 0, 0, 0, e};
	i = 0;
	while (i < frames) {
		add_frame_anim(a, s, slice);
		slice.x += slice.width;
		if (slice.x >= s.width) {
			slice.x = 0;
			slice.y += slice.height;
		}
		i++;
	}
	return a;
}

void	destroy_sprite_anim(t_sprite s) {
	free(s.name);
	free(s.file_path);
	destroy_image_anim(s.sprite_img);
}