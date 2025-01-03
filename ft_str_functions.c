/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:19:22 by dsemenov          #+#    #+#             */
/*   Updated: 2024/12/09 13:14:38 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

size_t	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

size_t	ft_putstr(char *s)
{
	size_t	res;
	size_t	i;

	if (!s)
		s = "(null)";
	i = 0;
	res = 0;
	while (s[i])
	{
		res += ft_putchar(s[i]);
		i++;
	}
	return (res);
}
