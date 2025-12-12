CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

FTPRINTF = ft_printf/libftprintf.a

SRCS = main.c error.c push_ops.c push_swap.c reverse_rotate_ops.c rotate_ops.c split.c swap_ops.c utils.c

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