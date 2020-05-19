/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 14:01:12 by cstill            #+#    #+#             */
/*   Updated: 2019/09/22 02:16:38 by cstill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char		*dest;
	int			c;

	if (s && f)
	{
		dest = ft_strnew(ft_strlen(s));
		if (!dest)
			return (NULL);
		c = 0;
		while (s[c] != '\0')
		{
			dest[c] = f(s[c]);
			c++;
		}
		return (dest);
	}
	return (NULL);
}
