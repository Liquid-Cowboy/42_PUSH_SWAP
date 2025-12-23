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
CFLAGS = -Wall -Wextra -Werror -I. -I srcs -I srcs/bonus
NAME = push_swap
FT_PRINTF = $(FT_PRINTF_DIR)libftprintf.a
FT_PRINTF_DIR = srcs/ft_printf/
MAKEFLAGS += --no-print-directory

SRCS_DIR = srcs/push_swap
OBJS_DIR = objs

COMMON_SRCS = $(shell find $(SRCS_DIR) -type f -name '*.c' ! -name 'main.c')
SRCS = $(COMMON_SRCS) $(SRCS_DIR)/main/main.c
OBJS = $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

BONUS_NAME = checker
BONUS_SRCS = $(COMMON_SRCS) srcs/bonus/checker.c
GNL = srcs/bonus/get_next_line.a

GREEN       = \033[0;32m
CYAN        = \033[0;36m
YELLOW      = \033[0;33m
RED         = \033[0;31m
RESET       = \033[0m
BOLD        = \033[1m

RM = rm -rf

all: $(NAME) $(OBJS_DIR)

$(NAME) : $(OBJS) $(FT_PRINTF)
	@echo "$(CYAN)🔗  Linking...$(BOLD)$(NAME)$(RESET)"
	@$(CC) $(CFLAGS) $^ -o $@ -g

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)⚙️  Compiling...$(RESET)$<"
	@$(CC) $(CFLAGS) -c $< -o $@ -g

$(FT_PRINTF) :
	@echo "$(YELLOW)🖨️  Compiling ft_printf..."
	@$(MAKE) -C srcs/ft_printf/

bonus : $(BONUS_NAME)

$(BONUS_NAME) : $(BONUS_SRCS) $(GNL) $(FT_PRINTF)
	@echo "$(YELLOW)➕  Compiling bonus..."
	@$(CC) $(CFLAGS) $^ -o $@ -g

clean :
	@echo "$(RED)🧹  Cleaning objects...$(RESET)"
	@$(RM) $(OBJS_DIR)
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean

fclean : clean
	@echo "$(RED)🗑   Removing binaries...$(RESET)"
	@$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

500: $(NAME)
	@echo "$(YELLOW)🧠  Testing $(GREEN)500$(YELLOW) random integers...$(RESET)"
	@./push_swap $(shell shuf -i 0-2000 -n 500) | wc -l

100: $(NAME)
	@echo "$(YELLOW)🧠  Testing $(GREEN)100$(YELLOW) random integers...$(RESET)"
	@./push_swap $(shell shuf -i 0-2000 -n 100) | wc -l

10: $(NAME)
	@echo "$(YELLOW)🧠  Testing $(GREEN)10$(YELLOW) random integers...$(RESET)"
	@./push_swap $(shell shuf -i 0-2000 -n 10) | wc -l

check_500 : $(NAME) $(BONUS_NAME)
	@echo "$(YELLOW)🧠  Does it sort $(GREEN)500$(YELLOW) random integers correctly? (OK/KO)$(RESET)"
	@ARG=$$(shuf -i 0-2000 -n 10); ./push_swap $$ARG | ./checker $$ARG

check_100: $(NAME) $(BONUS_NAME)
	@echo "$(YELLOW)🧠  Does it sort $(GREEN)100$(YELLOW) random integers correctly? (OK/KO)$(RESET)"
	@ARG=$$(shuf -i 0-2000 -n 10); ./push_swap $$ARG | ./checker $$ARG

check_10: $(NAME) $(BONUS_NAME)
	@echo "$(YELLOW)🧠  Does it sort $(GREEN)10$(YELLOW) random integers correctly? (OK/KO)$(RESET)"
	@ARG=$$(shuf -i 0-2000 -n 10); ./push_swap $$ARG | ./checker $$ARG

.PHONY: all clean fclean re bonus 500 100 10 check_500 check_100 check_10