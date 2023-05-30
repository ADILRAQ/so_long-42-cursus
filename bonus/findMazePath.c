/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findMazePath.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:37:19 by araqioui          #+#    #+#             */
/*   Updated: 2023/02/03 14:41:58 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	is_safe(char **map, int y, int x)
{
	if (map[y][x] == '0' || map[y][x] == 'C' || map[y][x] == 'P'
		|| map[y][x] == 'e')
		return (1);
	return (0);
}

static int	ft_find_paths(char **map, int y, int x, char **sol)
{
	if (is_safe(map, y, x))
	{
		if (sol[y][x] == '0')
			return (0);
		sol[y][x] = '0';
		ft_find_paths(map, y + 1, x, sol);
		ft_find_paths(map, y, x + 1, sol);
		ft_find_paths(map, y - 1, x, sol);
		ft_find_paths(map, y, x - 1, sol);
		return (0);
	}
	return (0);
}

static int	ft_check_access(char **map, int *ch_map, int *ch_sol, char **sol)
{
	int	i;
	int	j;

	*ch_map = 0;
	*ch_sol = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
			{
				(*ch_map)++;
				if (sol[i][j] == '0' || sol[i + 1][j] == '0'
					|| sol[i - 1][j] == '0' || sol[i][j + 1] == '0'
						|| sol[i][j - 1] == '0')
					(*ch_sol)++;
			}
		}
	}
	if (*ch_map == *ch_sol)
		return (1);
	return (0);
}

int	solve_maze_b(char **map, t_info *player)
{
	char	**sol;
	int		x;
	int		y;

	sol = ft_fill(player->y_max, player->x_max);
	if (!sol)
		return (0);
	player->y = -1;
	while (map[++(player->y)])
	{
		player->x = -1;
		while (map[player->y][++(player->x)])
			if (map[player->y][player->x] == 'P')
				break ;
		if (map[player->y][player->x] == 'P')
			break ;
	}
	ft_find_paths(map, player->y, player->x, sol);
	if (ft_check_access(map, &y, &x, sol))
	{
		ft_free(sol);
		return (1);
	}
	ft_free(sol);
	return (0);
}
