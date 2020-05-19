/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 23:30:05 by cstill            #+#    #+#             */
/*   Updated: 2019/09/22 03:16:24 by cstill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *arr;
	t_list *str;

	if (!lst)
		return (NULL);
	arr = f(lst);
	if (arr == NULL)
		return (NULL);
	str = arr;
	while (lst->next)
	{
		lst = lst->next;
		str->next = f(lst);
		if (str->next == NULL)
			return (NULL);
		str = str->next;
	}
	return (arr);
}
