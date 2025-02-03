CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = ./minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

SRCS = fractol.c logic.c str_utils.c utils.c fract_init.c
OBJS = $(SRCS:.c=.o)
TARGET = fractol

all: $(TARGET)

$(TARGET): $(OBJS) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(TARGET) -g

%.o:%.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
