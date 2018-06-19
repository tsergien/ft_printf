/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mask.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:25:10 by tsergien          #+#    #+#             */
/*   Updated: 2018/05/22 16:25:11 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

/*
***  0x7FF = 2047       ****
***  0xFFFF = 65535     ****
***  0x80 = 128         ****
***  0xC0 = 192         ****
***  0xE0 = 224         ****
***  0xF0 = 240         ****
***                     ****
***  0x1F = 110x xxxx   ****
***  0x0F = 1110 xxxx   ****
***  0x07 = 1111 0xxx   ****
***  0x3F = 10xx xxxx   ****
*/

static void	get_mask(intmax_t val, int *mask)
{
	if (val <= 0x7F)
	{
		mask[0] = val;
		mask[1] = 0;
	}
	else if (val <= 0x7FF)
	{
		mask[0] = 0xC0 | ((val >> 6) & 0x1F);
		mask[1] = 0x80 | (val & 0x3F);
		mask[2] = 0;
	}
	else if (val <= 0xFFFF)
	{
		mask[0] = 0xE0 | ((val >> 12) & 0xF);
		mask[1] = 0x80 | ((val >> 6) & 0x3F);
		mask[2] = 0x80 | (val & 0x3F);
		mask[3] = 0;
	}
	else
	{
		mask[0] = 0xF0 | ((val >> 18) & 0x7);
		mask[1] = 0x80 | ((val >> 12) & 0x3F);
		mask[2] = 0x80 | ((val >> 6) & 0x3F);
		mask[3] = 0x80 | (val & 0x3F);
	}
}

void		print_uni(intmax_t val, t_buf *buf)
{
	char	tmp;
	int		i;
	int		mask[4];

	i = -1;
	while (++i < 4)
		mask[i] = 0;
	i = -1;
	get_mask(val, mask);
	while (mask[++i] != 0 && i < 4)
	{
		tmp = mask[i];
		set_to_buf(buf, &tmp, 1);
	}
}

int			wchar_len(wchar_t *s)
{
	int		len;
	int		len_of_byte;
	char	*byte;

	len = 0;
	while (*s)
	{
		len_of_byte = 0;
		byte = (char *)s;
		while (*byte)
		{
			len_of_byte++;
			byte++;
		}
		len += len_of_byte;
		s++;
	}
	return (len);
}

void		add_spaces(t_buf *buf, int is_zero, int n)
{
	char	pad;

	pad = is_zero ? '0' : ' ';
	while (n-- > 0)
		set_to_buf(buf, &pad, 1);
}
