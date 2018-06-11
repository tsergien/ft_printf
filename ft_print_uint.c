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

#include "ft_printf.h"

void	add_hash(t_buf *buf, t_specif *spec)
{
	if (is_hash(spec->flags) && spec->conversion == 'X'
		&& spec->precision != 0)
		set_to_buf(buf, "0X", 2);
	else if ((is_hash(spec->flags) && spec->conversion == 'x'
		&& spec->precision != 0) || spec->conversion == 'p')
		set_to_buf(buf, "0x", 2);
	else if (is_hash(spec->flags) && (spec->conversion == 'O'
		|| spec->conversion == 'o'))
		set_to_buf(buf, "0", 1);
}

int		get_base(const char c)
{
	int		base;

	if (c == 'x' || c == 'X' || c == 'p')
		base = 16;
	else if (c == 'd' || c == 'i' || c == 'D'
		|| c == 'u' || c == 'U')
		base = 10;
	else
		base = 8;
	return (base);
}

int		printf_uint(t_buf *buf, va_list *ap, t_specif *spec)
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
