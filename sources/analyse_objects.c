/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 11:17:37 by cchameyr          #+#    #+#             */
/*   Updated: 2016/06/29 14:28:52 by                  ###   ########.fr       */
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
	*spot = (t_spot *)ft_memalloc(sizeof(t_spot) * (nb_obj + 1));
	while (++i < nb_obj)
	{
		next_line(list, line);
		if (ft_strncmp((*list)->line, "\t\t\t", 3) != 0)
			return (1);
		str = ft_strsplit(&(*list)->line[3], '/');
		if (!analyse_slash((*list)->line, 2) || ft_memlen((void **)str) != 2 ||
		!analyse_3d_value_d(str[0], &(*spot)[i].x, &(*spot)[i].y,
		&(*spot)[i].z) || !ft_strisdouble(str[1]))
			return (1);
		(*spot)[i].lux = ft_absd(ft_atoid(str[1]));
		ft_memdel2((void ***)&str);
	}
	(*spot)[nb_obj].end = -1;
	next_line(list, line);
	return (0);
}

int		analyse_sphere(t_sphere **sphere, t_lstline **list, int *line)
{
	int		nb_obj;
	char	**str;
	int		i;

	if (*sphere != NULL || !ft_strisdigit(&(*list)->line[11]))
		return (1);
	nb_obj = ft_atoi(&(*list)->line[11]);
	i = -1;
	*sphere = (t_sphere *)ft_memalloc(sizeof(t_sphere) * (nb_obj + 1));
	while (++i < nb_obj)
	{
		next_line(list, line);
		if (ft_strncmp((*list)->line, "\t\t\t", 3 != 0))
			return (1);
		str = ft_strsplit(&(*list)->line[3], '/');
		if (!analyse_sphere_help((*list)->line, str, &(*sphere)[i]))
			return (1);
		(*sphere)[i].radius = ft_absd(ft_atoid(str[1]));
		ft_memdel2((void ***)&str);
	}
	(*sphere)[nb_obj].end = -1;
	next_line(list, line);
	return (0);
}

int		analyse_cylindre(t_cylindre **cyl, t_lstline **list, int *line)
{
	int		nb_obj;
	char	**str;
	int		i;

	if (*cyl != NULL || !ft_strisdigit(&(*list)->line[13]))
		return (1);
	nb_obj = ft_atoi(&(*list)->line[13]);
	i = -1;
	*cyl = (t_cylindre *)ft_memalloc(sizeof(t_cylindre) * (nb_obj + 1));
	while (++i < nb_obj)
	{
		next_line(list, line);
		if (ft_strncmp((*list)->line, "\t\t\t", 3 != 0))
			return (1);
		str = ft_strsplit(&(*list)->line[3], '/');
		if (!analyse_cylindre_help((*list)->line, str, &(*cyl)[i]))
			return (1);
		(*cyl)[i].ray_size = ft_absd(ft_atoid(str[1]));
		(*cyl)[i].height = ft_absd(ft_atoid(str[2]));
		ft_memdel2((void ***)&str);
	}
	(*cyl)[nb_obj].end = -1;
	next_line(list, line);
	return (0);
}

int		analyse_cone(t_cone **cone, t_lstline **list, int *line)
{
	int		nb_obj;
	char	**str;
	int		i;

	if (*cone != NULL || !ft_strisdigit(&(*list)->line[9]))
		return (1);
	nb_obj = ft_atoi(&(*list)->line[9]);
	i = -1;
	*cone = (t_cone *)ft_memalloc(sizeof(t_cone) * (nb_obj + 1));
	while (++i < nb_obj)
	{
		next_line(list, line);
		if (ft_strncmp((*list)->line, "\t\t\t", 3) != 0)
			return (1);
		str = ft_strsplit(&(*list)->line[3], '/');
		if (!analyse_cone_help((*list)->line, str, &(*cone)[i]))
			return (1);
		(*cone)[i].ray_size = ft_absd(ft_atoid(str[1]));
		(*cone)[i].height = ft_absd(ft_atoid(str[2]));
		ft_memdel2((void ***)&str);
	}
	(*cone)[nb_obj].end = -1;
	next_line(list, line);
	return (0);
}

int		analyse_plan(t_plane **plane, t_lstline **list, int *line)
{
	int		nb_obj;
	char	**str;
	int		i;

	if (*plane != NULL || !ft_strisdigit(&(*list)->line[9]))
		return (1);
	nb_obj = ft_atoi(&(*list)->line[9]);
	i = -1;
	*plane = (t_plane *)ft_memalloc(sizeof(t_plane) * (nb_obj + 1));
	while (++i < nb_obj)
	{
		next_line(list, line);
		if (ft_strncmp((*list)->line, "\t\t\t", 3) != 0)
			return (1);
		str = ft_strsplit(&(*list)->line[3], '/');
		if (!analyse_plan_help((*list)->line, str, &(*plane)[i]))
			return (1);
		(*plane)[i].height = ft_absd(ft_atoid(str[1]));
		(*plane)[i].width = ft_absd(ft_atoid(str[2]));
		ft_memdel2((void ***)&str);
	}
	(*plane)[nb_obj].end = -1;
	next_line(list, line);
	return (0);
}

/*
** return 0 is a succes
** return 1 is a error
*/
