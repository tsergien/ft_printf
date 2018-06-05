/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 13:41:33 by tsergien          #+#    #+#             */
/*   Updated: 2018/05/14 13:42:58 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_sign(t_buf *buf, t_specif *spec, long int val)
{
	if (val < 0)
		set_to_buf(buf, "-", 1);
	else if (is_plus(spec->flags))
		set_to_buf(buf, "+", 1);
	else if (is_space(spec->flags))
		set_to_buf(buf, " ", 1);
}

static int		print_short(t_buf *buf, va_list *ap, t_specif *spec)
{
	short int		val;
	size_t			len;

	val = va_arg(*ap, int);
	len = num_len_signed(val, 10);
	if (!is_minus(spec->flags))
		put_flags_int(buf, spec, len, val);
	else
		put_flags_minus_int(buf, spec, len, val);
	return (1);
}

static int		print_default(t_buf *buf, va_list *ap, t_specif *spec)
{
	int				val;
	size_t			len;

	val = va_arg(*ap, int);
	len = num_len_signed(val, 10);
	if (!is_minus(spec->flags))
		put_flags_int(buf, spec, len, val);
	else
		put_flags_minus_int(buf, spec, len, val);
	return (1);
}

static int		print_long(t_buf *buf, va_list *ap, t_specif *spec)
{
	intmax_t		val;
	size_t			len;

	val = va_arg(*ap, intmax_t);
	len = num_len_signed(val, 10);
	if (!is_minus(spec->flags))
		put_flags_int(buf, spec, len, val);
	else
		put_flags_minus_int(buf, spec, len, val);
	return (1);
}

uintmax_t		printf_int(t_buf *buf, va_list *ap, t_specif *spec)
{
	uintmax_t		res;

	if (is_short(spec->size_mod))
		res = print_short(buf, ap, spec);
	else if (is_long(spec->size_mod) || spec->conversion == 'D')
		res = print_long(buf, ap, spec);
	else
		res = print_default(buf, ap, spec);
	return (res);
}