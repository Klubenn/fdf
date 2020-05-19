/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:11:05 by cstill            #+#    #+#             */
/*   Updated: 2019/09/22 04:47:55 by cstill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *str, int ch)
{
	int len;

	len = 1;
	ch = (unsigned char)ch;
	while (*str)
	{
		str++;
		len++;
	}
	if (ch == '\0')
		return ((char*)str);
	while (len--)
	{
		if (ch == *str)
			return ((char*)str);
		str--;
	}
	return (NULL);
}
