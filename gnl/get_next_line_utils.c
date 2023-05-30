/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:48:08 by araqioui          #+#    #+#             */
/*   Updated: 2023/01/12 15:44:21 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_bzero(void *s, size_t len)
{
	size_t	i;
	void	*ptr;

	ptr = s;
	i = 0;
	while (i < len)
	{
		*(unsigned char *)ptr++ = '\0';
		i++;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (*(s + i) == c)
			return ((char *) s + i + 1);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *s1)
{
	char	*s2;
	int		i;

	if (!s1)
		return (0);
	i = 0;
	s2 = malloc(ft_strlen(s1) + 1);
	if (!s2)
		return (0);
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;
	int		i;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft_strdup((char *)s2));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!str)
		return (0);
	i = -1;
	while ((size_t)++i < s1_len)
		str[i] = s1[i];
	i = -1;
	while ((size_t)++i < s2_len)
		str[s1_len + i] = s2[i];
	str[s1_len + s2_len] = '\0';
	free((char *)s1);
	return (str);
}
