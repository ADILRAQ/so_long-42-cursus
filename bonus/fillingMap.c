/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillingMap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:52:20 by araqioui          #+#    #+#             */
/*   Updated: 2023/02/01 17:51:59 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static t_list	*ft_fill_list(int fd)
{
	t_list	*lst;
	int		i;

	i = 0;
	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew(get_next_line(fd), i++));
	while (ft_lstlast(lst)->str)
		ft_lstadd_back(&lst, ft_lstnew(get_next_line(fd), i++));
	return (lst);
}

char	**ft_fill_map_b(int fd, int *y, int *x, int *coins)
{
	t_list	*head;
	t_list	*ptr;
	char	**map;

	map = NULL;
	head = ft_fill_list(fd);
	ptr = head;
	*y = ft_lstsize(head) - 1;
	*x = head->len;
	if (ft_chk_rctgl(ptr) && check_char_b(ptr, coins) && ft_chk_walls(ptr))
	{
		map = malloc(ft_lstsize(ptr) * sizeof(char *));
		if (!map)
			ft_free_list(&ptr);
		while (ptr)
		{
			map[ptr->indice] = ft_strdup(ptr->str);
			if (!map[ptr->indice] && ptr->str)
				ft_both_free(map, &head);
			ptr = ptr->next;
		}
	}
	ft_lstclear(&head);
	return (map);
}
