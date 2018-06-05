/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_buf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 12:21:50 by tsergien          #+#    #+#             */
/*   Updated: 2018/05/11 12:22:00 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	to_base(uintmax_t value)
{
	if (value <= 9)
		return ('0' + value);
	if (value > 9 && value <= 15)
		return ('a' + value - 10);
	else
		return (0);
}

static char	to_base_up(uintmax_t value)
{
	if (value <= 9)
		return ('0' + value);
	if (value > 9 && value <= 15)
		return ('A' + value - 10);
	else
		return (0);
}

static void	fill_s(t_buf *buf, int len, uintmax_t value, size_t base)
{
	char	tmp;

	if (len > 1)
		fill_s(buf, len - 1, value / base, base);
	tmp = to_base(value % base);
	set_to_buf(buf, &tmp, 1);
}

static void	fill_s_high(t_buf *buf, int len, uintmax_t value, size_t base)
{
	char	tmp;

	if (len > 1)
		fill_s_high(buf, len - 1, value / base, base);
	tmp = to_base_up(value % base);
	set_to_buf(buf, &tmp, 1);
}

void	ft_itoa_buf(t_buf *buf, uintmax_t value, size_t base, t_specif *spec)
{
	int		len;
	char	c;

	c = spec->conversion;
	len = ft_num_len(value, base);
	if (c == 'x' || c == 'o' || c == 'O')
		fill_s(buf, len, value, base);
	if (c == 'X')
		fill_s_high(buf, len, value, base);
}
