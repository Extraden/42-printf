/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:24:31 by dsemenov          #+#    #+#             */
/*   Updated: 2024/11/29 14:35:20 by dsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

int	ft_printf(const char *format, ...);
size_t   ft_putchar(char c);
size_t  ft_putstr(char *s);
size_t   num_len(int n);
size_t   ft_putnbr(int n);
int  ft_parse(va_list ap, const char c);

#endif