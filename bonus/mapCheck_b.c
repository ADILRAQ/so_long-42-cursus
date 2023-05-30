/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapCheck_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:12:38 by araqioui          #+#    #+#             */
/*   Updated: 2023/02/01 17:25:42 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	valid_chars_b(char *str, int *player, int *ex, int *col)
{
	while (*str && *str != '\n')
	{
		if (*str == '1' || *str == '0' || *str == 'C'
			|| *str == 'P' || *str == 'E' || *str == 'e')
		{
			if (*str == 'P')
				(*player)++;
			else if (*str == 'E')
				(*ex)++;
			else if (*str == 'C')
				(*col)++;
		}
		else
			return (0);
		str++;
	}
	return (1);
}

int	check_char_b(t_list *lst, int *coins)
{
	int		check;
	int		player;
	int		ex;
	int		col;

	check = 0;
	player = 0;
	ex = 0;
	col = 0;
	while (lst->str && !check)
	{
		if (!valid_chars_b(lst->str, &player, &ex, &col))
			check++;
		lst = lst->next;
	}
	if (check || player != 1 || ex != 1 || !col)
	{
		write(1, "Error\nInvalid character", 24);
		return (0);
	}
	*coins = col;
	return (1);
}
