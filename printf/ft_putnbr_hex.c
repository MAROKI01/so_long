/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntahadou <ntahadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:33:26 by ntahadou          #+#    #+#             */
/*   Updated: 2024/11/19 13:21:08 by ntahadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex(unsigned long n, int *count)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (*count == -1)
		return ;
	if (n >= 16)
	{
		ft_putnbr_hex(n / 16, count);
	}
	ft_putchar(hex[n % 16], count);
}
