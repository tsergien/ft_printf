/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 12:22:27 by tsergien          #+#    #+#             */
/*   Updated: 2018/05/07 12:22:44 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int		is_s_conv(char c)
{
	if (c == 'c' || c == 's'
		|| c == '%' || c == 'S')
		return (1);
	return (0);
}

static int		no_conversion(char *s)
{
	while (*s)
	{
		if (!is_right_char(*s))
			return (1);
		if (is_conversion(*s))
			return (0);
		s++;
	}
	return (1);
}
int		set_conversion(char *s, t_specif *spec)
{
	if (no_conversion(s))
	{
		spec->conversion = 0;
		return (0);
	}
	spec->conversion = *s;
	if (is_zero(spec->flags) && spec->precision != 1
		&& !is_s_conv(spec->conversion))
			spec->flags ^= 1UL << 3;
	return (1);
}

int		is_long_conv(char c)
{
	if (c == 'U' || c == 'S' || c == 'D'
		|| c == 'C' || c == 'O' || c == 'p')
		return (1);
	return (0);
}

int		is_decimal(char c)
{
	if (c == 'U' || c == 'D' || c == 'u'
		 || c == 'd' || c == 'i')
		return (1);
	return (0);
}

