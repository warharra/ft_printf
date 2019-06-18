NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

FILES = *.c

HEADERS = ft_printf.h

LIBS = ./libft/libft.a

OBJ = $(FILES:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(LIBS)
	@echo "\033[33m"
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(LIBS):
	make -C libft/

%.o: $(FILES)%.c
	@echo "\033[36m"
	gcc -I $(HEADERS) -c $(FILES)

clean:
	@echo "\033[31m"
	rm -f $(OBJ)
	make clean -C libft/

fclean: clean
	@echo "\033[31m"
	rm -f $(NAME)
	make fclean -C libft/

re: fclean all
