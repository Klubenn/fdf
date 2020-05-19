/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vizualization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 22:54:16 by cstill            #+#    #+#             */
/*   Updated: 2019/09/22 05:03:14 by cstill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	legend(t_map *map)
{
	int a;
	int b;
	int c;

	a = 20;
	b = 20;
	c = 30;
	mlx_string_put(map->fdf->mlx_ptr, map->fdf->win_ptr,
		a, b += c, WHITE, "ZOOM:    mouse scroll");
	mlx_string_put(map->fdf->mlx_ptr, map->fdf->win_ptr,
		a, b += c, WHITE, "MOVE:    arrows");
	mlx_string_put(map->fdf->mlx_ptr, map->fdf->win_ptr,
		a, b += c, WHITE, "HEIGHT:  8 / 2");
	mlx_string_put(map->fdf->mlx_ptr, map->fdf->win_ptr,
		a, b += c, WHITE, "ROTATE:");
	mlx_string_put(map->fdf->mlx_ptr, map->fdf->win_ptr,
		a += c, b += c, WHITE, "X-Axis - Q / W");
	mlx_string_put(map->fdf->mlx_ptr, map->fdf->win_ptr,
		a, b += c, WHITE, "Y-Axis - Z / X");
	mlx_string_put(map->fdf->mlx_ptr, map->fdf->win_ptr,
		a, b += c, WHITE, "Z-Axis - A / S");
	mlx_string_put(map->fdf->mlx_ptr, map->fdf->win_ptr,
		a -= c, b += c, WHITE, "Projection: P");
}

void	xyz_transf(double *x, double *y, double *z, t_map *map)
{
	double	x_tmp;
	double	y_tmp;

	y_tmp = *y;
	*y = (y_tmp) * cos(map->dr->x_angle) + (*z) * sin(map->dr->x_angle);
	*z = -(y_tmp) * sin(map->dr->x_angle) + (*z) * cos(map->dr->x_angle);
	x_tmp = *x;
	*x = x_tmp * cos(map->dr->y_angle) + (*z) * sin(map->dr->y_angle);
	*z = -x_tmp * sin(map->dr->y_angle) + (*z) * cos(map->dr->y_angle);
	x_tmp = *x;
	y_tmp = *y;
	*x = x_tmp * cos(map->dr->z_angle) - y_tmp * sin(map->dr->z_angle);
	*y = x_tmp * sin(map->dr->z_angle) + y_tmp * cos(map->dr->z_angle);
}

int		key_hook(int key, t_map *map)
{
	if (key == LEFT)
		map->fdf->shift_right -= 10;
	if (key == RIGHT)
		map->fdf->shift_right += 10;
	if (key == UP)
		map->fdf->shift_down += 10;
	if (key == DOWN)
		map->fdf->shift_down -= 10;
	if (key == EIGHT_0 || key == EIGHT_1)
		if (map->fdf->offset_z <= 6)
			map->fdf->offset_z *= 1.1;
	if (key == TWO_0 || key == TWO_1)
		if (map->fdf->offset_z >= 0.1)
			map->fdf->offset_z /= 1.1;
	if (key == L_P)
	{
		map->fdf->projection = (map->fdf->projection) ? 0 : 1;
		map->dr->x_angle = 0;
		map->dr->y_angle = 0;
		map->dr->z_angle = 0;
	}
	rotation(key, map);
	draw1(map, -1, -1);
	return (0);
}

int		rotation(int key, t_map *map)
{
	if (key == L_Q)
		map->dr->x_angle -= 0.1;
	if (key == L_W)
		map->dr->x_angle += 0.1;
	if (key == L_A)
		map->dr->y_angle -= 0.1;
	if (key == L_S)
		map->dr->y_angle += 0.1;
	if (key == L_Z)
		map->dr->z_angle -= 0.1;
	if (key == L_X)
		map->dr->z_angle += 0.1;
	if (key == ESC)
		shutdown(map);
	draw1(map, -1, -1);
	return (0);
}

int		mouse_move(int mouse, int x, int y, t_map *map)
{
	int z;

	z = x + y;
	if (mouse == 5)
		if (map->fdf->zoom >= 0.1)
			map->fdf->zoom /= 1.1;
	if (mouse == 4)
		map->fdf->zoom *= 1.1;
	draw1(map, -1, -1);
	return (0);
}
