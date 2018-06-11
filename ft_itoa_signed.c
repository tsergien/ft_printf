/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_signed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 15:22:57 by tsergien          #+#    #+#             */
/*   Updated: 2018/05/14 15:23:06 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			num_len_signed(long n, int base)
{
	int		l;

	l = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		l++;
		n = n / base;
	}
	return (l);
}

static void	fill_buf(t_buf *buf, int len, long int value)
{
	char	tmp;

	if (len > 1)
		fill_buf(buf, len - 1, value / 10);
	tmp = '0' + value % 10;
	set_to_buf(buf, &tmp, 1);
}

void		ft_itoa_signed(t_buf *buf, long int value, t_specif *spec)
{
	int		len;

	len = num_len_signed(value, 10);
	if (is_short(spec->size_mod) && value == -32768)
		set_to_buf(buf, "32768", 5);
	else if (value == -2147483648)
		set_to_buf(buf, "2147483648", 10);
	else
	{
		value = ABS(value);
		fill_buf(buf, len, value);
	}
}
