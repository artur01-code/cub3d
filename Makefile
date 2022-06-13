SRC = main.c

OBJS		=	$(SRC:.c=.o)

CFLAGS		=	-Wall -Werror -Wextra

%.o: %.c 
		gcc $(CFLAGS) -Imlx -c $< -o $@

cub3d:	$(OBJS)
			cd mlx && make
			gcc $(OBJS) mlx/libmlx.dylib -o $@

all:		so_long

clean:
		cd mlx && make clean
		rm -rf $(OBJS)

fclean: clean
		rm -rf cub3d
		rm -rf mlx/libmlx.a

re: fclean all
