/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:27:06 by cstill            #+#    #+#             */
/*   Updated: 2019/09/11 22:56:00 by cstill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int ch, size_t n)
{
	unsigned int c;

	c = 0;
	while (c < n)
	{
		if (((unsigned char *)arr)[c] == (unsigned char)ch)
			return ((void *)&((unsigned const char *)arr)[c]);
		c += 1;
	}
	return (NULL);
}
