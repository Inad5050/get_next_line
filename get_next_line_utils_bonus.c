/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:49:23 by dangonz3          #+#    #+#             */
/*   Updated: 2024/06/04 19:19:55 by dangonz3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_gnl_strjoin(char *line, const char *buffer)
{
	int		i;
	int		j;
	char	*str;

	if (!line)
	{
		line = (char *)ft_calloc(1, sizeof(char));
		line[0] = '\0';
	}
	if (!line || !buffer)
		return (NULL);
	str = ft_calloc((ft_strlen(line) + ft_strlen(buffer) + 1), sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (line[++i])
		str[i] = line[i];
	while (buffer[j])
		str[i++] = buffer[j++];
	str[ft_strlen(line) + ft_strlen(buffer)] = '\0';
	free (line);
	return (str);
}

char	*ft_strchr(const char *str, char character)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == character)
			return ((char *)str);
		str++;
	}
	if (character == '\0')
		return ((char *)str);
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	char	*temp;

	str = (void *)malloc(count * size);
	if (!str)
		return (NULL);
	temp = str;
	while (size)
	{
		*temp = '0';
		size--;
		temp++;
	}
	return (str);
}
