/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntahadou <ntahadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:07:46 by ntahadou          #+#    #+#             */
/*   Updated: 2025/02/02 16:02:50 by ntahadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_putchar(char c, int *count);
void	ft_putstr(char *s, int *count);
void	ft_putnbr_hex(unsigned long nbr, int *count);
void	ft_putnbr(long n, int *count);
void	ft_putnbr_unsigned(unsigned int n, int *count);
void	ft_putnbr_hex_lower(unsigned int nbr, int *count);
void	ft_putnbr_hex_upper(unsigned int nbr, int *count);
int ft_sprintf(char *buffer, const char *format, ...);
#endif