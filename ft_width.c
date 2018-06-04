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

void	add_pads_uint(char *buf, t_specif *spec, int len, uintmax_t val)
{
	char		pad;
	short int	base;

	base = get_base(spec->conversion);
	if (is_zero(spec->flags))
		pad = '0';
	else
		pad = ' ';
	if (base == 10 && (is_plus(spec->flags) ||
			is_space(spec->flags)) && val != 0)
			len--;
	if ((int)spec->precision > ft_num_len(val, base))
		len -= (int)spec->precision - ft_num_len(val, base);
	while (len-- && len > -1)
		set_to_buf(buf, &pad, 1);
}

void	add_pads_int(char *buf, t_specif *spec, int len, long int val)
{
	char		pad;
	short int	base;

	base = get_base(spec->conversion);
	if (is_zero(spec->flags))
		pad = '0';
	else
		pad = ' ';
	if (base == 10 && (is_plus(spec->flags) || val < 0 ||
			is_space(spec->flags)))
			len--;
	if ((int)spec->precision > ft_num_len(val, base))
		len -= (int)spec->precision - ft_num_len(val, base);
	while (len-- && len > -1)
		set_to_buf(buf, &pad, 1);
}