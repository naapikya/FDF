/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naapikya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:32:34 by naapikya          #+#    #+#             */
/*   Updated: 2022/02/01 19:32:39 by naapikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	argc_check(int argc)
{
	if (argc == 1 || argc > 2)
	{
		write(1, "ERROR!\n", 7);
		exit (0);
	}
}

void	image(t_param *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, W_L, W_H, "FDF");
	data->image.img = mlx_new_image(data->mlx_ptr, 1000, 1000);
	data->image.addr = mlx_get_data_addr(data->image.img, &data->image.bbp,
			&data->image.line_len, &data->image.endian);
	mlx_hook(data->win_ptr, 2, 0, deal_key, data);
	mlx_loop_hook(data->mlx_ptr, ft_frame, data);
	mlx_loop(data->mlx_ptr);
}

void	init(t_param *data)
{
	data->shift_x = W_L / 2;
	data->shift_y = W_H / 3;
	data->rot_angle = 0.8;
	data->z_scale = 1;
	data->zoom = 20;
}
