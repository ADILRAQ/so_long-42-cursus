/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directionMoves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:53:22 by araqioui          #+#    #+#             */
/*   Updated: 2023/02/04 11:08:38 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	move_up(t_info *pl)
{
	int		x;
	int		y;

	x = pl->x;
	y = pl->y;
	if (pl->maze[y - 1][x] == '0' || pl->maze[y - 1][x] == 'C')
	{
		if (pl->maze[y - 1][x] == 'C')
			++(pl->to_coins);
		pl->maze[y][x] = '0';
		pl->y -= 1;
		pl->maze[pl->y][x] = 'P';
		ft_putnbr(++(pl->mov));
		write(1, "\n", 1);
	}
	else if (pl->maze[y - 1][x] == 'E' && pl->coins == pl->to_coins)
	{
		ft_putnbr(++(pl->mov));
		write(1, "\n", 1);
		ft_free(pl->maze);
		exit(EXIT_SUCCESS);
	}
}

void	move_down(t_info *pl)
{
	int		x;
	int		y;

	x = pl->x;
	y = pl->y;
	if (pl->maze[y + 1][x] == '0' || pl->maze[y + 1][x] == 'C')
	{
		if (pl->maze[y + 1][x] == 'C')
			++(pl->to_coins);
		pl->maze[y][x] = '0';
		pl->y += 1;
		pl->maze[pl->y][x] = 'P';
		ft_putnbr(++(pl->mov));
		write(1, "\n", 1);
	}
	else if (pl->maze[y + 1][x] == 'E' && pl->coins == pl->to_coins)
	{
		ft_putnbr(++(pl->mov));
		write(1, "\n", 1);
		ft_free(pl->maze);
		exit(EXIT_SUCCESS);
	}
}

void	move_left(t_info *pl)
{
	int		x;
	int		y;

	x = pl->x;
	y = pl->y;
	pl->dir = 'L';
	if (pl->maze[y][x - 1] == '0' || pl->maze[y][x - 1] == 'C')
	{
		if (pl->maze[y][x - 1] == 'C')
			++(pl->to_coins);
		pl->maze[y][x] = '0';
		pl->x -= 1;
		pl->maze[y][pl->x] = 'P';
		ft_putnbr(++(pl->mov));
		write(1, "\n", 1);
	}
	else if (pl->maze[y][x - 1] == 'E' && pl->coins == pl->to_coins)
	{
		ft_putnbr(++(pl->mov));
		write(1, "\n", 1);
		ft_free(pl->maze);
		exit(EXIT_SUCCESS);
	}
}

void	move_right(t_info *pl)
{
	int		x;
	int		y;

	x = pl->x;
	y = pl->y;
	pl->dir = 'R';
	if (pl->maze[y][x + 1] == '0' || pl->maze[y][x + 1] == 'C')
	{
		if (pl->maze[y][x + 1] == 'C')
			++(pl->to_coins);
		pl->maze[y][x] = '0';
		pl->x += 1;
		pl->maze[y][pl->x] = 'P';
		ft_putnbr(++(pl->mov));
		write(1, "\n", 1);
	}
	else if (pl->maze[y][x + 1] == 'E' && pl->coins == pl->to_coins)
	{
		ft_putnbr(++(pl->mov));
		write(1, "\n", 1);
		ft_free(pl->maze);
		exit(EXIT_SUCCESS);
	}
}
