/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 11:17:37 by cchameyr          #+#    #+#             */
/*   Updated: 2016/06/17 16:58:59 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int		analyse_spot(t_spot **spot, t_lstline **list, int *line)
{
	int		nb_obj;
	char	**str;
	int		i;

	if (*spot != NULL || !ft_strisdigit(&(*list)->line[9]))
		return (1);
	nb_obj = ft_atoi(&(*list)->line[9]);
	i = -1;
	*spot = (t_spot *)ft_memalloc(sizeof(t_spot) * nb_obj);
	while (++i < nb_obj)
	{
		*list = (*list)->next;
		*line += 1;
		if (ft_strncmp((*list)->line, "\t\t\t", 3) != 0)
			return (1);
		str = ft_strsplit(&(*list)->line[3], '/');
		if (ft_memlen((void **)str) != 2 ||
		!analyse_3d_value_d(str[0], &(*spot)[i].x, &(*spot)[i].y,
			&(*spot)[i].z) ||
		!ft_strisdouble(str[1]))
			return (1);
		(*spot)[i].lux = ft_atoid(str[1]);
		ft_memdel2((void ***)&str);
	}
	*list = (*list)->next;
	*line += 1;
	return (0);
}

/*
** return 0 is succes
** return 1 is error
*/