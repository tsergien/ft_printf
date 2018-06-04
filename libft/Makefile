#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsergien <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/21 11:42:01 by tsergien          #+#    #+#              #
#    Updated: 2018/05/07 12:23:51 by tsergien         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

HEADER = includes/

SRC = ft_atoi.c ft_bzero.c ft_isdigit.c ft_strlen.c ft_num_len.c


OBJ = $(SRC:.c=.o)

FLAGC = -Wall -Wextra -Werror

TILDA = *~

all: $(NAME)

$(NAME):
		@gcc $(FLAGS) -c $(SRC) -I $(HEADER)
		@ar rc $(NAME) $(OBJ)
		@echo "lib compiled successfully."

clean:
		@rm -f $(OBJ) $(TILDA)
		@echo "obj removed."

fclean: clean
		@rm -f $(NAME)
		@echo "lib removed."

re: fclean all