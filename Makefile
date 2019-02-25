NAME = bsq
SRC = src/*.c

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -c $(SRC)
	gcc -Wall -Werror -Wextra *.o -o $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
