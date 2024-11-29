CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

OBJS = ft_printf.o ft_parse.o ft_printf_utils.o

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
