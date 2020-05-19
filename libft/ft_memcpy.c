/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 23:00:13 by cstill            #+#    #+#             */
/*   Updated: 2019/09/22 01:45:21 by cstill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *s2, size_t n)
{
	unsigned char	*dest;
	unsigned char	*str;
	size_t			i;

	dest = (unsigned char*)dst;
	str = (unsigned char*)s2;
	i = 0;
	if (n == 0 || dst == s2)
		return (dst);
	while (i < n && n != 0)
	{
		dest[i] = str[i];
		i++;
	}
	return (dst);
}
