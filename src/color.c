/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 22:54:16 by cstill            #+#    #+#             */
/*   Updated: 2019/09/22 05:03:14 by cstill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_color(t_map *map)
{
	int i;
	int x;
	int y;

	x = (int)(map->fdf->shift_right + map->dr->x);
	y = (int)(map->fdf->shift_down + map->dr->y);
	if (x > LEGEND && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * map->fdf->bits_per_pixel / BYTE) + (y * map->fdf->size_line);
		map->fdf->address[i++] = map->dr->col;
		map->fdf->address[i++] = map->dr->col >> BYTE;
		map->fdf->address[i] = map->dr->col >> (BYTE * 2);
	}
}

int		is_hex(char *str)
{
	while (*str)
	{
		if ((*str >= '0' && *str <= '9') ||
			(*str >= 'a' && *str <= 'f') || (*str >= 'A' && *str <= 'F'))
			str++;
		else
			return (0);
	}
	return (1);
}

int		color(char *str, int *col)
{
	int check;

	if (!str)
		return (-1);
	if (!*str)
	{
		*col = WHITE;
		return (1);
	}
	else if (!ft_strncmp(",0x", str, 3))
	{
		*col = ft_atoi_base(str + 3, 16);
		if (!is_hex(str + 3))
			return (-1);
	}
	else if (str[1] < '0' || str[1] > '9')
		return (-1);
	else
	{
		check = atoi_fdf(&(str[1]), col);
		if (check == -1 || str[check + 1] == ',')
			return (-1);
	}
	return (0);
}

void	change_color2(t_map *map, float diff, int x, int y)
{
	float delta;

	delta = diff + map->z_min;
	if (map->coord[y][x][0] <= delta)
		map->coord[y][x][1] = DARK;
	else if (map->coord[y][x][0] <= delta + diff)
		map->coord[y][x][1] = BLUE;
	else if (map->coord[y][x][0] <= delta + 2 * diff)
		map->coord[y][x][1] = GREEN;
	else if (map->coord[y][x][0] <= delta + 3 * diff)
		map->coord[y][x][1] = YELLOW;
	else if (map->coord[y][x][0] <= delta + 4 * diff)
		map->coord[y][x][1] = ORANGE;
	else
		map->coord[y][x][1] = RED;
}

void	change_color1(t_map *map, int x, int y)
{
	float diff;

	diff = (float)(map->z_max - map->z_min) / COLORS;
	if (!map->color)
	{
		while (y < map->height)
		{
			x = 0;
			while (x < map->width)
			{
				change_color2(map, diff, x, y);
				x++;
			}
			y++;
		}
	}
}
