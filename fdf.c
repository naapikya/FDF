/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naapikya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 12:46:21 by naapikya          #+#    #+#             */
/*   Updated: 2022/01/29 12:46:23 by naapikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bbp / 8));
	*(unsigned int *)dst = color;
}

void	map_check(char *file_name)
{
	int		count;
	int		temp;
	char	*line;
	int		fd;

	fd = open(file_name, O_RDONLY);
	get_next_line(fd, &line);
	count = count_width(line, ' ');
	free(line);
	while (get_next_line(fd, &line))
	{
		temp = count_width(line, ' ');
		if (count != temp)
		{
			write(1, "ERROR!\n", 7);
			exit(0);
		}
		free(line);
	}
	close(fd);
}

void	black(t_param *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < W_H)
	{
		j = 0;
		while (j < W_L)
		{
			my_mlx_pixel_put(&data->image, j, i, 0x000000);
			j++;
		}
		i++;
	}
}

int	ft_frame(t_param *info)
{
	black(info);
	draw(info);
	mlx_put_image_to_window(info->mlx_ptr,
		info->win_ptr, info->image.img, 0, 0);
	mlx_do_sync(info->mlx_ptr);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_param		*data;
	int			fd;
	char		*line;

	line = NULL;
	argc_check(argc);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "ERROR!\n", 7);
		exit (0);
	}
	else
	{
		data = (t_param *)malloc(sizeof(t_param));
		create_matrix(argv[1], line, fd, data);
		close(fd);
	}
	init(data);
	map_check(argv[1]);
	image(data);
}
