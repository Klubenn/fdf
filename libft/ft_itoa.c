/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 21:45:55 by cstill            #+#    #+#             */
/*   Updated: 2019/09/20 20:22:20 by cstill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;

	if (n == -(2147483648))
		return (ft_strdup("-2147483648"));
	len = ft_nbrlen(n);
	if (!(str = (char *)malloc((len + 1) * sizeof(*str))))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	str[len] = '\0';
	while (n >= 10)
	{
		str[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	str[len - 1] = n + '0';
	return (str);
}
