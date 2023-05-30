/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveEnemie.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:15:02 by araqioui          #+#    #+#             */
/*   Updated: 2023/02/03 18:46:20 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	enemy_up(t_info **ply, int i, int j)
{
	if ((*ply)->maze[i - 1][j] == 'P')
	{
		ft_free((*ply)->maze);
		exit(1);
	}
	(*ply)->maze[i][j] = '0';
	(*ply)->maze[i - 1][j] = 'e';
}

void	enemy_right(t_info **ply, int i, int j)
{
	if ((*ply)->maze[i][j + 1] == 'P')
	{
		ft_free((*ply)->maze);
		exit(1);
	}
	(*ply)->maze[i][j] = '0';
	(*ply)->maze[i][j + 1] = 'e';
}

void	enemy_down(t_info **ply, int i, int j)
{
	if ((*ply)->maze[i + 1][j] == 'P')
	{
		ft_free((*ply)->maze);
		exit(1);
	}
	(*ply)->maze[i][j] = '0';
	(*ply)->maze[i + 1][j] = 'e';
}

void	enemy_left(t_info **ply, int i, int j)
{
	if ((*ply)->maze[i][j - 1] == 'P')
	{
		ft_free((*ply)->maze);
		exit(1);
	}
	(*ply)->maze[i][j] = '0';
	(*ply)->maze[i][j - 1] = 'e';
}
