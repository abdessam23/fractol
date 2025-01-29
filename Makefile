NAME = fractol
CC = cc 
CFLAGS = -Wall -Wextra -Werror
SRC = fractol.c logic.c str_utils.c utils.c
OBJ = $(SRC: .c =.o)

all = $(NAME)
