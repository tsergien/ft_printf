/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 11:38:10 by tsergien          #+#    #+#             */
/*   Updated: 2018/05/03 20:21:26 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>

# define ABS(x) (x > 0 ? x : -x)
# define ft_max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })
# define ft_min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })

void				ft_bzero(void *s, size_t n);
size_t				ft_strlen(const char *s);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
int					ft_num_len(unsigned long n, size_t base);

#endif
