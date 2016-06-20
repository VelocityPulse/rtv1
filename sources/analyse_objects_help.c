/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_objects_help.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 12:16:13 by cchameyr          #+#    #+#             */
/*   Updated: 2016/06/20 11:38:23 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int		analyse_sphere_help(char **str, t_sphere *sphere)
{
	if (ft_memlen((void **)str) != 4 ||
			!analyse_3d_value_d(str[0], &sphere->x, &sphere->y,
			&sphere->z) ||
			!ft_strisdouble(str[1]) ||
			!ft_strisdigit(str[2]) ||
			!analyse_3d_value_v(str[3], &sphere->dir))
		return (0);
	else
		return (1);
}
