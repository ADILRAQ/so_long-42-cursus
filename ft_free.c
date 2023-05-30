/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:28:43 by araqioui          #+#    #+#             */
/*   Updated: 2023/01/31 18:04:56 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_free_list(t_list **lst)
{
	ft_lstclear(lst);
	exit(EXIT_FAILURE);
}

char	**ft_free(char **str)
{
	char	*arr;
	int		i;

	i = 0;
	while (str[i])
	{
		arr = str[i++];
		free(arr);
	}
	free(str);
	str = NULL;
	return (str);
}

char	**ft_both_free(char **str, t_list **lst)
{
	char	*arr;
	int		i;

	ft_lstclear(lst);
	i = 0;
	while (str[i])
	{
		arr = str[i++];
		free(arr);
	}
	free(str);
	str = NULL;
	return (str);
}
