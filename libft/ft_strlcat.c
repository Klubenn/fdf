/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:59:14 by cstill            #+#    #+#             */
/*   Updated: 2019/09/19 22:29:47 by cstill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *str, size_t n)
{
	size_t			i;
	size_t			len;

	len = ft_strlen(dest) + ft_strlen(str);
	if (n < ft_strlen(dest))
		return (ft_strlen(str) + n);
	while (*dest)
	{
		dest++;
	}
	i = 0;
	while ((i < n - (len - ft_strlen(str)) - 1) && str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}
