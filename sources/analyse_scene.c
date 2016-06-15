/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 15:58:04 by cchameyr          #+#    #+#             */
/*   Updated: 2016/06/15 15:44:58 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"


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
			if (ft_strncmp((*list)->line, "\t\t", 2) == 0)
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
	*list = (*list)->next;
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
		printf("x : %f y : %f z : %f\nrotx : %f roty : %f rotz : %f\n",
				rt->cam.x, rt->cam.y, rt->cam.z, rt->cam.dir.x, rt->cam.dir.y, 
				rt->cam.dir.z);
		sleep(1000000000);
	}
	else
		error_line(line);
	return (1);
}
