/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 21:01:14 by cstill            #+#    #+#             */
/*   Updated: 2019/09/22 01:46:07 by cstill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *sourse, size_t n)
{
	size_t				i;
	unsigned char		*s1;
	unsigned char		*s2;

	if (dest == sourse || n == 0)
		return (dest);
	s1 = (unsigned char *)dest;
	s2 = (unsigned char *)sourse;
	i = 0;
	if (s2 < s1)
		while (++i <= n)
			s1[n - i] = s2[n - i];
	else
		while (n-- > 0)
			*(s1++) = *(s2++);
	return (dest);
}
