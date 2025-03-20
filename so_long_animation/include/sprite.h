/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntahadou <ntahadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:58:29 by ntahadou          #+#    #+#             */
/*   Updated: 2025/03/20 18:03:07 by ntahadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include "utils.h"

t_sprite	new_sprite_anim(char *name, char *file_path, t_win *win);
t_animation	*slice_sprite_anim(t_sprite_params params);
void		destroy_sprite_anim(t_sprite s);
#endif
