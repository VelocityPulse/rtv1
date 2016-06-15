/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 14:40:27 by cchameyr          #+#    #+#             */
/*   Updated: 2016/06/15 14:40:29 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_itoa_len(long n)
{
	int len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len = ft_itoa_len(n);
		len++;
	}
	else if (n >= 10)
	{
		len = ft_itoa_len(n / 10);
		len++;
	}
	else
		len++;
	return (len);
}

char		*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	nbr;

	nbr = n;
	len = ft_itoa_len(nbr);
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (n < 0)
		nbr = -nbr;
	while (len)
	{
		len--;
		str[len] = 48 + (nbr % 10);
		nbr = nbr / 10;
	}
	if (str[len] == '0' && str[1] != '\0')
		str[len] = '-';
	return (str);
}
