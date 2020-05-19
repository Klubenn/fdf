/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 22:54:16 by cstill            #+#    #+#             */
/*   Updated: 2019/09/22 05:03:14 by cstill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	height_width3(int *x0, char ch, int *t)
{
	if (ch == ' ')
		*t = 0;
	else
	{
		if (*t == 0)
			(*x0)++;
		*t = 1;
	}
}

static char	*height_width2(int *x, int *y, int *x0, int *t)
{
	if (*y == 0)
		*x = *x0;
	if (*x != *x0)
		return (CO);
	(*y)++;
	*x0 = 0;
	*t = 0;
	return (NULL);
}

char		*height_width(int *x, int *y, int fd)
{
	int		x0;
	int		t;
	char	ch[1];
	char	*ret;

	if (read(fd, ch, 0) < 0)
		return (RE);
	t = 0;
	x0 = 0;
	while (read(fd, ch, 1))
	{
		if (*ch == '\n')
		{
			if ((ret = height_width2(x, y, &x0, &t)))
				return (ret);
		}
		else
			height_width3(&x0, *ch, &t);
	}
	if (*ch != '\n')
		return (CO);
	return (NULL);
}

int			atoi_fdf(char *str, int *num)
{
	long long		res;
	int				sign;
	int				len;
	int				err;

	sign = 1;
	res = 0;
	len = 0;
	err = 0;
	if (str[len] == '-' && ++err && ++len)
		sign = -1;
	else if (str[len] == '+' && ++err)
		len++;
	while (str[len] >= '0' && str[len] <= '9' && len <= 11)
	{
		res = res * 10 + (str[len] - '0');
		len++;
	}
	if ((res > 2147483647 && sign == 1) || (res > 2147483648 && sign == -1)
		|| len > 11 || (str[len] && str[len] != ',') || (len == 1 && err == 1))
		return (-1);
	*num = ((int)res * sign);
	return (len);
}

void		fill_arr(t_map *map, int fd)
{
	int		j;
	int		i;
	char	*line;

	j = 0;
	map->coord = (int ***)ft_memalloc(sizeof(int **) * map->height);
	while (get_next_line(fd, &line))
	{
		map->err->j = j;
		map->err->arr = ft_strsplit(line, ' ');
		free(line);
		if (!(map->err->arr) || !(map->err->arr[0]))
			error_management(map, BC);
		(map->coord)[j] = (int **)ft_memalloc(sizeof(int *) * map->width);
		i = -1;
		while (++i < map->width && map->err->arr[i])
		{
			fill_err(map, j, i);
		}
		free(map->err->arr);
		j++;
	}
	change_z(map);
	change_color1(map, 0, 0);
}
