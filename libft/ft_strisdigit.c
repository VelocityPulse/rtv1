/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 16:16:37 by cchameyr          #+#    #+#             */
/*   Updated: 2016/06/19 14:53:18 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strisdigit(char *str)
{
	int		i;
	int		end;

	i = -1;
	end = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if ((str[i] >= 48 || str[i] <= 57) && end == 0)
			i++;
		else if (str[i] == ' ')
			end = 1;
		else
			return (0);
	}
	return (1);
}
