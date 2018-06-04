#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsergien <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/04 12:27:20 by tsergien          #+#    #+#              #
#    Updated: 2018/05/07 13:32:55 by tsergien         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC = 	ft_printf.c\
		ft_buf.c\
		ft_valid.c\
		ft_flags.c\
		ft_precision.c\
		ft_width.c\
		ft_conversion.c\
		ft_size_mod.c\
		ft_specificators.c\
		ft_check_flags.c\
		ft_itoa_buf.c\
		ft_setting_flags.c\
		ft_print_uint.c\
		ft_print_int.c\
		ft_print_s.c\
		ft_itoa_signed.c\
		ft_mask.c\

LIB_SRC = ft_atoi.c ft_bzero.c ft_isdigit.c ft_strlen.c ft_num_len.c

LIB_OBJ = $(LIB_SRC:.c=.o)

LIB = $(addprefix $(LIB_DIR), $(LIB_OBJ))

LIB_DIR = libft/

OBJ = $(SRC:.c=.o)

HEADER = includes/

all: $(NAME)

$(NAME):
		@make -C $(LIB_DIR) -silent
		@gcc $(FLAGS) -c $(SRC) -I$(HEADER)
		@ar rc $(NAME) $(OBJ) $(LIB)
		@echo "fortunate test compiled :)"

%.o: %.c
		@gcc $(FLAGS) $@ -c $<

norm:
		@norminette

clean:
		@@make clean -C $(LIB_DIR)
		@rm -f $(OBJ)

fclean: clean
		@@make fclean -C $(LIB_DIR)
		@rm -f $(NAME)

re: fclean all