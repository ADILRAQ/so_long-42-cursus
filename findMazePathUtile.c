/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findMazePathUtile.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:44:56 by araqioui          #+#    #+#             */
/*   Updated: 2023/02/04 11:10:53 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char	*ft_initialize(int x)
{
	char	*str;
	int		y;

	str = malloc((x + 1) * sizeof(char));
	if (!str)
		return (NULL);
	y = -1;
	while (++y < x)
		str[y] = '1';
	str[x] = '\0';
	return (str);
}

char	**ft_fill(int y, int x)
{
	char	**str;
	int		i;

	str = malloc((y + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	str[y] = NULL;
	i = -1;
	while (++i < y)
	{
		str[i] = ft_initialize(x);
		if (!str[i])
		{
			ft_free(str);
			return (NULL);
		}
	}
	return (str);
}
