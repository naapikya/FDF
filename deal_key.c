/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naapikya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:55:01 by naapikya          #+#    #+#             */
/*   Updated: 2022/02/01 18:55:02 by naapikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	deal_key2(int key, t_param *data)
{
	int	i;

	if (key == K_ESC)
	{
		i = 0;
		while (i < data->height)
		{
			free(data->matrix[i]);
			i++;
		}
		free(data->matrix);
		exit(0);
	}
	if (key == K_UP)
		data->shift_y -= 10;
	if (key == K_DOWN)
		data->shift_y += 10;
	if (key == K_LEFT)
		data->shift_x -= 10;
	if (key == K_RIGHT)
		data->shift_x += 10;
}

int	deal_key(int key, t_param *data)
{
	deal_key2(key, data);
	if (key == K_PLUS && data->zoom <= 1500)
		data->zoom += 3;
	if (key == K_MINUS && data->zoom > 0)
		data->zoom -= 3;
	if (key == K_ROTP)
		data->rot_angle += 0.05;
	if (key == K_ROTM)
		data->rot_angle -= 0.05;
	if (key == K_TWOD)
		data->dot = 1;
	if (key == K_THREED)
		data->dot = 0;
	if (key == 28)
		data->z_scale += 1;
	if (key == 25)
		data->z_scale -= 1;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}
