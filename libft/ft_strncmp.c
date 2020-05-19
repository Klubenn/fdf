/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:02:51 by cstill            #+#    #+#             */
/*   Updated: 2019/09/11 22:22:43 by cstill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t c;

	c = 0;
	if (n == 0)
		return (0);
	while (c < n && str1[c] != '\0')
	{
		if (str1[c] != str2[c])
			return ((unsigned char)str1[c] - (unsigned char)str2[c]);
		c++;
	}
	if (c == n)
		return (0);
	else
		return ((unsigned char)str1[c] - (unsigned char)str2[c]);
}
