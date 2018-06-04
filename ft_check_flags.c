/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 16:42:11 by tsergien          #+#    #+#             */
/*   Updated: 2018/05/08 16:42:13 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		is_minus(char flags)
{
	if ((flags >> 4) % 2 == 1)
		return (1);
	return (0);
}

int		is_zero(char flags)
{
	if ((flags >> 3) % 2 == 1)
		return (1);
	return (0);
}

int		is_plus(char flags)
{
	if ((flags >> 2) % 2 == 1)
		return (1);
	return (0);
}

int		is_space(char flags)
{
	if ((flags >> 1) % 2 == 1)
		return (1);
	return (0);
}

int		is_hash(char flags)
{
	if ((flags >> 0) % 2 == 1)
		return (1);
	return (0);
}
