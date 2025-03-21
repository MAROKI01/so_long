/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntahadou <ntahadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 16:05:21 by ntahadou          #+#    #+#             */
/*   Updated: 2025/01/22 15:48:33 by ntahadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putstr(char *s, int *count)
{
	int	i;

	if (*count == -1)
		return ;
	if (s == NULL)
	{
		ft_putstr("(null)", count);
		return ;
	}
	i = 0;
	while (s[i])
	{
		if (write(1, &s[i], 1) == -1)
		{
			*count = -1;
			return ;
		}
		i++;
		(*count)++;
	}
}
