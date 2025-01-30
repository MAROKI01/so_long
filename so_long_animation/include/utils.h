#ifndef UTILS_H
# define UTILS_H

# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# include "libft.h"
# include "animation.h"
// # include "sprite.h"

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;	
	int		height;	
}		t_win;

typedef struct s_img
{
	t_win	win;
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
}		t_img;

/*Window and Images*/
t_win	new_window(int w, int h, char *str);
t_img	new_img(int w, int h, t_win window);
t_img	new_file_img(char * path, t_win window);
void	destroy_image(t_img img);
void	put_pixel_img(t_img img, int x, int y, int color);
void	destroy_window(t_win w);
t_list		*ft_lstget(t_list *lst, int index);
void		ft_lstiter_param(t_list *lst, void (*f)(void *, void *), void * ptr);
unsigned int	get_pixel_img(t_img img, int x, int y);

#endif