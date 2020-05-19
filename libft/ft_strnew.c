/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:41:29 by cstill            #+#    #+#             */
/*   Updated: 2019/09/12 21:50:37 by cstill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char *arr;

	arr = (char *)malloc((size + 1) * sizeof(char));
	if (arr)
		ft_memset(arr, '\0', size + 1);
	return (arr);
}
