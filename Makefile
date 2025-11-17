CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap_lib.a

SRCS = push_swap_ops.c push_swap_split.c push_swap_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	ar rcs $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -g

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re