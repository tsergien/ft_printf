/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 16:26:35 by tsergien          #+#    #+#             */
/*   Updated: 2018/05/18 16:26:55 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

/*
** ' ' undefined  **
** 0 undefined    **
** + undefined    **
** # undefined    **
*/

static int		long_c(t_buf *buf, va_list *ap, t_specif *spec)
{
	int			len;
	wchar_t		symb;

	symb = va_arg(*ap, wchar_t);
	if (symb <= 127)
		len = 1;
	else if (symb <= 2047)
		len = 2;
	else if (symb <= 65535)
		len = 3;
	else
		len = 4;
	if (symb == 0)
	{
		putbuf(buf, &symb);
		write(1, "\0", 1);
		buf->printed += 1;
	}
	if (!is_minus(spec->flags))
		add_spaces(buf, is_zero(spec->flags), spec->width - len);
	print_uni((int)symb, buf);
	if (is_minus(spec->flags))
		add_spaces(buf, is_zero(spec->flags), spec->width - len);
	return (1);
}

static int		print_char(t_buf *buf, va_list *ap, t_specif *spec)
{
	char		char_symbol;
	int			ind;

	if (spec->conversion == '%')
		char_symbol = '%';
	else
		char_symbol = (char)va_arg(*ap, int);
	if (!is_minus(spec->flags))
		add_spaces(buf, is_zero(spec->flags), spec->width - 1);
	set_to_buf(buf, &char_symbol, 1);
	if (char_symbol == 0)
	{
		putbuf(buf, &ind);
		write(1, "\0", 1);
		buf->printed += 1;
	}
	if (is_minus(spec->flags))
		add_spaces(buf, is_zero(spec->flags), spec->width - 1);
	return (1);
}

static int		long_s(t_buf *buf, va_list *ap, t_specif *spec)
{
	int			len;
	wchar_t		*s;
	int			min;

	len = 0;
	if (spec->precision == 0 && spec->width == 0)
		return (1);
	s = va_arg(*ap, wchar_t *);
	if (!s)
		set_to_buf(buf, NULL, 1);
	else
		len = wchar_len(s);
	if (spec->precision != -1)
		spec->precision = len;
	min = FT_MIN(len, spec->precision);
	len = min;
	if (!is_minus(spec->flags))
		add_spaces(buf, is_zero(spec->flags), spec->width - min);
	while (s && *s && len-- > 0)
	{
		print_uni((int)*s, buf);
		s++;
	}
	if (is_minus(spec->flags))
		add_spaces(buf, is_zero(spec->flags), spec->width - min);
	return (1);
}

static int		default_s(t_buf *buf, va_list *ap, t_specif *spec)
{
	va_list		cp;
	int			len;
	int			min;

	va_copy(cp, *ap);
	len = ft_strlen(va_arg(cp, char *));
	va_copy(cp, *ap);
	if (va_arg(cp, char *) == 0)
		len = 6;
	if (spec->precision == -1)
		spec->precision = len;
	min = FT_MIN(len, spec->precision);
	if (!is_minus(spec->flags))
		add_spaces(buf, is_zero(spec->flags), spec->width - min);
	if (!(spec->width > 0 && spec->precision == 0))
		set_to_buf(buf, va_arg(*ap, char *), min);
	if (is_minus(spec->flags))
		add_spaces(buf, is_zero(spec->flags), spec->width - min);
	return (1);
}

int				printf_s(t_buf *buf, va_list *ap, t_specif *spec)
{
	if (spec->conversion == 'c' || spec->conversion == '%')
		return (print_char(buf, ap, spec));
	if ((is_long(spec->size_mod) && spec->conversion == 's')
		|| spec->conversion == 'S')
		return (long_s(buf, ap, spec));
	if ((is_long(spec->size_mod) && spec->conversion == 'c')
		|| spec->conversion == 'C')
		return (long_c(buf, ap, spec));
	return (default_s(buf, ap, spec));
}
