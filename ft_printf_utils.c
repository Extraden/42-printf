/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:49:00 by dsemenov          #+#    #+#             */
/*   Updated: 2024/11/28 17:55:49 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>
#include <limits.h>
 
size_t	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

size_t  ft_putstr(char *s)
{
	size_t	i;

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
	if (n < 0)
	{
		ft_putchar('-');
		
	}
	return (num_len(n));
}

int	main(void)
{
	__builtin_printf("%zu\n", ft_putnbr(-2147483648));
}
