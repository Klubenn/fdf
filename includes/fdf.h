/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 22:55:09 by gtristan          #+#    #+#             */
/*   Updated: 2020/05/02 22:55:11 by gtristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include <math.h>
# include <stdio.h>
# include "fdf_defines.h"
# include "fdf_structures.h"

char	*height_width(int *x, int *y, int fd);
void	error_management(t_map *map, char *err);
int		shutdown(t_map *map);
int		atoi_fdf(char *str, int *num);
int		is_hex(char *str);
int		color(char *str, int *col);
void	change_color2(t_map *map, float diff, int x, int y);
void	change_color1(t_map *map, int x, int y);
void	fill_arr(t_map *map, int fd);
t_fdf	*new_fdf(t_map *map);
t_map	*new_map(void);
void	processing(char *file);
int		main(int ac, char **av);
void	iso(double *x, double *y, double z, t_map *map);
void	visualize(t_map *map);
int		maxmod(t_fdf *fdf);
void	put_color(t_map *map);
void	legend(t_map *map);
void	draw2(t_map *map);
void	xyz_transf(double *x, double *y, double *z, t_map *map);
void	draw1(t_map *map, int x, int y);
int		key_hook(int key, t_map *map);
int		rotation(int key, t_map *map);
int		mouse_move(int mouse, int x, int y, t_map *map);
void	fill_err(t_map *map, int j, int i);
void	zoom_width(t_map *map, int x, int y);
void	zoom_height(t_map *map, int x, int y);
int		get_light(int start, int end, double percentage);
int		ft_get_color(t_map *map, double dz, double dy, double dx);
double	distance(int first, int last, int current);
void	change_z(t_map *map);

#endif
