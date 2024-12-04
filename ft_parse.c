/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:56:14 by dsemenov          #+#    #+#             */
/*   Updated: 2024/12/04 18:18:17 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stddef.h>

size_t	ft_putchar(char c);
size_t	ft_putstr(char *s);
size_t	num_len(int n);
size_t	ft_putnbr(int n);
size_t	ft_puthex(unsigned int nbr, char *base);

static size_t	ft_parse_ptr(void *ptr)
{
	size_t	length;
	void	*pointer;

	length = 0;
	pointer = ptr;
	if (!pointer)
		length += write(1, "(nil)", 5);
	else
	{
		length += write(1, "0x", 2);
		length += ft_putptr((unsigned long) pointer, "0123456789abcdef");
	}
	return (length);
}

int	ft_parse(va_list ap, const char c)
{
	size_t	len;

	len = 0;
	if (c == 'c' || c == '%')
		len += ft_putchar(va_arg(ap, int));
	else if (c == 's')
		len += ft_putstr(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(ap, int));
	else if (c == 'u')
		len += ft_unsigned_putnbr(va_arg(ap, unsigned int));
	else if (c == 'x')
		len += ft_puthex(va_arg(ap, int), "0123456789abcdef");
	else if (c == 'X')
		len += ft_puthex(va_arg(ap, int), "0123456789ABCDEF");
	else if (c == 'p')
	{
		len += ft_parse_ptr(va_arg(ap, void *));
	}
	return (len);
}
