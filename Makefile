NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror 

SRCS = test.c \
	close_window.c \
	free_all.c \
	key_hook_function.c \
	mouse_hook_function.c \
	my_mlx_pixel_put.c \
	mandelbrot.c \
	shapes.c \
	switch_color.c

OBJS = $(SRCS:.c=.o)

MLX = -L. -lmlx -lX11 -lXext -lm

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)

%.o: %.c header.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re