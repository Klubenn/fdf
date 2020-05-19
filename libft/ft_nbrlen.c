/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 20:12:19 by cstill            #+#    #+#             */
/*   Updated: 2019/09/20 20:15:13 by cstill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_nbrlen(int n)
{
	int size;

	size = 0;
	if (n < 0)
		size++;
	while (n / 10 != 0)
	{
		n = n / 10;
		size++;
	}
	size++;
	return (size);
}