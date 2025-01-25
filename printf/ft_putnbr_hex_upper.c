/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_upper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntahadou <ntahadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:33:26 by ntahadou          #+#    #+#             */
/*   Updated: 2025/01/22 15:48:22 by ntahadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putnbr_hex_upper(unsigned int n, int *count)
{
	char	*hex;

	hex = "0123456789ABCDEF";
	if (*count == -1)
		return ;
	if (n >= 16)
	{
		ft_putnbr_hex_upper(n / 16, count);
	}
	ft_putchar(hex[n % 16], count);
}
