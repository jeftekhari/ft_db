#!/usr/bin/make -f

LIBRARY = ../libft/libft.a

NAME = ft_db

HEADERS = knurkle.h

OBJECTS = main.o includes/get_next_line/get_next_line.o draw.o draw1.o parsing.o tools.o hook.o bresenham.o

GRAPHICS_FLAGS = -framework OpenGL -framework AppKit

CFLAGS = -Wall -Werror -Wextra -g -fno-omit-frame-pointer -fsanitize=address

.PHONY:all clean fclean re information
all: information $(NAME)

$(NAME): $(OBJECTS)
	make -C ./includes/libft/
	make -C ./minilibx_macos/
	$(CC) $(CFLAGS) $(GRAPHICS_FLAGS) $(OBJECTS) -L. ./includes/libft/libft.a -lmlx -Lminilibx_macos -o $@

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME) $(OBJECTS)
re: fclean all

information:
	@printf "Build mode "$(mode)" selected\n"
