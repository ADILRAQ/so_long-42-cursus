/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapCheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:12:38 by araqioui          #+#    #+#             */
/*   Updated: 2023/02/01 12:47:35 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	ft_valid_char(char *str, int *player, int *ex, int *col)
{
	while (*str && *str != '\n')
	{
		if (*str == '1' || *str == '0' || *str == 'C'
			|| *str == 'P' || *str == 'E')
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

int	ft_check_chars(t_list *lst, int *coins)
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
		if (!ft_valid_char(lst->str, &player, &ex, &col))
			check++;
		lst = lst->next;
	}
	if (check != 0 || player != 1 || ex != 1 || !col)
	{
		write(1, "Error\nInvalid character", 23);
		return (0);
	}
	*coins = col;
	return (1);
}

int	ft_chk_rctgl(t_list *lst)
{
	size_t	len;

	if (((ft_lstsize(lst) - 1) * lst->len < 15)
		|| ft_lstsize(lst) - 1 == 2 || lst->len == 2)
	{
		write(1, "Error\nMap is too small", 22);
		return (0);
	}
	len = lst->len;
	while (lst->str)
	{
		if (len != ft_strlen_map(lst->str))
		{
			write(1, "Error\nMap isn't rectangular", 27);
			return (0);
		}
		lst = lst->next;
	}
	return (1);
}

int	ft_chk_walls(t_list *lst)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (lst->str[i] && lst->str[i] != '\n' && !check)
		if (lst->str[i++] != '1')
			check = 1;
	lst = lst->next;
	while (lst->next->str > 0 && !check)
	{
		if (lst->str[0] != '1' || lst->str[lst->len - 1] != '1')
			check = 1;
		lst = lst->next;
	}
	i = 0;
	while (lst->str[i] && lst->str[i] != '\n' && !check)
		if (lst->str[i++] != '1')
			check = 1;
	if (check)
	{
		write(1, "Error\nInvalid Walls\n", 20);
		return (0);
	}
	return (1);
}
