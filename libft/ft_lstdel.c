/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 22:42:46 by cstill            #+#    #+#             */
/*   Updated: 2019/09/16 23:00:06 by cstill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *arr;

	if (alst)
	{
		while (*alst)
		{
			del((*alst)->content, (*alst)->content_size);
			arr = *alst;
			*alst = (*alst)->next;
			free(arr);
			arr = NULL;
		}
	}
}
