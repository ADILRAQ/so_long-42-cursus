/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapName.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:19:12 by araqioui          #+#    #+#             */
/*   Updated: 2023/01/31 17:51:16 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	map_format(char *str)
{
	char	*form;
	int		i;
	int		j;

	form = ".ber";
	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	j = 0;
	while (str[i])
	{
		if (str[i] != form[j])
			return (0);
		i++;
		j++;
	}
	if (str[i] != form[j])
		return (0);
	return (1);
}
