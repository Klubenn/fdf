/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 22:14:12 by cstill            #+#    #+#             */
/*   Updated: 2019/09/22 01:47:33 by cstill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *dest, const char *src, size_t nb)
{
	size_t		i;
	char		*arr;

	arr = dest;
	i = 0;
	while (*dest)
		dest++;
	while (i < nb && *src != '\0')
	{
		*dest++ = *src++;
		i++;
	}
	*dest = '\0';
	return (arr);
}
