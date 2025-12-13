CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

FTPRINTF = ft_printf/libftprintf.a

SRCS = main.c push_swap.c split.c error.c utils.c ops/swap_ops.c ops/push_ops.c ops/reverse_rotate_ops.c ops/rotate_ops.c  

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS) $(FTPRINTF)
	$(CC) $(CFLAGS) $^ -o $@ -g

$(FTPRINTF) :
	$(MAKE) -C ft_printf/

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -g

clean :
	rm -f $(OBJS)
	$(MAKE) -C ft_printf/ clean

fclean : clean
	rm -f $(NAME)
	$(MAKE) -C ft_printf/ fclean

re: fclean all

.PHONY: all clean fclean re