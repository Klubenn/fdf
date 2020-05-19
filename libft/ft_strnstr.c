/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:42:21 by cstill            #+#    #+#             */
/*   Updated: 2019/09/11 22:01:22 by cstill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *dest, const char *str, size_t n)
{
	size_t c;

	if (*str == '\0')
		return ((char *)dest);
	c = ft_strlen(str);
	while (*dest != '\0' && n >= c)
	{
		if (ft_strncmp(dest, str, c) == 0)
			return ((char *)dest);
		dest++;
		n--;
	}
	return (NULL);
}
