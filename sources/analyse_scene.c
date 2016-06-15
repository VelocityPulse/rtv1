/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 15:58:04 by cchameyr          #+#    #+#             */
/*   Updated: 2016/06/15 11:27:36 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"


static int		analyse_cam(t_rtv1 *rt, t_lstline **list, int *line)
{
	if ((*list)->line && ft_strcmp((*list)->line, "\t###cam") == 0)
	{
		(*list) = (*list)->next;
		if (ft_strncmp((*list)->line, "\t\t", 2) == 0)
		{
			analyse_3d_value(&(*list)->line[2], &rt->cam.x, &rt->cam.y,
					&rt->cam.z);
			
		}
		else
			error_line(*line);
	}
	else
		error_line(*line);
	return (1);
}

int				analyse_scene(t_rtv1 *rt, t_lstline *list)
{
	int		line;

	line = 1;
	if (list->line && ft_strcmp(list->line, "#scene#\n") == 0)
	{
		line++;
		list = list->next;
		if (analyse_cam(rt, &list, &line) == 0)
			return (0);
	}
	else
		error_line(line);
	return (1);
}
