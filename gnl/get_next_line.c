/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:37:16 by araqioui          #+#    #+#             */
/*   Updated: 2023/01/12 15:44:28 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	ft_check_nl_eof(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n' || *str == EOF)
			return (1);
		str++;
	}
	return (0);
}

static size_t	ft_len(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n' && s[i] != EOF)
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

static char	*ft_new_strings(char *str, char ***str1)
{
	char	*new_stock;
	size_t	len;
	size_t	i;

	len = ft_len(str);
	new_stock = malloc((len + 1) * sizeof(char));
	if (!new_stock)
		return (0);
	i = 0;
	while (i < len)
	{
		new_stock[i] = str[i];
		i++;
	}
	new_stock[i] = '\0';
	**str1 = ft_strdup(ft_strchr(str, '\n'));
	free(str);
	str = NULL;
	return (new_stock);
}

static char	*ft_new_str(int fd, char *to_stock, char **to_keep, ssize_t sz)
{
	char	*str;

	str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str)
		return (0);
	while (sz > 0)
	{
		ft_bzero(str, BUFFER_SIZE + 1);
		if (ft_check_nl_eof(to_stock))
		{
			free(str);
			return (ft_new_strings(to_stock, &to_keep));
		}
		sz = read(fd, str, BUFFER_SIZE);
		if (sz < 0)
		{
			free(str);
			return (0);
		}
		to_stock = ft_strjoin(to_stock, str);
	}
	free(str);
	return (to_stock);
}

char	*get_next_line(int fd)
{
	static char	*to_keep;
	char		*to_stock;
	ssize_t		sz;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	to_stock = NULL;
	if (to_keep)
	{
		to_stock = ft_strdup(to_keep);
		free(to_keep);
		to_keep = NULL;
	}
	sz = 1;
	to_stock = ft_new_str(fd, to_stock, &to_keep, sz);
	if (to_stock && *to_stock != '\0')
		return (to_stock);
	free(to_stock);
	return (0);
}
