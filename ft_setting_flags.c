/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setting_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 15:04:10 by tsergien          #+#    #+#             */
/*   Updated: 2018/05/11 15:04:28 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void			add_hash(t_buf *buf, t_specif *spec)
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

void	put_flags_int(t_buf *buf, t_specif *spec, int number_len, intmax_t val)
{
	if (!is_zero(spec->flags))
		add_pads_int(buf, spec, (spec->width - number_len), val);
	add_sign(buf, spec, val);
	if (is_zero(spec->flags))
		add_pads_int(buf, spec, (spec->width - number_len), val);
	add_precision_int(buf, spec, val);
	if (val == 0 && spec->precision == 0)
		return ;
	ft_itoa_signed(buf, val);
}

void	put_flags_minus_int(t_buf *buf, t_specif *spec,
		int len, intmax_t val)
{
	add_sign(buf, spec, val);
	add_precision_int(buf, spec, val);
	if (val == 0 && spec->precision == 0 && (int)spec->width < len)
		return ;
	ft_itoa_signed(buf, val);
	add_pads_int(buf, spec, spec->width - len, val);
}

void	put_flags_uint(t_buf *buf, t_specif *spec, int len, unsigned long val)
{
	short int		base;

	base = get_base(spec->conversion);
	if (!is_zero(spec->flags))
		add_pads_uint(buf, spec, spec->width - len, val);
	if (val != 0 || (val == 0 && spec->precision == 0)
		|| spec->conversion == 'p')
		add_hash(buf, spec);
	if (is_zero(spec->flags))
		add_pads_uint(buf, spec, spec->width - len, val);
	add_precision_uint(buf, spec, val);
	if (val == 0 && spec->precision == 0)
		return ;
	ft_itoa_buf(buf, val, base, spec);
}

void	put_flags_minus_uint(t_buf *buf, t_specif *spec,
	int len, unsigned long val)
{
	short int		base;

	base = get_base(spec->conversion);
	if (val != 0 || spec->conversion == 'p')
		add_hash(buf, spec);
	add_precision_uint(buf, spec, val);
	if (val == 0 && spec->precision == 0 && (int)spec->width < len)
		return ;
	ft_itoa_buf(buf, val, base, spec);
	add_pads_uint(buf, spec, spec->width - len, val);
}
