/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naapikya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:43:49 by naapikya          #+#    #+#             */
/*   Updated: 2022/01/29 17:43:52 by naapikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_m(int *m_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		m_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	create_matrix(char *argv, char *line, int fd, t_param *data)
{
	int	i;

	data->width = 0;
	data->height = 0;
	get_height(data, argv);
	get_width(data, argv);
	data->matrix = (int **)malloc(data->height * sizeof(int *));
	i = 0;
	while (i < data->height)
		data->matrix[i++] = (int *)malloc(data->width * sizeof(int));
	i = 0;
	while (get_next_line(fd, &line))
	{
		fill_m(data->matrix[i], line);
		free(line);
		i++;
	}
	free(line);
}
