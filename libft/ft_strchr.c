/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 20:24:53 by cstill            #+#    #+#             */
/*   Updated: 2019/09/11 20:42:50 by cstill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *str, int ch)
{
	int c;

	c = 0;
	while (str[c] != '\0')
	{
		if (str[c] == ch)
			return ((char*)str + c);
		c++;
	}
	if (str[c] == '\0' && ch == '\0')
		return ((char*)str + c);
	return (NULL);
}
