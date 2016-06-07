/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 13:45:24 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/15 13:45:26 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *t;

	t = (unsigned char *)b;
	while (len > 0)
	{
		len--;
		t[len] = (unsigned char)c;
	}
	b = (void *)t;
	return (b);
}
