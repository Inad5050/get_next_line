/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:50:06 by dangonz3          #+#    #+#             */
/*   Updated: 2024/06/04 19:28:59 by dangonz3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd1, fd2;
	char	*line;

	fd1 = open("text.txt", O_RDONLY);
	fd2 = open("text2.txt", O_RDONLY);
	if (fd1 == -1 || fd2 == -1)
		return (perror("open"), 1);
	while (1)
	{
		line = get_next_line(fd1);
		if (!line)
			break ;
		printf("%s", line);
		free(line);
	}
	printf("\n");
	while (1)
	{
		line = get_next_line(fd2);
		if (!line)
			break ;
		printf("%s", line);
		free(line);
	}
	close(fd1);
	close(fd2);
	return (0);
} 