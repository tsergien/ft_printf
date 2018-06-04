/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 15:40:12 by tsergien          #+#    #+#             */
/*   Updated: 2018/05/01 15:42:41 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include <stdint.h>
# include "../libft/includes/libft.h"
# define BUFF_SIZE 1024

typedef struct		s_specif
{
	char			flags;
	size_t			width;
	int				precision;
	char			conversion;
	short int		size_mod;
}					t_specif;

int		ft_printf(const char *format, ...);

//***********************CHECK VALID*************
int		is_conversion(char c);//
int		is_flag(char c);//
int		is_valid(char *str);///

//************************BUF WORK****************
void	putbuf(char *buf);
void	set_to_buf(char *buf, char const *src, int n);
int		write_value_to_buf(char *buf, va_list *ap, char *s);
int		init(char *s, t_specif *spec, va_list *ap);

//************************FLAGS...*************
int		set_flags(char *s, t_specif *spec);
int		set_width(char *s, t_specif *spec, va_list *ap);
int		set_precision(char *s, t_specif *spec, va_list *ap);
int		set_size_mod(char *s, t_specif *spec);
int		set_conversion(char *s, t_specif *spec);
int		is_minus(char flags);
int		is_zero(char flags);
int		is_plus(char flags);
int		is_space(char flags);
int		is_hash(char flags);
int		is_short(int size_mod);
int		is_long(int size_mod);

int		print_specificator(char *buf, va_list *ap, t_specif *spec);
//                   COVERSION cases funstions
void	put_flags_uint(char *buf, t_specif *spec, size_t len, uintmax_t val);
void	put_flags_minus_uint(char *buf, t_specif *spec, size_t len, uintmax_t val);
void	put_flags_int(char *buf, t_specif *spec, size_t len, long int val);
void	put_flags_minus_int(char *buf, t_specif *spec, size_t len, long int val);

uintmax_t		printf_uint(char *buf, va_list *ap, t_specif *spec);
uintmax_t		printf_int(char *buf, va_list *ap, t_specif *spec);
uintmax_t		printf_s(char *buf, va_list *ap, t_specif *spec);


void	ft_itoa_buf(char *buf, uintmax_t value, size_t base, t_specif *spec);
void	ft_itoa_signed(char *buf, long int value, t_specif *spec);
int		num_len_signed(long int n, int base);
//                   UINT
void	add_precision_uint(char *buf, t_specif *spec, uintmax_t val);
void	add_precision_int(char *buf, t_specif *spec, intmax_t val);
void	add_pads_uint(char *buf, t_specif *spec, int len, uintmax_t val);
void	add_pads_int(char *buf, t_specif *spec, int len, intmax_t val);
void	add_hash(char *buf, t_specif *spec);
//                      INT
void	add_sign(char *buf, t_specif *spec, long int val);


int		get_base(char c);
void	print_uni(intmax_t val, char *buf);
int		wchar_len(wchar_t *s);
void	add_spaces(char *buf, int n);

#endif
