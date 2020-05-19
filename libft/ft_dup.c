/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 20:31:07 by cstill            #+#    #+#             */
/*   Updated: 2019/09/20 20:58:15 by cstill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_dup(void const *content, size_t content_size)
{
	unsigned char		*set;
	unsigned char		*set2;
	void				*new;

	new = NULL;
	set = (unsigned char*)content;
	set2 = (unsigned char*)new;
	if (!(new = ft_memalloc(content_size)))
		return (NULL);
	while (*set)
		*(set2++) = *(set++);
	return (new);
}
