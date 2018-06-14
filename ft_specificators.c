/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:45:41 by tsergien          #+#    #+#             */
/*   Updated: 2018/05/07 16:45:54 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int		printf_no_conv(t_buf *buf, t_specif *spec)
{
	if (is_minus(spec->flags))//
	{
		add_pads_no_conv(buf, spec);
	}
	else
	{
		add_pads_no_conv(buf, spec);	
	}
	return (1);
}

int		print_specificator(t_buf *buf, va_list *ap, t_specif *spec)
{
	if (spec->conversion == 0)
		return (printf_no_conv(buf, spec));
	if (spec->conversion == 'x' || spec->conversion == 'X'
		|| spec->conversion == 'o' || spec->conversion == 'O'
		|| spec->conversion == 'u' || spec->conversion == 'U'
		|| spec->conversion == 'p')
		return (printf_uint(buf, ap, spec));
	if (spec->conversion == 'd' || spec->conversion == 'i'
		|| spec->conversion == 'D')
		return (printf_int(buf, ap, spec));
	if (spec->conversion == 's' || spec->conversion == 'S'
		|| spec->conversion == 'c' || spec->conversion == 'C'
		|| spec->conversion == '%')
		return (printf_s(buf, ap, spec));
	return (0);
}
