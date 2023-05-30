/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:43:43 by araqioui          #+#    #+#             */
/*   Updated: 2023/01/13 14:54:20 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*ptr;

	if (!lst)
		return ;
	ptr = *lst;
	while (ptr)
	{
		ptr = ptr->next;
		free((*lst)->str);
		free(*lst);
		*lst = ptr;
	}
	lst = NULL;
}
