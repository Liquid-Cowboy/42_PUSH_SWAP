# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnogueir <mnogueir@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/22 11:39:22 by mnogueir          #+#    #+#              #
#    Updated: 2025/12/22 11:39:22 by mnogueir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -I. -I srcs

NAME = push_swap

FT_PRINTF = $(FT_PRINTF_DIR)libftprintf.a

FT_PRINTF_DIR = srcs/ft_printf/

SRCS_DIR = srcs/push_swap

OBJS_DIR = objs

SRCS = $(shell find $(SRCS_DIR) -type f -name '*.c')

OBJS = $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

RM = rm -rf

all: $(NAME) $(OBJS_DIR)

$(NAME) : $(OBJS) $(FT_PRINTF)
	@$(CC) $(CFLAGS) $^ -o $@ -g

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ -g

$(FT_PRINTF) :
	@$(MAKE) -C srcs/ft_printf/

clean :
	@$(RM) $(OBJS_DIR)
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean

fclean : clean
	@$(RM) $(NAME)

re: fclean all

500: $(NAME)
	@./push_swap $(shell shuf -i 0-2000 -n 500) | wc -l

100: $(NAME)
	@./push_swap $(shell shuf -i 0-2000 -n 100) | wc -l

10: $(NAME)
	@./push_swap $(shell shuf -i 0-2000 -n 10) | wc -l

.PHONY: all clean fclean re