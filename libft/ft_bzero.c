/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <cchameyr@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 12:39:37 by cchameyr          #+#    #+#             */
/*   Updated: 2015/11/30 12:11:51 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*c_s;

	c_s = (unsigned char *)s;
	i = 0;
	if (n > 0)
	{
		while (i < n)
		{
			c_s[i] = '\0';
			i++;
		}
	}
}
