/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 14:20:20 by tsergien          #+#    #+#             */
/*   Updated: 2018/05/05 14:20:29 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	putbuf(t_buf *buf, int *index)
{
	*index = 0;
	buf->printed += ft_strlen(buf->buf);
	write(1, buf->buf, ft_strlen(buf->buf));
	ft_bzero(buf->buf, BUFF_SIZE);
}

void	set_to_buf(t_buf *buf, char const *src, int n)
{
	int		j;

	j = 0;
	while (buf->buf[j] != '\0' && j < BUFF_SIZE)
		j++;
	if (j >= BUFF_SIZE)
		putbuf(buf, &j);
	if (src == NULL)
		set_to_buf(buf, "(null)", 6);
	while (src && *src != '\0' && n)
	{
		if (j < BUFF_SIZE)
		{
			buf->buf[j] = *src;
			j++;
			src++;
			n--;
		}
		else
			putbuf(buf, &j);
	}
}

int		init(char *s, t_specif *spec, va_list *ap)
{
	char	*start_s;

	start_s = s;
	s += set_flags(s, spec);
	s += set_width(s, spec, ap);
	s += set_precision(s, spec, ap);
	s += set_size_mod(s, spec);
	s += set_conversion(s, spec);
	return (s - start_s);
}

/*
** return amoount of symbols after %   **
*/

int		write_value_to_buf(t_buf *buf, va_list *ap, char *s)
{
	int			symb;
	t_specif	spec;

	if (!is_valid(s))
		return (-1);
	symb = init(s, &spec, ap);
	if (print_specificator(buf, ap, &spec) == -1)
		return (-1);
	return (symb);
}
