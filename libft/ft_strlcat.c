/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <cchameyr@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 19:10:26 by cchameyr          #+#    #+#             */
/*   Updated: 2015/11/29 10:01:38 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	size_dst;

	i = 0;
	size_dst = 0;
	if (dst)
	{
		while (dst[i] && i < size)
			i++;
		size_dst = i;
		while (src[i - size_dst] && i < size - 1)
		{
			dst[i] = src[i - size_dst];
			i++;
		}
		if (i < size)
			dst[i] = '\0';
	}
	return (size_dst + ft_strlen(src));
}
