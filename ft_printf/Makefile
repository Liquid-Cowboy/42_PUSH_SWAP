NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = specs/print_spec.c specs/print_char.c specs/print_str.c specs/print_ptr.c specs/print_digit.c specs/print_hex_up.c ft_printf.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $@ $^

#ft_printf.o : ft_printf.c
#	$(CC) $(CFLAGS) -c $^ -I. -o $@

specs/%.o : specs/%.c
	$(CC) $(CFLAGS) -c $^ -I. -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
