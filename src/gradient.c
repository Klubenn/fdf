/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 22:54:16 by cstill            #+#    #+#             */
/*   Updated: 2019/09/22 05:03:14 by cstill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(double *x, double *y, double z, t_map *map)
{
	double x_tmp;
	double y_tmp;

	x_tmp = *x;
	y_tmp = *y;
	*x = (x_tmp - y_tmp) * cos(map->fdf->angle);
	*y = (x_tmp + y_tmp) * sin(map->fdf->angle) - z;
}

int		maxmod(t_fdf *fdf)
{
	int a;
	int b;
	int c;

	a = (fdf->x1 - fdf->x0);
	b = (fdf->y1 - fdf->y0);
	c = (fdf->z1 - fdf->z0);
	a = (a > 0) ? a : -a;
	b = (b > 0) ? b : -b;
	c = (c > 0) ? c : -c;
	a = (a > b) ? a : b;
	a = (a > c) ? a : c;
	return (a);
}

double	distance(int first, int last, int current)
{
	double	a;
	double	dist;

	dist = last - first;
	current -= first;
	if (dist == 0)
		return (1.0);
	a = (current / dist);
	return (a);
}

int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int		ft_get_color(t_map *map, double dz, double dy, double dx)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;
	int		cl;

	if (map->fdf->col0 == map->fdf->col1)
		cl = map->fdf->col0;
	if (dz != 0)
	{
		if (dx > dy)
			percentage = distance(map->fdf->x0, map->fdf->x1, map->dr->x);
		else
			percentage = distance(map->fdf->y0, map->fdf->y1, map->dr->y);
		red = get_light((map->fdf->col0 >> 16) & 0xFF,
			(map->fdf->col1 >> 16) & 0xFF, percentage);
		green = get_light((map->fdf->col0 >> 8) & 0xFF,
			(map->fdf->col1 >> 8) & 0xFF, percentage);
		blue = get_light(map->fdf->col0 & 0xFF,
			map->fdf->col1 & 0xFF, percentage);
		cl = ((red << 16) | (green << 8) | blue);
	}
	return (cl);
}
