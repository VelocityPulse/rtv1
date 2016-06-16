/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 15:58:04 by cchameyr          #+#    #+#             */
/*   Updated: 2016/06/16 16:32:53 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static int		analyse_objects(t_rtv1 *rt, t_lstline **list, int *line)
{
	int		error;

	error = 0;
	while (ft_strncmp((*list)->line, "\t\t##spot ", 9) == 0 ||
			ft_strncmp((*list)->line, "\t\t##sphere ", 11) == 0 ||
			ft_strncmp((*list)->line, "\t\t##cylindre ", 13) == 0 ||
			ft_strncmp((*list)->line, "\t\t##cone ", 9) == 0 ||
			ft_strncmp((*list)->line, "\t\t##plan ", 9) == 0)
	{
		if (ft_strncmp((*list)->line, "\t\t##spot ", 9) == 0)
			error += analyse_spot(&rt->obj.spot, list, line);
		else if (ft_strncmp((*list)->line, "\t\t##sphere ", 11) == 0)
			error += analyse_sphere(&rt->obj.sphere, list, line);
		else if (ft_strncmp((*list)->line, "\t\t##cylindre ", 13) == 0)
			error += analyse_cylindre(&rt->obj.cylindre, list, line);
		else if (ft_strncmp((*list)->line, "\t\t##cone ", 9) == 0)
			error += analyse_cone(&rt->obj.cone, list, line);
		else if (ft_strncmp((*list)->line, "\t\t##plan ", 9) == 0)
			error += analyse_plan(&rt->obj.plan, list, line);
		else if (ft_strcmp((*list)->line, "#End#") == 0)
			return (1);
		if (error >= 1)
			return (error_line(*line));
	}
	return (error_line(*line));
}

static int		analyse_cam(t_rtv1 *rt, t_lstline **list, int *line)
{
	if ((*list)->line && ft_strcmp((*list)->line, "\t###Cam") == 0)
	{
		(*list) = (*list)->next;
		if (ft_strncmp((*list)->line, "\t\t", 2) == 0)
		{
			if (!analyse_3d_value_d(&(*list)->line[2], &rt->cam.x, &rt->cam.y,
					&rt->cam.z))
				return (error_line(*line));
			*list = (*list)->next;
			if (ft_strncmp((*list)->line, "\t\t", 2) == 0 && (*line += 1))
			{
				if (!analyse_3d_value_v(&(*list)->line[2], &rt->cam.dir))
					return (error_line(*line));
			}
			else
				return (error_line(*line));
		}
		else
			return (error_line(*line));
	}
	else
		return (error_line(*line));
	return (1);
}

int				analyse_scene(t_rtv1 *rt, t_lstline *list)
{
	int		line;

	line = 1;
	if (list->line && ft_strcmp(list->line, "#Scene#") == 0)
	{
		line++;
		list = list->next;
		if (!analyse_cam(rt, &list, &line))
			return (0);
		line++;
		list = list->next;
		if (list->line && ft_strcmp(list->line, "\t###Objetcs") == 0)
		{
			line++;
			list = list->next;
			if (!analyse_objects(rt, &list, &line))
				return (0);
		}
		else
			error_line(line);
	}
	else
		error_line(line);
	return (1);
}

/*
	printf("x : %f y : %f z : %f\nrotx : %f roty : %f rotz : %f\n",
	rt->cam.x, rt->cam.y, rt->cam.z, rt->cam.dir.x, rt->cam.dir.y,
	rt->cam.dir.z);
*/

