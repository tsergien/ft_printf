/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 20:01:00 by tsergien          #+#    #+#             */
/*   Updated: 2018/05/04 20:01:18 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int		get_flag_index(char c)
{
	if (c == '-')
		return (4);
	if (c == '0')
		return (3);
	if (c == '+')
		return (2);
	if (c == ' ')
		return (1);
	if (c == '#')
		return (0);
	return (-1);
}

/*
** set flags and return their          **
**amount(how much shift string format  **
*/

int				set_flags(char *s, t_specif *spec)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	spec->flags = 0;
	while (is_flag(s[j]))
	{
		i = get_flag_index(s[j]);
		spec->flags |= 1UL << i;
		j++;
	}
	return (j);
}
