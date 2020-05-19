/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:56:55 by cstill            #+#    #+#             */
/*   Updated: 2019/09/12 20:12:00 by cstill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int c;

	c = 0;
	while ((c < n) && ((unsigned char *)s1)[c] == ((unsigned char *)s2)[c])
		c += 1;
	if (c == n)
		return (0);
	else
		return (((unsigned char *)s1)[c] - ((unsigned char *)s2)[c]);
}
