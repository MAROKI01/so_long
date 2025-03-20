/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntahadou <ntahadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:57:28 by ntahadou          #+#    #+#             */
/*   Updated: 2025/03/20 17:57:29 by ntahadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../../include/libft.h"
# include "../../include/structers_and_includes.h"
# include "animation.h"
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

t_img			new_img_anim(int w, int h, t_win window);
t_img			new_file_img_anim(char *path, t_win window);
void			destroy_image_anim(t_img img);
void			put_pixel_img_anim(t_img *img, int x, int y, int color);
void			destroy_window_anim(t_win w);
t_list			*ft_lstget_anim(t_list *lst, int index);
void			ft_lstiter_param_anim(t_list *lst, void (*f)(void *, void *),
					void *ptr);
unsigned int	get_pixel_img_anim(t_img img, int x, int y);

#endif