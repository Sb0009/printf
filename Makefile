# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nboute <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/04 20:02:22 by nboute            #+#    #+#              #
#    Updated: 2017/02/07 22:57:29 by nboute           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: make all clean fclean re

NAME = libftprintf.a

LIB = -L libft/ -lft

LIBFT = libft/libft.a

CFLAGS = -c -Wall -Wextra -Werror

CC = gcc

C_DIR = ./

SRCS = printf.c \
		flag_format.c \
		format_number.c \
		printf_numbers.c \
		parse_flags.c \
		spec_functions_2.c \
		spec_functions.c \
		spec_functions_3.c \
		utils.c \
		utils_2.c \
		utils_3.c \
		write.c

SRC = $(addprefix $(C_DIR), $(SRCS))

OBJ = $(SRCS:.c=.o)

INC = -I includes -I libft/

all : $(NAME)

$(NAME): $(OBJ)
	make -C libft
	cp $(LIBFT) $(NAME)
	rm -f $(LIBFT)
	ar rc $(NAME) $^

$(LIBFT):
	make -C libft/

$(OBJ) : $(SRC)
	$(CC) $(CFLAGS) $^ $(INC)

clean :
	make clean -C libft/
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
