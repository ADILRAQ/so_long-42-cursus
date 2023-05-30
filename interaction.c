/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:41:04 by araqioui          #+#    #+#             */
/*   Updated: 2023/02/04 11:10:04 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_img	init_images(t_info	*pl)
{
	t_img	ig;
	int		i;
	int		j;

	ig.coll = mlx_xpm_file_to_image(pl->mlx, "img/chezz.xpm", &i, &j);
	ig.exit = mlx_xpm_file_to_image(pl->mlx, "img/C_door.xpm", &i, &j);
	ig.exit_o = mlx_xpm_file_to_image(pl->mlx, "img/Odoor.xpm", &i, &j);
	ig.floor = mlx_xpm_file_to_image(pl->mlx, "img/floor.xpm", &i, &j);
	ig.wall = mlx_xpm_file_to_image(pl->mlx, "img/plant2.xpm", &i, &j);
	ig.pll = mlx_xpm_file_to_image(pl->mlx, "img/jerry_L.xpm", &i, &j);
	ig.plr = mlx_xpm_file_to_image(pl->mlx, "img/jerry_R.xpm", &i, &j);
	return (ig);
}

static void	init_pl(t_info *pl)
{
	pl->to_coins = 0;
	pl->dir = 'R';
	pl->mov = 0;
	pl->ig = init_images(pl);
	if (!pl->ig.coll || !pl->ig.exit || !pl->ig.exit_o
		|| !pl->ig.floor || !pl->ig.wall || !pl->ig.pll || !pl->ig.plr)
	{
		ft_free(pl->maze);
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

int	move_player(int keycode, void *param)
{
	t_info	*pl;

	pl = (t_info *)param;
	if (keycode == 126)
		move_up(pl);
	else if (keycode == 123)
		move_left(pl);
	else if (keycode == 125)
		move_down(pl);
	else if (keycode == 124)
		move_right(pl);
	else if (keycode == 53)
	{
		ft_free(pl->maze);
		exit(EXIT_FAILURE);
	}
	if (keycode == 126 || keycode == 123
		|| keycode == 125 || keycode == 124)
	{
		mlx_clear_window(pl->mlx, pl->win);
		make_window(pl->maze, pl);
	}
	return (0);
}

int	ft_close(void *param)
{
	t_info	*pl;

	pl = (t_info *)param;
	ft_free(pl->maze);
	exit(EXIT_FAILURE);
}

void	game_interaction(char **map, t_info pl)
{
	pl.mlx = mlx_init();
	pl.win = mlx_new_window(pl.mlx, pl.x_max * 64, pl.y_max * 64, "so_long");
	if (!pl.mlx || !pl.win)
	{
		ft_free(map);
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	pl.maze = map;
	init_pl(&pl);
	ft_putnbr(pl.mov);
	write(1, "\n", 1);
	make_window(map, &pl);
	mlx_hook(pl.win, 2, 0, move_player, &pl);
	mlx_hook(pl.win, 17, 0, ft_close, &pl);
	mlx_loop(pl.mlx);
}
