/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:06:31 by cstill            #+#    #+#             */
/*   Updated: 2019/09/21 22:34:59 by cstill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, const void *sourse, int c, size_t n)
{
	unsigned char			*s1;
	unsigned char			*dst;
	size_t					i;

	i = 0;
	s1 = (unsigned char*)sourse;
	dst = (unsigned char*)dest;
	while (i < n)
	{
		dst[i] = s1[i];
		if (s1[i] == (unsigned char)c)
			return ((void*)(dest + i + 1));
		i++;
	}
	return (NULL);
}
