NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCPA = parsing
LIBFT = libft/libft.a
LIB =  -lmlx -framework OpenGL -framework AppKit -O3 -fsanitize=address -g3
SRCP = $(wildcard $(SRCPA)/*.c)
OBJ = $(SRCP:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(LIB) $(OBJ) $(LIBFT) -o cub3D

$(LIBFT):
	$(MAKE) -Clibft

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean  all