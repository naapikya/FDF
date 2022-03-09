/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naapikya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 15:02:02 by naapikya          #+#    #+#             */
/*   Updated: 2022/02/05 15:02:03 by naapikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	find_max(float a, float b)
{
	float	max;

	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	if (a > b)
		max = a;
	else
		max = b;
	return (max);
}

void	isometric(float *x, float *y, int z, t_param *data)
{
	*x = (*x - *y) * cos(data->rot_angle);
	*y = (*x + *y) * sin(data->rot_angle) - z;
}

void	zoom(float *x, float *y, float *x1, t_param *data)
{
	*x *= data->zoom;
	*y *= data->zoom;
	*x1 *= data->zoom;
	data->y1 *= data->zoom;
}

void	z_scale(int *z, int *z1, t_param *data)
{
	*z *= data->z_scale;
	*z1 *= data->z_scale;
	if (*z != 0)
		data->color = 0xe80c0c;
	else
		data->color = 0xffffff;
}

void	shift(float *x, float *y, float *x1, t_param *data)
{
	*x += data->shift_x;
	*y += data->shift_y;
	*x1 += data->shift_x;
	data->y1 += data->shift_y;
}
