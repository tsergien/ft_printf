/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 15:38:46 by tsergien          #+#    #+#             */
/*   Updated: 2018/05/01 16:01:56 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int		read_format(char *s, va_list *ap)
{
	char	buf[BUFF_SIZE];
	int		symbols;

	ft_bzero(buf, BUFF_SIZE);
	while (*s)
	{
		if (*s != '%')
			set_to_buf(buf, s++, 1);
		else if (*s == '%' && *(s + 1) == '%')
		{
			set_to_buf(buf, s, 1);
			s += 2;
		}
		else
		{
			symbols = write_value_to_buf(buf, ap, ++s);
			if (symbols < 0)
				return (0);
			s = s + symbols;
		}
	}
	putbuf(buf);
	return (1);
}

int		ft_printf(const char *format, ...)
{
	char	*p;
	va_list	ap;

	va_start(ap, format);
	p = (char *)format;
	if (!read_format(p, &ap))
		return (-1);
	va_end(ap);
	return (1);
}
