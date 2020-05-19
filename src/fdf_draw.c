/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 22:54:16 by cstill            #+#    #+#             */
/*   Updated: 2019/09/22 05:03:14 by cstill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw2(t_map *map)
{
	double		dx;
	double		dy;
	double		dz;
	int			steps;

	steps = maxmod(map->fdf);
	dx = ((double)((map->fdf->x1 - map->fdf->x0)) / (double)steps);
	dy = ((double)(map->fdf->y1 - map->fdf->y0)) / (double)steps;
	dz = ((double)(map->fdf->z1 - map->fdf->z0)) / (double)steps;
	map->dr->x = map->fdf->x0;
	map->dr->y = map->fdf->y0;
	map->dr->z = map->fdf->z0;
	map->dr->col = map->fdf->col0;
	put_color(map);
	while (steps > 0)
	{
		map->dr->x += dx;
		map->dr->y += dy;
		map->dr->z += dz;
		map->dr->col = ft_get_color(map, dz, dy, dx);
		put_color(map);
		steps--;
	}
}

void	visualize(t_map *map)
{
	map->fdf = new_fdf(map);
	map->dr = (t_draw *)ft_memalloc(sizeof(t_draw));
	map->dot = (t_dot *)ft_memalloc(sizeof(t_dot));
	if (!(map->fdf->mlx_ptr = mlx_init()))
		shutdown(map);
	if (!(map->fdf->win_ptr = mlx_new_window(map->fdf->mlx_ptr,
		WIDTH, HEIGHT, "FDF")))
		shutdown(map);
	if (!(map->fdf->img_ptr = mlx_new_image(map->fdf->mlx_ptr, WIDTH, HEIGHT)))
		shutdown(map);
	if (!(map->fdf->address = mlx_get_data_addr(map->fdf->img_ptr,
	&(map->fdf->bits_per_pixel), &(map->fdf->size_line), &(map->fdf->endian))))
		shutdown(map);
	draw1(map, -1, -1);
	mlx_hook(map->fdf->win_ptr, 2, 0, key_hook, map);
	mlx_hook(map->fdf->win_ptr, 4, 0, mouse_move, map);
	mlx_hook(map->fdf->win_ptr, 17, 0, shutdown, map);
	mlx_loop(map->fdf->mlx_ptr);
}

void	draw1(t_map *map, int x, int y)
{
	ft_bzero(map->fdf->address, WIDTH * HEIGHT * sizeof(int));
	while (++y <= map->height - 1)
	{
		x = -1;
		while (++x <= map->width - 1)
		{
			map->fdf->x0 = x * map->fdf->zoom;
			map->fdf->x0 -= (map->width * map->fdf->zoom) / 2;
			map->fdf->y0 = y * map->fdf->zoom;
			map->fdf->y0 -= (map->height * map->fdf->zoom) / 2;
			map->fdf->z0 = map->coord[y][x][0] *
				map->fdf->zoom * map->fdf->offset_z;
			map->fdf->col0 = map->coord[y][x][1];
			xyz_transf(&map->fdf->x0, &map->fdf->y0, &map->fdf->z0, map);
			if (!map->fdf->projection)
				iso(&map->fdf->x0, &map->fdf->y0, map->fdf->z0, map);
			if (x <= map->width - 2)
				zoom_width(map, x, y);
			if (y <= map->height - 2)
				zoom_height(map, x, y);
		}
	}
	mlx_put_image_to_window(map->fdf->mlx_ptr,
		map->fdf->win_ptr, map->fdf->img_ptr, 0, 0);
	legend(map);
}

void	zoom_width(t_map *map, int x, int y)
{
	map->fdf->x1 = (x + 1) * map->fdf->zoom;
	map->fdf->x1 -= (map->width * map->fdf->zoom) / 2;
	map->fdf->y1 = y * map->fdf->zoom;
	map->fdf->y1 -= (map->height * map->fdf->zoom) / 2;
	map->fdf->z1 = map->coord[y][x + 1][0] *
		map->fdf->zoom * map->fdf->offset_z;
	map->fdf->col1 = map->coord[y][x + 1][1];
	xyz_transf(&map->fdf->x1, &map->fdf->y1, &map->fdf->z1, map);
	if (!map->fdf->projection)
		iso(&map->fdf->x1, &map->fdf->y1, map->fdf->z1, map);
	draw2(map);
}

void	zoom_height(t_map *map, int x, int y)
{
	map->fdf->x1 = x * map->fdf->zoom;
	map->fdf->x1 -= (map->width * map->fdf->zoom) / 2;
	map->fdf->y1 = (y + 1) * map->fdf->zoom;
	map->fdf->y1 -= (map->height * map->fdf->zoom) / 2;
	map->fdf->z1 = map->coord[y + 1][x][0] *
		map->fdf->zoom * map->fdf->offset_z;
	map->fdf->col1 = map->coord[y + 1][x][1];
	xyz_transf(&map->fdf->x1, &map->fdf->y1, &map->fdf->z1, map);
	if (!map->fdf->projection)
		iso(&map->fdf->x1, &map->fdf->y1, map->fdf->z1, map);
	draw2(map);
}
