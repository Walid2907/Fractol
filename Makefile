NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude
INCLUDES = -Iinclude

SRCS = src/main.c \
       src/put_pixel.c \
	   src/free_all.c \
	   src/mandelbort.c \
	   src/key_hook.c \
	   src/disco_loop.c \
	   src/mouse_hook.c \
	   src/parsing.c \
	   src/julia.c \
	   src/tricorn.c \
	   src/ft_atof.c

OBJS = $(SRCS:.c=.o)

MLX = -L. -lmlx -lX11 -lXext -lm

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)

%.o: %.c include/fractol.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
