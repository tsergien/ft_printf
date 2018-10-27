/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 11:52:09 by tsergien          #+#    #+#             */
/*   Updated: 2018/05/04 11:52:21 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			is_conversion(char c)
{
	if (c == 's' || c == 'S' || c == 'p' ||
		c == 'd' || c == 'D' || c == 'i' ||
		c == 'o' || c == 'O' || c == 'u' ||
		c == 'U' || c == 'x' || c == 'X' ||
		c == 'c' || c == 'C' || c == '%')
		return (1);
	return (0);
}

int			is_flag(char c)
{
	if (c == '#' || c == '0' || c == '-' ||
		c == '+' || c == ' ')
		return (1);
	return (0);
}

int			is_size_mod(char c)
{
	if (c == 'h' || c == 'l' ||
		c == 'j' || c == 'z')
		return (1);
	return (0);
}

int			is_right_char(char c)
{
	if (is_flag(c) || is_conversion(c) ||
		is_size_mod(c) || ft_isdigit(c) ||
		c == '.' || c == '*')
		return (1);
	return (0);
}
