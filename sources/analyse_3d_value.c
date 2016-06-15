/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_3d_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 11:30:20 by cchameyr          #+#    #+#             */
/*   Updated: 2016/06/15 11:57:25 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static int		check_values(char **list_value)
{
	int		point;
	int		i;
	int		j;

	j = -1;
	while (list_value[++j])
	{
		point = 0;
		i = 0;
		while (list_value[j][i])
		{
			if (ft_isdigit(list_value[j][i]))
				i++;
			else if (list_value[j][i] == '.')
			{
				if (point == 0)
					point++;
				else
					return (0);
			}
			else
				return (0);
		}
	}
}

int				analyse_3d_value(char *str, double *x, double *y, double *z)
{
	char	**list_value;

	list_value = ft_strsplit(str, ' ');
	if (ft_memlen((void **)list_value) != 3)
		return (0);
	check_values(list_value);
}
