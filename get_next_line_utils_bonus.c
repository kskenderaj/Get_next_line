/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskender <kskender@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:27:42 by kskender          #+#    #+#             */
/*   Updated: 2025/04/22 09:43:15 by kskender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	newstr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!newstr)
		return (ft_free(&s1));
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		newstr[i++] = s2[j++];
	newstr[i] = '\0';
	ft_free(&s1);
	return (newstr);
}

char	*ft_strdup(const char *src)
{
	char	*str;
	size_t	i;

	str = malloc(ft_strlen(src) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	*ft_free(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}
