/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_3d_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 11:30:20 by cchameyr          #+#    #+#             */
/*   Updated: 2016/06/15 15:56:21 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static int		check_values(char **list_value)
{
	int		point;
	int		i;
	int		j;

	j = -1;
	while (list_value[++j] && !(i = 0))
	{
		if (!(point = 0) && list_value[j][i] == '-')
			i++;
		while (list_value[j][i])
		{
			if (ft_isdigit(list_value[j][i]))
				i++;
			else if (list_value[j][i++] == '.')
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
	return (1);
}

int				analyse_3d_value_d(char *str, double *x, double *y, double *z)
{
	char	**list_value;

	list_value = ft_strsplit(str, ' ');
	if (ft_memlen((void **)list_value) != 3)
		return (0);
	if (!check_values(list_value))
		return (0);
	*x = ft_atoid(list_value[0]);
	*y = ft_atoid(list_value[1]);
	*z = ft_atoid(list_value[2]);
	ft_memdel((void **)&list_value[0]);
	ft_memdel((void **)&list_value[1]);
	ft_memdel((void **)&list_value[2]);
	free(list_value);
	return (1);
}

int				analyse_3d_value_v(char *str, t_vector *v)
{
	char	**list_value;

	list_value = ft_strsplit(str, ' ');
	if (ft_memlen((void **)list_value) != 3)
		return (0);
	if (!check_values(list_value))
		return (0);
	v->x = ft_atoid(list_value[0]);
	v->y = ft_atoid(list_value[1]);
	v->z = ft_atoid(list_value[2]);
	ft_memdel((void **)&list_value[0]);
	ft_memdel((void **)&list_value[1]);
	ft_memdel((void **)&list_value[2]);
	free(list_value);
	return (1);
}
