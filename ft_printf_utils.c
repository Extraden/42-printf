/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:49:00 by dsemenov          #+#    #+#             */
/*   Updated: 2024/12/04 15:42:36 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stddef.h>
 
size_t	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

size_t  ft_putstr(char *s)
{
	size_t	i;

	if (!s)
		s = "(null)";
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

size_t	num_len(int n)
{
	size_t	len;

	if (n == -2147483648)
		return (11);
	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	len++;
	return (len);
}

size_t	ft_putnbr(int n)
{
	size_t	nbr;

	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	nbr = n;
	if (n < 0)
	{
		nbr = -nbr;
		ft_putchar('-');
	}
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + '0');
	return (num_len(n));
}

size_t	ft_unsigned_putnbr(unsigned int n)
{
	size_t	len;

	len = 0;
	if (n >= 10)
		len += ft_unsigned_putnbr(n / 10);
	len += ft_putchar(n % 10 + '0');
	return (len);
}

size_t	ft_puthex(unsigned int nbr, char *base)
{
	size_t	len;

	len = 0;
	if (nbr >= 16)
		len += ft_puthex(nbr / 16, base);
	len += ft_putchar(base[nbr % 16]);
	return (len);
}

size_t	ft_putptr(unsigned long nbr, char *base)
{
	size_t	len;

	len = 0;
	if (nbr >= 16)
		len += ft_putptr(nbr / 16, base);
	len += ft_putchar(base[nbr % 16]);
	return (len);
}
