# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miparis <miparis@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/28 09:40:51 by miparis           #+#    #+#              #
#    Updated: 2024/08/14 12:34:25 by miparis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

MY_SOURCES = src/main.c \
			src/map1.c \
			src/map2.c \
			src/map3.c \
			src/events.c \
			src/game.c \
			src/graphics.c \

OBJS = ${MY_SOURCES:.c=.o}

# Define Colors
GREEN  := \033[1;32m  # Bold Green
YELLOW := \033[0;33m  # Non-bold Yellow
RED    := \033[0;31m  # Regular Red
BLUE   := \033[1;34m  # Bold Blue
PURPLE := \033[1;35m  # Bold Purple
BOLD   := \033[1m     # Bold Text
NC     := \033[0m     # No Color (Resets color and style)


LIBFT_DIR = includes/libft
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF_DIR = includes/printf
PRINTF = $(PRINTF_DIR)/libftprintf.a
MLX_DIR = mlx_linux
MLX_LIB = $(MLX_DIR)/libmlx.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(LIBFT) $(PRINTF) $(MLX_LIB) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR) -s all
	@echo "$(BLUE)libft compiled$(NC)"

$(MLX_LIB):
	@make -C $(MLX_DIR) > /dev/null
	@echo "$(BLUE)mlx compiled$(NC)"

$(PRINTF):
	@make -C $(PRINTF_DIR) -s all
	@echo "$(BLUE)printf compiled$(NC)"

${NAME}: ${OBJS} $(MLX) $(LIBFT) $(PRINTF)
	@echo "$(PURPLE)👾so_long compiled$(NC)"
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm -lz -o $(NAME)

clean:
	@rm -f ${OBJS} ${BONUS_OBJS}
	@make -C $(LIBFT_DIR) -s clean
	@make -C $(PRINTF_DIR) -s clean
	@make -C $(MLX_DIR) clean > /dev/null

fclean: clean
	@echo "$(GREEN)Everything cleaned up$(NC)"
	@rm -f ${NAME}
	@make -C $(LIBFT_DIR) -s fclean
	@make -C $(PRINTF_DIR) -s fclean

re: fclean all
clear:
	@clear
run: clear re

.PHONY: all clean fclean re


