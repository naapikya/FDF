/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naapikya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:39:44 by naapikya          #+#    #+#             */
/*   Updated: 2022/01/29 17:39:47 by naapikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_width(char *line, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] != c && (line[i + 1] == c || line[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

void	get_width(t_param *data, char *argv)
{
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	get_next_line(fd, &line);
	data->width = count_width(line, ' ');
	free(line);
	close(fd);
}

void	get_height(t_param *data, char *argv)
{
	char	*line;
	int		fd;

	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		(data->height)++;
		free(line);
	}
	free(line);
	close(fd);
}
