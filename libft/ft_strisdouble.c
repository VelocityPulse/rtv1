/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisdouble.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 12:52:24 by cchameyr          #+#    #+#             */
/*   Updated: 2016/06/17 15:10:59 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strisdouble(char *str)
{
	int		i;
	int		dot;

	i = 0;
	dot = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			;
		else if (str[i] == '.')
		{
			dot++;
			if (dot > 1)
				return (0);
		}
		else
			return (0);
		i++;
	}
	return (1);
}
