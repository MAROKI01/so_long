/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_read_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntahadou <ntahadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 00:29:06 by ntahadou          #+#    #+#             */
/*   Updated: 2025/03/21 02:47:26 by ntahadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_utils.h"

int	check_line_length(char *line, int width)
{
	int	len;

	if (!line)
		return (0);
	len = ft_strlen(line);
	if (line[len - 1] == '\n')
	{
		len--;
	}
	return (len != width);
}
