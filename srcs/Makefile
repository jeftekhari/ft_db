#!/usr/bin/make -f

LIBRARY = ../libft/libft.a

NAME = ft_db

HEADERS = knurkle.h

OBJECTS = main.o writeout.o tools.o readin.o search.o tools2.o

CFLAGS = -Wall -Werror -Wextra -g

.PHONY:all clean fclean re information
all: information $(NAME)

$(NAME): $(OBJECTS)
	make -C ../libs/libft/
	$(CC) $(CFLAGS) $(GRAPHICS_FLAGS) $(OBJECTS) -L. ../libs/libft/libft.a -o $@

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME) $(OBJECTS)
re: fclean all

information:
	@printf "Build mode "$(mode)" selected\n"
