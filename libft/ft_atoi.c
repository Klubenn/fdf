/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 22:53:39 by cstill            #+#    #+#             */
/*   Updated: 2019/09/22 05:03:14 by cstill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_intcount(char *str)
{
	int i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}

static int		check_long(char *str, long si)
{
	int		int_count;

	int_count = ft_intcount(str);
	if (si > 0 && (int_count > 18
	|| (int_count == 18 && ft_strcmp(str, "9223372036854775807") > 0)))
		return (-1);
	else if (si < 0 && (int_count > 18
	|| (int_count == 18 && ft_strcmp(str, "-9223372036854775808") > 0)))
		return (0);
	else
		return (1);
}

int				ft_atoi(char *str)
{
	int				i;
	long			si;
	unsigned long	res;

	i = 0;
	si = 1;
	while (str[i] == '\n' || str[i] == ' ' || str[i] == '\r' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == '\t')
		i++;
	if (str[i] == '-' && ++i)
		si = -1;
	if (str[i] == '+' && si != -1)
		i++;
	else if (str[i] == '+' && si == -1)
		return (0);
	if ((res = check_long(str + i, si)) != 1)
		return (res);
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * si);
}
