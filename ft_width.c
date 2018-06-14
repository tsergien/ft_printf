/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 18:37:45 by tsergien          #+#    #+#             */
/*   Updated: 2018/05/05 18:37:58 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

/*
** set width and return amount of digits   **
** (how much should we shift string format)**
*/

int		set_width(char *s, t_specif *spec, va_list *ap)
{
	if (*s == '*')
	{
		spec->width = va_arg(*ap, int);
		return (1);
	}
	if (ft_isdigit(*s))
	{
		spec->width = ft_atoi(s);
		return (num_len_signed(spec->width, 10));
	}
	spec->width = 0;
	return (0);
}

void	add_pads_uint(t_buf *buf, t_specif *spec, int len, unsigned int val)
{
	char		pad;
	short int	base;

	base = get_base(spec->conversion);
	if (is_zero(spec->flags) && !is_minus(spec->flags))
		pad = '0';
	else
		pad = ' ';
	if (val == 0 && spec->precision == 0)
		len++;
	if (base == 10 && (is_plus(spec->flags) ||
		is_space(spec->flags)) && val != 0)
		len--;
	if (spec->precision > ft_num_len(val, base))
		len -= spec->precision - ft_num_len(val, base);
	while (len-- > 0)
		set_to_buf(buf, &pad, 1);
}

void	add_pads_int(t_buf *buf, t_specif *spec, int pads_amount, long int val)
{
	char		pad;
	short int	b;

	b = get_base(spec->conversion);
	if (is_zero(spec->flags) && !is_minus(spec->flags))
		pad = '0';
	else
		pad = ' ';
	if (val == 0 && spec->precision == 0)
		pads_amount++;
	if (b == 10 && (is_plus(spec->flags) || val < 0 ||
		is_space(spec->flags)))
		pads_amount--;
	if (spec->precision > num_len_signed(val, b))
		pads_amount -= spec->precision - num_len_signed(val, b);
	while (pads_amount-- > 0)
		set_to_buf(buf, &pad, 1);
}

void	add_pads_no_conv(t_buf *buf, t_specif *spec)
{
	char		pad;
	int			amount_pads;
	int			ind;

	putbuf(buf, &ind);
	amount_pads = spec->width - buf->printed;
	if (is_zero(spec->flags) && !is_minus(spec->flags))
		pad = '0';
	else
		pad = ' ';
	if (is_plus(spec->flags) || is_space(spec->flags))
		amount_pads--;
	if (spec->precision > amount_pads)
		return ;
	while (amount_pads-- > 0)
		set_to_buf(buf, &pad, 1);
}
