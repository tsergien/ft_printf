/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 12:41:37 by tsergien          #+#    #+#             */
/*   Updated: 2018/05/07 12:41:46 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

/*
** ll/l - long long/unsiged long int(d, i, o, u, x, X)**
**  hh/h - char/ unsigned char ()d, i, o, u, x, X)    **
**  h - short/ unsigned short (d, i, o, u, x , X)     **
**  j - intmax_t or uintmax_t d, i, o, u, x, X,)      **
**  z - size_t          (d, i, o, u, x, X)            **
*/

int		is_short(int size_mod)
{
	if (size_mod == 1 || size_mod == 2)
		return (1);
	return (0);
}

int		is_long(int size_mod)
{
	if (size_mod == 4 || size_mod == 3
		|| size_mod == 5)
		return (1);
	return (0);
}

int		set_size_mod(char *s, t_specif *spec)
{
	spec->size_mod = 0;
	if ((*s == *(s + 1) || *s == *(s + 1)) && is_conversion(*(s + 2)))
	{
		if (*s == 'h' && *(s + 1) == 'h')
			spec->size_mod = 1;
		if (*s == 'l' && *(s + 1) == 'l')
			spec->size_mod = 3;
		return (2);
	}
	if (*s == 'h')
		spec->size_mod = 2;
	if (*s == 'l')
		spec->size_mod = 4;
	if (*s == 'j')
		spec->size_mod = 5;
	if (*s == 'z')
		spec->size_mod = 6;
	if (spec->size_mod)
		return (1);
	return (0);
}
