/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 18:47:03 by tsergien          #+#    #+#             */
/*   Updated: 2018/05/05 18:47:20 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

/*
** set precision and return amount of digits + 1 *****
**(for '.') (how much should we shift string format)**
*/

static int	default_precision(char *s)
{
	while (*s && ft_isdigit(*s))
		s++;
	if (*s == 's' || *s == 'S')
		return (-1);
	return (1);
}

int			set_precision(char *s, t_specif *spec, va_list *ap)
{
	if (*s == '.')
	{
		if (is_zero(spec->flags))
			spec->flags ^= 1UL << 3;
		spec->precision = 0;
		s++;
		if (!ft_isdigit(*s))
			return (1);
		if (*s == '*')
		{
			spec->precision = va_arg(*ap, int);
			return (2);
		}
		spec->precision = ft_atoi(s);
		return (ft_num_len(spec->precision, 10) + 1);
	}
	spec->precision = default_precision(s);
	return (0);
}

void		add_precision_uint(t_buf *buf, t_specif *spec, uintmax_t val)
{
	int		n;
	int		len;

	len = ft_num_len(val, get_base(val));
	n = spec->precision - len;
	if (get_base(val) == 8 && is_hash(spec->flags) && val != 0)
		n--;
	while (n-- && n > -1)
		set_to_buf(buf, "0", 1);
}

void		add_precision_int(t_buf *buf, t_specif *spec, intmax_t val)
{
	int		n;
	int		l;
	int		base;

	base = get_base(val);
	l = num_len_signed(val, base);
	n = spec->precision - l;
	if (base == 8 && is_hash(spec->flags) && val != 0)
		n--;
	while (n-- > -1)
		set_to_buf(buf, "0", 1);
}
