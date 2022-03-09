/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naapikya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:58:44 by naapikya          #+#    #+#             */
/*   Updated: 2022/01/30 17:58:46 by naapikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham_helper(float *x, float *x1, float *y, t_param *data)
{
	while ((int)(*x1 - *x) || (int)(data->y1 - *y))
	{
		if ((*y < W_H) && (*x < W_L))
		{
			if (*x >= 0 && *y >= 0)
				my_mlx_pixel_put(&data->image, *x, *y, data->color);
		}
		*x += data->x_step;
		*y += data->y_step;
	}
}

void	bresenham(float x, float y, float x1, t_param *data)
{
	float	max;
	int		z;
	int		z1;

	if (data->draw_flag == 1)
		data->y1 = y;
	else if (data->draw_flag == 2)
		data->y1 = y + 1;
	z = data->matrix[(int)y][(int)x];
	z1 = data->matrix[(int)data->y1][(int)x1];
	zoom(&x, &y, &x1, data);
	z_scale(&z, &z1, data);
	if (!(data->dot))
	{
		isometric(&x, &y, z, data);
		isometric(&x1, &data->y1, z1, data);
	}
	shift(&x, &y, &x1, data);
	data->x_step = x1 - x;
	data->y_step = data->y1 - y;
	max = find_max(data->x_step, data->y_step);
	data->y_step /= max;
	data->x_step /= max;
	bresenham_helper(&x, &x1, &y, data);
}

void	draw(t_param *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
			{
				data->draw_flag = 1;
				bresenham(x, y, x + 1, data);
			}
			if (y < data->height - 1)
			{
				data->draw_flag = 2;
				bresenham(x, y, x, data);
			}
			x++;
		}
		y++;
	}
}
