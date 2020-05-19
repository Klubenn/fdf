/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 22:54:16 by cstill            #+#    #+#             */
/*   Updated: 2019/09/22 05:03:14 by cstill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_err(t_map *map, int j, int i)
{
	int		k;

	map->err->i = i;
	(map->coord)[j][i] = (int *)ft_memalloc((sizeof(int) * 2));
	k = atoi_fdf(map->err->arr[i], &((map->coord)[j][i][0]));
	if (k == -1)
		error_management(map, WH);
	k = color(&(map->err->arr[i][k]), &((map->coord)[j][i][1]));
	if (k == -1)
		error_management(map, WC);
	if (k != 1)
		map->color = 1;
	free(map->err->arr[i]);
	if (i == 0 && j == 0)
	{
		map->z_max = (map->coord)[j][i][0];
		map->z_min = (map->coord)[j][i][0];
	}
	map->z_max = (map->z_max >= map->coord[j][i][0]) ?
				map->z_max : map->coord[j][i][0];
	map->z_min = (map->z_min <= map->coord[j][i][0]) ?
				map->z_min : map->coord[j][i][0];
}

void	error_management(t_map *map, char *err)
{
	int i;

	if (err)
		ft_putstr(err);
	if (map && map->err)
	{
		i = map->err->i;
		if (map->err->arr)
		{
			while (i < map->width)
			{
				if (map->err->arr[i])
					free(map->err->arr[i]);
				i++;
			}
			free(map->err->arr);
		}
		shutdown(map);
	}
	exit(1);
}

void	shutdown2(t_map *map, int x, int y)
{
	if (map->err->j || map->err->i)
	{
		while (y <= map->err->j)
		{
			x = 0;
			while ((y < map->err->j && x < map->width) ||
					(y == map->err->j && x <= map->err->i))
			{
				if (map->coord[y][x])
					free(map->coord[y][x]);
				x++;
			}
			free(map->coord[y]);
			y++;
		}
	}
	else if (map->coord[0])
	{
		if (map->coord[0][0])
			free(map->coord[0][0]);
		free(map->coord[0]);
	}
	free(map->coord);
}

int		shutdown(t_map *map)
{
	if (map)
	{
		if (map->coord)
			shutdown2(map, 0, 0);
		free(map->err);
		if (map->fdf)
			free(map->fdf);
		if (map->dr)
			free(map->dr);
		if (map->dot)
			free(map->dot);
		free(map);
	}
	exit(0);
}
