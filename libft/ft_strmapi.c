/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 14:15:55 by cstill            #+#    #+#             */
/*   Updated: 2019/09/22 02:17:55 by cstill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		c;
	char				*dest;

	if (!s || !f)
		return (NULL);
	dest = ft_strnew(ft_strlen(s));
	if (!dest)
		return (NULL);
	c = 0;
	while (s[c])
	{
		dest[c] = (*f)(c, s[c]);
		c++;
	}
	return (dest);
}
