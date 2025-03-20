/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntahadou <ntahadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:52:03 by ntahadou          #+#    #+#             */
/*   Updated: 2025/02/02 16:36:04 by ntahadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h" // Include libft header
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

// Helper function to append a single character to the buffer
void	ft_append_char(char **result, char c)
{
	*(*result)++ = c;
}

// Helper function to append a string to the buffer
void	ft_append_string(char **result, const char *str)
{
	const char	*null_str;

	if (str)
	{
		while (*str)
		{
			ft_append_char(result, *str++);
		}
	}
	else
	{
		null_str = "(null)";
		while (*null_str)
		{
			ft_append_char(result, *null_str++);
		}
	}
}

// Helper function to append an integer to the buffer
void	ft_append_integer(char **result, int value)
{
	char	*tmp;

	tmp = ft_itoa(value);
	if (tmp)
	{
		ft_append_string(result, tmp);
		free(tmp); // Free memory allocated by ft_itoa
	}
}

// Helper function to process the format specifier '%s'
void	ft_process_s(char **result, va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	ft_append_string(result, str);
}

// Helper function to process the format specifier '%d' or '%i'
void	ft_process_d(char **result, va_list args)
{
	int	value;

	value = va_arg(args, int);
	ft_append_integer(result, value);
}

// Main sprintf implementation
int	ft_sprintf(char *buffer, const char *format, ...)
{
	va_list	args;
	char	*result;

	va_start(args, format);
	result = buffer;
	while (*format)
	{
		if (*format != '%')
		{
			ft_append_char(&result, *format++);
		}
		else
		{
			format++; // Skip the '%' character
			if (*format == '\0')
			{
				break ; // End of format string
			}
			// Process format specifiers
			if (*format == 's')
			{
				ft_process_s(&result, args);
			}
			else if (*format == 'd' || *format == 'i')
			{
				ft_process_d(&result, args);
			}
			format++; // Move to the next character after the format specifier
		}
	}
	*result = '\0'; // Null-terminate the result string
	va_end(args);
	return (ft_strlen(buffer)); // Return the length of the formatted string
}
