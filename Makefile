NAME = cub3D
CC = cc -g
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
SRCPA = parsing
LIBFT = libft/libft.a
#LIB =  -lmlx -framework OpenGL -framework AppKit -O3 -fsanitize=address -g3
SRCP = $(wildcard $(SRCPA)/*.c)
OBJ = $(SRCP:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS)  $(OBJ) $(LIBFT) -o cub3D

$(LIBFT):
	$(MAKE) -Clibft

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean  all