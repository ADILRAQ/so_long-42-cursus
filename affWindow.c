/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affWindow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:09:46 by araqioui          #+#    #+#             */
/*   Updated: 2023/02/04 11:09:05 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	ft_img_to_window(t_info *pl, void *ig, t_cord pos)
{
	mlx_put_image_to_window(pl->mlx, pl->win, ig, pos.j * 64, pos.i * 64);
}

static void	ft_put_background(char **map, t_info *pl)
{
	t_cord	pos;

	pos.i = -1;
	while (map[++(pos.i)])
	{
		pos.j = -1;
		while (map[pos.i][++(pos.j)])
			ft_img_to_window(pl, pl->ig.floor, pos);
	}
	pos.i = -1;
	while (map[++(pos.i)])
	{
		pos.j = -1;
		while (map[pos.i][++(pos.j)])
			if (map[pos.i][pos.j] == '1')
				ft_img_to_window(pl, pl->ig.wall, pos);
	}
}

static void	ft_put_chars(char **map, t_info *pl)
{
	t_cord	pos;

	pos.i = -1;
	while (map[++(pos.i)])
	{
		pos.j = -1;
		while (map[pos.i][++(pos.j)])
		{
			if (map[pos.i][pos.j] == 'E' && pl->coins != pl->to_coins)
				ft_img_to_window(pl, pl->ig.exit, pos);
			if (map[pos.i][pos.j] == 'E' && pl->coins == pl->to_coins)
				ft_img_to_window(pl, pl->ig.exit_o, pos);
			else if (map[pos.i][pos.j] == 'C')
				ft_img_to_window(pl, pl->ig.coll, pos);
		}
	}
}

void	make_window(char **map, t_info *pl)
{
	ft_put_background(map, pl);
	ft_put_chars(map, pl);
	pl->lst.i = pl->y;
	pl->lst.j = pl->x;
	if (pl->dir == 'L')
		ft_img_to_window(pl, pl->ig.pll, pl->lst);
	else
		ft_img_to_window(pl, pl->ig.plr, pl->lst);
}
