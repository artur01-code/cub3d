#ifndef CUB3D_H
# define CUB3D_H
# include "mlx/mlx.h"
# include <stdlib.h>

typedef struct s_player {
	int		x;
	int		y;
	int		collactables;
	size_t	counter;
}				t_player;

typedef struct s_img {
	void	*img;
	char	*path;
	int		width;
	int		heigth;
}				t_img;

typedef struct s_map {
	char	**map;
	char	*path;
	int		rows;
	int		columns;
	int		collactables;
	int		exit;
	int		player;
}				t_map;

typedef struct s_mlx {
	void		*mlx;
	void		*mlx_win;
	t_img		*img;
	t_map		*map;
	t_player	*player;
}				t_mlx;

#endif