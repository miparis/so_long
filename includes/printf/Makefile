# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miparis <miparis@student.42madrid.>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 09:51:47 by miparis           #+#    #+#              #
#    Updated: 2023/10/25 11:33:47 by miparis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

MY_SOURCES = ft_printf.c \
			 ft_putchar.c \
			 ft_putnbr.c \
			 ft_putstr.c \
			 ft_putunbr.c \
			 ft_puthexmin.c \
			 ft_puthexmax.c \
			 ft_putptr.c 

MY_OBJECTS = $(MY_SOURCES:.c=.o)

INCLUDE = libftprintf.h

CFLAGS = -Wall -Werror -Wextra

CC = gcc

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	@ar rcs $(NAME) $(MY_OBJECTS)

clean:
	@rm -f $(MY_OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
	
