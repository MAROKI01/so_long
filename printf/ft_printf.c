/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntahadou <ntahadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:07:42 by ntahadou          #+#    #+#             */
/*   Updated: 2024/11/19 13:34:32 by ntahadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	conversion(char c, va_list list, int *count)
{
	if (c == 'c')
		ft_putchar((char)va_arg(list, int), count);
	else if (c == 's')
		ft_putstr((char *)va_arg(list, char *), count);
	else if (c == 'p')
	{
		ft_putstr("0x", count);
		ft_putnbr_hex((unsigned long)va_arg(list, unsigned long), count);
	}
	else if (c == 'd' || c == 'i')
		ft_putnbr((long)va_arg(list, int), count);
	else if (c == 'u')
		ft_putnbr_unsigned((unsigned int)va_arg(list, unsigned int), count);
	else if (c == 'x')
		ft_putnbr_hex_lower((unsigned int)va_arg(list, unsigned int), count);
	else if (c == 'X')
		ft_putnbr_hex_upper((unsigned int)va_arg(list, unsigned int), count);
	else if (c != '\0')
		ft_putchar(c, count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	list;

	va_start(list, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			conversion(*(str + 1), list, &count);
			str++;
		}
		else
			ft_putchar(*str, &count);
		str++;
	}
	va_end(list);
	return (count);
}
