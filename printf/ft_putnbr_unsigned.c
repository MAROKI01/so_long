/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntahadou <ntahadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:45:39 by ntahadou          #+#    #+#             */
/*   Updated: 2024/11/19 12:05:14 by ntahadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned(unsigned int n, int *count)
{
	if (*count == -1)
		return ;
	if (n > 9)
	{
		ft_putnbr_unsigned(n / 10, count);
		ft_putnbr_unsigned(n % 10, count);
	}
	else
	{
		ft_putchar(n + '0', count);
	}
}
