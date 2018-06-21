/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ox.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 12:29:44 by tsergien          #+#    #+#             */
/*   Updated: 2018/05/13 12:30:06 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int				get_base(const char c)
{
	int		base;

	if (c == 'x' || c == 'X' || c == 'p')
		base = 16;
	else if (c == 'O' || c == 'o')
		base = 8;
	else
		base = 10;
	return (base);
}

static int		uint_short(t_buf *buf, va_list *ap, t_specif *spec)
{
	int				len;
	short int		base;
	unsigned short	val;

	val = (unsigned short)va_arg(*ap, unsigned int);
	base = get_base(spec->conversion);
	len = ft_num_len(val, base);
	if ((is_hash(spec->flags) && val != 0 &&
		(spec->conversion == 'x' || spec->conversion == 'X'))
		|| spec->conversion == 'p')
		len += 2;
	if (is_hash(spec->flags) && val != 0 &&
		(spec->conversion == 'o' || spec->conversion == 'O'))
		len += 1;
	if (!is_minus(spec->flags))
		put_flags_uint(buf, spec, len, val);
	else
		put_flags_minus_uint(buf, spec, len, val);
	return (1);
}

static int		uint_default(t_buf *buf, va_list *ap, t_specif *spec)
{
	int				len;
	short int		base;
	unsigned int	val;

	val = va_arg(*ap, unsigned int);
	base = get_base(spec->conversion);
	len = ft_num_len(val, base);
	if ((is_hash(spec->flags) && val != 0 &&
		(spec->conversion == 'x' || spec->conversion == 'X'))
		|| spec->conversion == 'p')
		len += 2;
	if (is_hash(spec->flags) && val != 0 &&
		(spec->conversion == 'o' || spec->conversion == 'O'))
		len += 1;
	if (!is_minus(spec->flags))
		put_flags_uint(buf, spec, len, val);
	else
		put_flags_minus_uint(buf, spec, len, val);
	return (1);
}

static int		uint_long(t_buf *buf, va_list *ap, t_specif *spec)
{
	int				len;
	short int		base;
	uintmax_t		val;

	val = va_arg(*ap, uintmax_t);
	base = get_base(spec->conversion);
	len = ft_num_len(val, base);
	if ((is_hash(spec->flags) && val != 0 &&
		(spec->conversion == 'x' || spec->conversion == 'X'))
		|| spec->conversion == 'p')
		len += 2;
	if (is_hash(spec->flags) && val != 0 &&
		(spec->conversion == 'o' || spec->conversion == 'O'))
		len += 1;
	if (!is_minus(spec->flags))
		put_flags_uint(buf, spec, len, val);
	else
		put_flags_minus_uint(buf, spec, len, val);
	return (1);
}

int				printf_uint(t_buf *buf, va_list *ap, t_specif *spec)
{
	if (is_long_conv(spec->conversion) || is_long(spec->size_mod))
		uint_long(buf, ap, spec);
	else if (is_short(spec->size_mod))
		uint_short(buf, ap, spec);
	else
		uint_default(buf, ap, spec);
	return (1);
}
