# -*- MakeFile -*-

NAME = cub3d
# -*- Compiler -*-
GCC = gcc
FLAGS = -Wall -Wextra -Werror -Imlx

# -*- Includes -*-
SRC_PATH =
LIBFT = libft
INCL = incl
MLX_MACOS = mlx

# -*- Source Files -*-
SRC =	main.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		map_handler.c \

# -*- Objects -*-
SRCS=$(addprefix $(SRC_PATH),$(SRC))

all: lib tmp $(NAME)

tmp:
	@mkdir -p obj

# -*- MacOS -*-
lib:
	make -C $(LIBFT)

$(NAME): $(LIBFT)/*.c $(LIBFT)/*.h $(SRC)
	$(GCC) $(OBJ) $(FLAGS) $^ -L $(LIBFT)  -o $(NAME)


clean:
	make clean -C $(LIBFT)
	rm -rf $(OBJ_PATH)

fclean:
	make clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)
	rm -f libmlx.dylib
	rm -f src/libmlx.dylib


re:	fclean all


.PHONY: temporary, re, fclean, clean