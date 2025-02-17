TARGET = fractol
BONUS = fractol_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes
MLX_DIR = ./minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

BSRCS = bonus/fract_init.c bonus/fract_render.c bonus/fractol.c bonus/hook.c \
		bonus/str_utils.c bonus/utils.c
SRCS = mandatory/fractol.c mandatory/fract_render.c mandatory/str_utils.c \
		mandatory/utils.c mandatory/fract_init.c mandatory/hook.c
OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(TARGET)

$(BONUS): $(BOBJS) $(MLX_LIB) 
	$(CC) $(CFLAGS) $(BOBJS) $(MLX_FLAGS) -o $(BONUS)
bonus: $(BONUS)
%.o:%.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -rf $(OBJS) $(BOBJS)

fclean: clean
	rm -rf $(TARGET) $(BONUS)
re: fclean all

.PHONY: all clean fclean re
