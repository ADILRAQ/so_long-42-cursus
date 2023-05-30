/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemyPath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:21:50 by araqioui          #+#    #+#             */
/*   Updated: 2023/02/04 11:18:30 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	move_enemie_two(t_info **ply, int i, int j)
{
	if ((*ply)->maze[i - 1][j] == '0' || (*ply)->maze[i - 1][j] == 'P')
		enemy_up(ply, i, j);
	else if ((*ply)->maze[i][j + 1] == '0' || (*ply)->maze[i][j + 1] == 'P')
		enemy_right(ply, i, j);
	else if ((*ply)->maze[i + 1][j] == '0' || (*ply)->maze[i + 1][j] == 'P')
		enemy_down(ply, i, j);
	else if ((*ply)->maze[i][j - 1] == '0' || (*ply)->maze[i][j - 1] == 'P')
		enemy_left(ply, i, j);
}

void	move_enemies_one(t_info *ply)
{
	ply->lst.i = 0;
	while (++(ply->lst.i) < ply->y_max - 1)
	{
		ply->lst.j = 0;
		while (++(ply->lst.j) < ply->x_max - 1)
		{
			if (ply->maze[ply->lst.i][ply->lst.j] == 'e')
			{
				move_enemie_two(&ply, ply->lst.i, ply->lst.j);
				if (ply->lst.i < ply->y_max - 1)
					(ply->lst.i)++;
			}
		}
	}
}

int	move_enemies(void *pl)
{
	t_info		*ply;
	static int	k;

	if (k < 3500)
		k++;
	else
	{
		k = 0;
		ply = (t_info *)pl;
		ply->lst.i = -1;
		move_enemies_one(ply);
		mlx_clear_window(ply->mlx, ply->win);
		make_window_b(ply->maze, ply);
	}
	return (0);
}
