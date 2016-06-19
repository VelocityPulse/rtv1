/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_3d_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 11:30:20 by cchameyr          #+#    #+#             */
/*   Updated: 2016/06/19 15:07:48 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int				analyse_3d_value_d(char *str, double *x, double *y, double *z)
{
	char	**list_value;
	int		j;

	list_value = ft_strsplit(str, ' ');
	if (ft_memlen((void **)list_value) != 3)
		return (0);
	j = -1;
	while (list_value[++j])
	{
		if (!ft_strisdouble(list_value[j]))
			return (0);
	}
	*x = ft_atoid(list_value[0]);
	*y = ft_atoid(list_value[1]);
	*z = ft_atoid(list_value[2]);
	ft_memdel2((void ***)&list_value);
	return (1);
}

int				analyse_3d_value_v(char *str, t_vector *v)
{
	char	**list_value;
	int		j;

	list_value = ft_strsplit(str, ' ');
	if (ft_memlen((void **)list_value) != 3)
		return (0);
	j = -1;
	while (list_value[++j])
	{
		if (!ft_strisdouble(list_value[j]))
			return (0);
	}
	v->x = ft_atoid(list_value[0]);
	v->y = ft_atoid(list_value[1]);
	v->z = ft_atoid(list_value[2]);
	ft_memdel2((void ***)&list_value);
	return (1);
}
