CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

FTPRINTF = ft_printf/libftprintf.a

SRCS = push_swap_ops.c push_swap_split.c push_swap_utils.c  push_swap.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS) $(FTPRINTF)
	$(CC) $(CFLAGS) $^ -o $@ 

$(FTPRINTF) :
	$(MAKE) -C ft_printf/

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)
	$(MAKE) -C ft_printf/ clean

fclean : clean
	rm -f $(NAME)
	$(MAKE) -C ft_printf/ fclean

re: fclean all

.PHONY: all clean fclean re