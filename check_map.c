#include "incl/cub3d.h"

static int	check_top_n_bot(t_window *window, int line)
{
	int	i;

	i = 0;
	while (window->map->map[line][i] && window->map->map[line][i] != '\n')
	{
		if (window->map->map[line][i] != '1' && window->map->map[line][i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

static int	line_check(t_window *window, int line)
{
	int	i;

	i = 0;
	if (window->map->map[line][i] != ' ' && window->map->map[line][i] != '1')
		return (0);
	i = 1;
	while (window->map->map[line][i] && window->map->map[line][i] != '\n')
	{
		if (window->map->map[line][i] == ' ' && window->map->map[line][i] != ' ' \
			&& window->map->map[line][i] != '1')
			return (0);
		while (window->map->map[line][i] == ' ')
			i++;
		if (window->map->map[line][i - 1] == ' ' && window->map->map[line][i] != '1')
			return (0);
		if (window->map->map[line][i] == '0' && \
			((window->map->map[line - 1][i] != '1' && window->map->map[line - 1][i] != '0') \
			|| (window->map->map[line + 1][i] != '1' && window->map->map[line + 1][i] != '0')) \
			&& window->map->map[line-1][i] != 'N' && window->map->map[line+1][i] != 'N' \
			&& window->map->map[line-1][i] != 'E' && window->map->map[line+1][i] != 'E' \
			&& window->map->map[line-1][i] != 'S' && window->map->map[line+1][i] != 'S' \
			&& window->map->map[line-1][i] != 'W' && window->map->map[line+1][i] != 'W')
			return (1);
		i++;
	}
	if (window->map->map[line][i - 1] != ' ' && window->map->map[line][i - 1] != '1')
		return (0);
	return (1);
}

int	check_map(t_window *window)
{
	int	i;

	i = 0;
	if (!check_top_n_bot(window, i))
		return (0);
	i = 1;
	while (i < window->map->rows)
	{
		if (!line_check(window, i))
			return (0);
		i++;
	}
	//window->map->map[(int)window->player->y][(int)window->player->x] = window->map->pdir;
	return (1);
}
