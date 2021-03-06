/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_objects_help.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 12:16:13 by cchameyr          #+#    #+#             */
/*   Updated: 2016/06/29 14:29:16 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int		analyse_slash(char *str, int nb_value)
{
	int		i;
	int		cpt;

	i = -1;
	cpt = 0;
	while (str[++i])
	{
		if (str[i] == '/')
			cpt++;
	}
	if (cpt != nb_value - 1)
		return (0);
	return (1);
}

int		analyse_sphere_help(char *line, char **str, t_sphere *sphere)
{
	char	*pref;

	if (!analyse_slash(line, 3) ||
		ft_memlen((void **)str) != 3 ||
		!analyse_3d_value_d(str[0], &sphere->x, &sphere->y, &sphere->z) ||
		!ft_strisdouble(str[1]) ||
		!ft_strishexa(str[2]))
		return (0);
	if ((pref = ft_strstr(str[2], "0x")))
		sphere->color = ft_abs(ft_atoi_base(&pref[2], 16));
	else
		sphere->color = ft_abs(ft_atoi_base(str[2], 16));
	return (1);
}

int		analyse_cylindre_help(char *line, char **str, t_cylindre *cyl)
{
	char	*pref;

	if (!analyse_slash(line, 5) ||
		ft_memlen((void **)str) != 5 ||
		!analyse_3d_value_d(str[0], &cyl->x, &cyl->y, &cyl->z) ||
		!ft_strisdouble(str[1]) ||
		!ft_strisdouble(str[2]) ||
		!ft_strishexa(str[3]) ||
		!analyse_3d_value_v(str[4], &cyl->rot))
		return (0);
	if ((pref = ft_strstr(str[2], "0x")))
		cyl->color = ft_abs(ft_atoi_base(&pref[2], 16));
	else
		cyl->color = ft_abs(ft_atoi_base(str[3], 16));
	return (1);
}

int		analyse_cone_help(char *line, char **str, t_cone *cone)
{
	char	*pref;

	if (!analyse_slash(line, 5) ||
		ft_memlen((void **)str) != 5 ||
		!analyse_3d_value_d(str[0], &cone->x, &cone->y, &cone->z) ||
		!ft_strisdouble(str[1]) ||
		!ft_strisdouble(str[2]) ||
		!ft_strishexa(str[3]) ||
		!analyse_3d_value_v(str[4], &cone->rot))
		return (0);
	if ((pref = ft_strstr(str[2], "0x")))
		cone->color = ft_abs(ft_atoi_base(&pref[2], 16));
	else
		cone->color = ft_abs(ft_atoi_base(str[3], 16));
	return (1);
}

int		analyse_plan_help(char *line, char **str, t_plane *plan)
{
	char	*pref;

	if (!analyse_slash(line, 5) ||
		ft_memlen((void **)str) != 5 ||
		!analyse_3d_value_d(str[0], &plan->x, &plan->y, &plan->z) ||
		!ft_strisdouble(str[1]) ||
		!ft_strisdouble(str[2]) ||
		!ft_strishexa(str[3]) ||
		!analyse_3d_value_v(str[4], &plan->rot))
		return (0);
	if ((pref = ft_strstr(str[2], "0x")))
		plan->color = ft_abs(ft_atoi_base(&pref[2], 16));
	else
		plan->color = ft_abs(ft_atoi_base(str[3], 16));
	return (1);
}
