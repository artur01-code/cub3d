#include "cub3d.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_mlx	*mlx;

	mlx = NULL;
	if (argc != 2)
		return (0);
	printf("%s and %p\n", argv[0], mlx);
	mlx = (t_mlx *) malloc(sizeof(t_mlx));
	mlx->img = (t_img *) malloc(sizeof(t_img));
	mlx->map = (t_map *) malloc(sizeof(t_map));
	mlx->player = (t_player *) malloc(sizeof(t_player));
	//----------------------
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, mlx->map->columns * 99,  mlx->map->rows * 99, "Rice rally");

}