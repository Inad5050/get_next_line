/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:50:14 by dangonz3          #+#    #+#             */
/*   Updated: 2024/06/04 19:17:15 by dangonz3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

char	*ft_strchr(const char *str, char character);
char	*ft_gnl_strjoin(char *line, const char *buffer);
char	*get_next_line(int fd);
char	*excess(char *deposit);
size_t	ft_strlen(const char *str);
char	*cut_line(char *deposit);
void	*ft_calloc(size_t count, size_t size);

#endif
