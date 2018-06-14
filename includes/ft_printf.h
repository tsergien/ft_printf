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
# define BUFF_SIZE 500

typedef struct		s_specif
{
	char			flags;
	size_t			width;
	int				precision;
	char			conversion;
	short int		size_mod;
}					t_specif;

typedef struct		s_buf
{
	char			buf[BUFF_SIZE];
	int				printed;
}					t_buf;

int					ft_printf(const char *format, ...);

/*
**********************CHECK VALID*************
*/

int					is_conversion(char c);
int					is_long_conv(char c);
int					is_flag(char c);
int					is_valid(char *str);
int					is_decimal(char c);
int					is_right_char(char c);

/*
***********************BUF WORK****************
*/

void				putbuf(t_buf *buf, int *index);
void				set_to_buf(t_buf *buf, char const *src, int n);
int					write_value_to_buf(t_buf *buf, va_list *ap, char *s);
int					init(char *s, t_specif *spec, va_list *ap);

/*
***********************FLAGS...*************
*/

int					set_flags(char *s, t_specif *spec);
int					set_width(char *s, t_specif *spec, va_list *ap);
int					set_precision(char *s, t_specif *spec, va_list *ap);
int					set_size_mod(char *s, t_specif *spec);
int					set_conversion(char *s, t_specif *spec);
int					is_minus(char flags);
int					is_zero(char flags);
int					is_plus(char flags);
int					is_space(char flags);
int					is_hash(char flags);
int					is_short(int size_mod);
int					is_long(int size_mod);

int					print_specificator(t_buf *buf, va_list *ap, t_specif *spec);

/*
********** COVERSION cases funstions ******
*/

void				put_flags_uint(t_buf *buf, t_specif *spec,
					int len, unsigned long val);
void				put_flags_minus_uint(t_buf *buf, t_specif *spec,
					int len, unsigned long val);
void				put_flags_int(t_buf *buf, t_specif *spec, int num_len,
					intmax_t val);
void				put_flags_minus_int(t_buf *buf, t_specif *spec,
					int len, intmax_t val);

int					printf_uint(t_buf *buf, va_list *ap, t_specif *spec);
int					printf_int(t_buf *buf, va_list *ap, t_specif *spec);
int					printf_s(t_buf *buf, va_list *ap, t_specif *spec);

void				ft_itoa_buf(t_buf *buf, unsigned long value, size_t base,
					t_specif *spec);
void				ft_itoa_signed(t_buf *buf, intmax_t value);
int					num_len_signed(intmax_t n, int base);

/*
************************UINT**********
*/

void				add_precision_uint(t_buf *buf, t_specif *spec,
					unsigned int val);
void				add_precision_int(t_buf *buf, t_specif *spec, intmax_t val);
void				add_pads_uint(t_buf *buf, t_specif *spec,
					int len, unsigned int val);
void				add_pads_int(t_buf *buf, t_specif *spec,
					int len, intmax_t val);
void				add_pads_no_conv(t_buf *buf, t_specif *spec);
void				add_hash(t_buf *buf, t_specif *spec);

/*
************************INT***********
*/

void				add_sign(t_buf *buf, t_specif *spec, long int val);
int					get_base(const char c);
void				print_uni(intmax_t val, t_buf *buf);
int					wchar_len(wchar_t *s);
void				add_spaces(t_buf *buf, int is_zero, int n);

#endif
