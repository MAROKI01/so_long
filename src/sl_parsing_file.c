/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_parsing_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntahadou <ntahadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 00:28:50 by ntahadou          #+#    #+#             */
/*   Updated: 2025/03/21 00:29:01 by ntahadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_utils.h"

int	check_file(char *file)
{
	int	is_file_valid;

	is_file_valid = 0;
	if (ft_strnstr(file, ".ber", ft_strlen(file)))
		is_file_valid = 1;
	return (is_file_valid);
	return (0);
}
