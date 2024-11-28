/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:49:25 by dsemenov          #+#    #+#             */
/*   Updated: 2024/11/28 16:44:03 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>

int ft_putchar(char c);

int	ft_putstr(char *s);

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
		else if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				len += ft_putchar('%');
				format++;
			}
			else
				ft_parse(va_arg(ap, c));
		}
		format++;
	}
	va_end(ap);
	return (len);
}

int	main(void)
{
	__builtin_printf("%d", ft_printf("Hello"));

}
