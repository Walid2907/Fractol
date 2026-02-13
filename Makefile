NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude
INCLUDES = -Iinclude

SRCS = src/main.c \
	src/close_window.c \
	src/free_all.c \
	src/key_hook_function.c \
	src/mouse_hook_function.c \
	src/my_mlx_pixel_put.c \
	src/mandelbrot.c \
	src/shapes.c \
	src/switch_color.c \
	src/disco_loop.c

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