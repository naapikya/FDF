/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naapikya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 12:46:04 by naapikya          #+#    #+#             */
/*   Updated: 2022/01/29 12:46:10 by naapikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define BUFFER_SIZE 10
# define W_H 1000
# define W_L 1000
# define K_ESC 53
# define K_W 13
# define K_PLUS 69
# define K_MINUS 78
# define K_UP 126
# define K_DOWN 125
# define K_RIGHT 124
# define K_LEFT 123
# define K_ROTP 18
# define K_ROTM 19
# define K_TWOD 21
# define K_THREED 22

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "minilibx_macos/mlx.h"

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bbp;
	int			line_len;
	int			endian;
}				t_img;

typedef struct s_param{
	t_img	image;
	int		width;
	int		height;
	int		**matrix;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	float	rot_angle;
	int		dot;
	int		z_scale;
	void	*mlx_ptr;
	void	*win_ptr;
	int		draw_flag;
	float	y1;
	float	x_step;
	float	y_step;
}	t_param;

int		get_next_line(int fd, char **line);
int		ft_strlen_gnl(char *str);
char	*ft_strjoin_gnl(char *rem_line, char *buffer);
int		ft_str_endline_gnl(char *str);
char	*ft_remline_gnl(char *rem_line);
char	*ft_clearrem_gnl(char *rem_line);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
void	get_width(t_param *data, char *argv);
void	get_height(t_param *data, char *argv);
void	create_matrix(char *argv, char *line, int fd, t_param *data);
void	bresenham(float x, float y, float x1, t_param *data);
void	draw(t_param *data);
int		count_width(char *line, char c);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
int		deal_key(int key, t_param *data);
void	argc_check(int argc);
void	image(t_param *data);
int		ft_frame(t_param *info);
void	init(t_param *data);
float	find_max(float a, float b);
void	isometric(float *x, float *y, int z, t_param *data);
void	zoom(float *x, float *y, float *x1, t_param *data);
void	z_scale(int *z, int *z1, t_param *data);
void	shift(float *x, float *y, float *x1, t_param *data);

#endif
