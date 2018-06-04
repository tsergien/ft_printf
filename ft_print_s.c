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

#include "ft_printf.h"

/*
** ' ' undefined  **
** 0 undefined    **
** + undefined    **
** # undefined    **
*/

static int		long_c(char *buf, va_list *ap, t_specif *spec)
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
	if (!is_minus(spec->flags))
		add_spaces(buf, spec->width - len);
	print_uni((int)symb, buf);
	if (is_minus(spec->flags))
		add_spaces(buf, spec->width - len);
	return (1);
}

static int		print_char(char *buf, int symbol, t_specif *spec)
{
	char		char_symbol;

	char_symbol = (char)symbol;
	if (!is_minus(spec->flags))
		add_spaces(buf, spec->width - 1);
	set_to_buf(buf, &char_symbol, 1);
	if (is_minus(spec->flags))
		add_spaces(buf, spec->width - 1);
	return (1);
}
//there are no precision here. so why does output depend on precision? if it is or not
static int		long_s(char *buf, va_list *ap, t_specif *spec)
{
	va_list		cp;
	int			len;
	wchar_t		*s;
	
	va_copy(cp, *ap);
	len = wchar_len(va_arg(cp, wchar_t *));
	s = va_arg(*ap, wchar_t *);
	if (!is_minus(spec->flags))
		add_spaces(buf, spec->width - len);
	while (*s)
	{
		print_uni((int)*s, buf);
		s++;
	}
	if (is_minus(spec->flags))
		add_spaces(buf, spec->width - len);
	return (1);
}

static int		default_s(char *buf, va_list *ap, t_specif *spec)
{
	va_list		cp;
	int			len;
	int			min;
	
	va_copy(cp, *ap);
	len = ft_strlen(va_arg(cp, char *));
	if (spec->precision == -1)
		spec->precision = len;
	min = ft_min(len, spec->precision);
	if (!is_minus(spec->flags))
		add_spaces(buf, spec->width - min);
	set_to_buf(buf, va_arg(*ap, char *), min);
	if (is_minus(spec->flags))
		add_spaces(buf, spec->width - min);
	return (1);
}

uintmax_t		printf_s(char *buf, va_list *ap, t_specif *spec)
{
	if (spec->conversion == 'c')
		return (print_char(buf, va_arg(*ap, int), spec));
	if ((is_long(spec->size_mod) && spec->conversion == 's') || spec->conversion == 'S') 
		return (long_s(buf, ap, spec));
	if ((is_long(spec->size_mod) && spec->conversion == 'c') || spec->conversion == 'C')
		return (long_c(buf, ap, spec)); 
	return (default_s(buf, ap, spec));
}