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

#include "ft_printf.h"

void	put_flags_int(t_buf *buf, t_specif *spec, size_t len, long int val)
{
	if (!is_zero(spec->flags))
		add_pads_int(buf, spec, spec->width - len, val);
	if (val != 0)
		add_hash(buf, spec);
	add_sign(buf, spec, val);
	if (is_zero(spec->flags))
		add_pads_int(buf, spec, spec->width - len, val);
	add_precision_int(buf, spec, val);
	if (val == 0 && spec->precision == 0)
		return ;
	ft_itoa_signed(buf, val, spec);
}

void	put_flags_minus_int(t_buf *buf, t_specif *spec, size_t len, long val)
{
	if (val != 0)
		add_hash(buf, spec);
	add_sign(buf, spec, val);
	add_precision_int(buf, spec, val);
	if (val == 0 && spec->precision == 0 && spec->width < len)
		return ;
	ft_itoa_signed(buf, val, spec);
	add_pads_int(buf, spec, spec->width - len, val);
}

void	put_flags_uint(t_buf *buf, t_specif *spec, size_t len, uintmax_t val)
{
	short int		base;

	base = get_base(spec->conversion);
	if (!is_zero(spec->flags))
		add_pads_uint(buf, spec, spec->width - len, val);
	if (val != 0)
		add_hash(buf, spec);
	add_sign(buf, spec, val);
	if (is_zero(spec->flags))
		add_pads_uint(buf, spec, spec->width - len, val);
	add_precision_uint(buf, spec, val);
	if (val == 0 && spec->precision == 0)
		return ;
	ft_itoa_buf(buf, val, base, spec);
}

void	put_flags_minus_uint(t_buf *buf, t_specif *spec,
	size_t len, uintmax_t val)
{
	short int		base;

	base = get_base(spec->conversion);
	if (val != 0)
		add_hash(buf, spec);
	add_sign(buf, spec, val);
	add_precision_uint(buf, spec, val);
	if (val == 0 && spec->precision == 0 && spec->width < len)
		return ;
	ft_itoa_buf(buf, val, base, spec);
	add_pads_uint(buf, spec, spec->width - len, val);
}
