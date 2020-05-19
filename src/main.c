/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 22:54:16 by cstill            #+#    #+#             */
/*   Updated: 2019/09/22 05:03:14 by cstill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_z(t_map *map)
{
	int diff;
	int x;
	int y;

	if (map->z_max < -5 || map->z_min > 5)
		diff = (map->z_max + map->z_min) / 2;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->coord[y][x][0] -= diff;
			x++;
		}
		y++;
	}
}

t_fdf	*new_fdf(t_map *map)
{
	t_fdf *fdf;

	if (!(fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf))))
		error_management(map, ER_MEM);
	fdf->zoom = WIDTH / (3.1 * map->width);
	fdf->offset_z = OFF_Z;
	fdf->shift_right = WIDTH / 2 - (fdf->zoom * map->width / 3) + LEGEND;
	fdf->shift_down = HEIGHT - (fdf->zoom * map->width / 1.5);
	fdf->angle = ANGLE;
	return (fdf);
}

t_map	*new_map(void)
{
	t_map *map;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	if (!map)
		error_management(map, ER_MEM);
	map->err = (t_err *)ft_memalloc(sizeof(t_err));
	if (!(map->err))
		error_management(map, ER_MEM);
	return (map);
}

void	processing(char *file)
{
	t_map		*map;
	int			fd;
	char		*err;

	map = new_map();
	if (!(fd = open(file, O_RDONLY)))
		error_management(map, RE);
	if ((err = height_width(&(map->width), &(map->height), fd)))
		error_management(map, err);
	close(fd);
	fd = open(file, O_RDONLY);
	fill_arr(map, fd);
	close(fd);
	visualize(map);
}

int		main(int ac, char **av)
{
	if (ac != 2)
		ft_putstr("usage: ./fdf source_file\n");
	else
		processing(av[1]);
	return (0);
}
