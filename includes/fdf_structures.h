/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structures.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 22:55:09 by gtristan          #+#    #+#             */
/*   Updated: 2020/05/02 22:55:11 by gtristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTURES_H
# define FDF_STRUCTURES_H

typedef struct		s_draw
{
	double		x;
	double		y;
	double		z;
	int			col;
	double		x_angle;
	double		y_angle;
	double		z_angle;

}					t_draw;

typedef struct		s_dot
{
	int			x;
	int			y;
	int			z;
	int			color;
}					t_dot;

typedef struct		s_fdf
{
	double		x0;
	double		y0;
	double		z0;
	int			col0;
	double		x1;
	double		y1;
	double		z1;
	int			col1;
	double		zoom;
	double		offset_z;
	int			shift_right;
	int			shift_down;
	double		angle;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*address;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			projection;
}					t_fdf;

typedef struct		s_err
{
	int			x;
	int			y;
	int			i;
	int			j;
	char		**arr;
}					t_err;

typedef struct		s_map
{
	int			height;
	int			width;
	int			color;
	int			***coord;
	int			z_min;
	int			z_max;
	t_fdf		*fdf;
	t_draw		*dr;
	t_dot		*dot;
	t_err		*err;
}					t_map;

#endif
