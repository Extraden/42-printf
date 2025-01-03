/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:49:25 by dsemenov          #+#    #+#             */
/*   Updated: 2024/12/09 13:04:06 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

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
