/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisdouble.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 12:52:24 by cchameyr          #+#    #+#             */
/*   Updated: 2016/06/24 14:55:55 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_back_number(char *str)
{
	int		i;

	i = -1;
	while (str[++i] == ' ')
		;
	if (str[i] == '-' || str[i] == '+')
		i++;
	return (i);
}

int				ft_strisdouble(char *str)
{
	int		i;
	int		dot;
	int		end;

	dot = 0;
	end = 0;
	i = ft_back_number(str);
	while (str[i])
	{
		if (ft_isdigit(str[i]) && end == 0)
			;
		else if (str[i] == '.' && end == 0)
		{
			dot++;
			if (dot > 1)
				return (0);
		}
		else if (str[i] == ' ')
			end = 1;
		else
			return (0);
		i++;
	}
	return (1);
}
