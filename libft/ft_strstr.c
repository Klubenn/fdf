/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 21:31:11 by cstill            #+#    #+#             */
/*   Updated: 2019/09/20 19:11:49 by cstill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int v;

	i = 0;
	if (*to_find == '\0')
		return ((char*)str);
	while (str[i] != '\0')
	{
		v = 0;
		while (str[i + v] == to_find[v])
		{
			++v;
			if (to_find[v] == '\0')
				return ((char*)(str + i));
		}
		++i;
	}
	return (0);
}
