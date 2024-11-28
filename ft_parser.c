/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:56:14 by dsemenov          #+#    #+#             */
/*   Updated: 2024/11/28 18:02:35 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int	ft_parse(va_list ap, const char c)
{
	size_t	len;

	len = 0;
	if (c == 'c' || c == '%')
		len += ft_putchar(va_arg(ap, char));
	else if (c == 's')
		len += ft_putstr(va_arg(ap, char *));
	else if (c == 'd' || 'i')
		len += ft_putnbr(va_arg(ap, int));
	return (len);
}
