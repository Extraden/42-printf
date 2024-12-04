/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:49:25 by dsemenov          #+#    #+#             */
/*   Updated: 2024/12/04 15:39:09 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

int  ft_parse(va_list ap, const char c);
size_t  ft_putchar(char c);

int	ft_printf(const char *format, ...)
{
	size_t	len;
	va_list	ap;

	va_start(ap, format);
	len = 0;
	while (*format)
	{
		if (*format != '%')
			len += ft_putchar(*format);
		else if (*format == '%' && *(format + 1))
		{
			format++;
			if (*format == '%')
			{
				len += ft_putchar('%');
			}
			else
				len += ft_parse(ap, *format);
		}
		format++;
	}
	va_end(ap);
	return (len);
}

/*
#include <limits.h>
int	main(void)
{

	__builtin_printf("%d\n", ft_printf("%p", LONG_MIN));
	__builtin_printf("%d\n", __builtin_printf("%p", LONG_MIN));

}
*/
