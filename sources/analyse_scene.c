/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 15:58:04 by cchameyr          #+#    #+#             */
/*   Updated: 2016/06/19 13:02:26 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void			next_line(t_lstline **list, int *line)
{
	*list = (*list)->next;
	*line += 1;
}

static int		analyse_objects(t_rtv1 *rt, t_lstline **list, int *line)
{
	int		error;

	error = 0;
	while (ft_strncmp((*list)->line, "\t\t##spot ", 9) == 0 ||
		ft_strncmp((*list)->line, "\t\t##sphere ", 11) == 0 ||
		ft_strncmp((*list)->line, "\t\t##cylindre ", 13) == 0 ||
		ft_strncmp((*list)->line, "\t\t##cone ", 9) == 0 ||
		ft_strncmp((*list)->line, "\t\t##plan ", 9) == 0 ||
		ft_strncmp((*list)->line, "#End#", 5) == 0)
	{
		if (ft_strncmp((*list)->line, "\t\t##spot ", 9) == 0)
			error += analyse_spot(&rt->obj.spot, list, line);
		else if (ft_strncmp((*list)->line, "\t\t##sphere ", 11) == 0)
			error += analyse_sphere(&rt->obj.sphere, list, line);
/*		else if (ft_strncmp((*list)->line, "\t\t##cylindre ", 13) == 0)
			error += analyse_cylindre(&rt->obj.cylindre, list, line);
		else if (ft_strncmp((*list)->line, "\t\t##cone ", 9) == 0)
			error += analyse_cone(&rt->obj.cone, list, line);
		else if (ft_strncmp((*list)->line, "\t\t##plan ", 9) == 0)
			error += analyse_plan(&rt->obj.plan, list, line);
*/		else if (ft_strncmp((*list)->line, "#End#", 5) == 0)
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
		next_line(list, line);
		if (ft_strncmp((*list)->line, "\t\t", 2) == 0)
		{
			if (!analyse_3d_value_d(&(*list)->line[2], &rt->cam.x, &rt->cam.y,
					&rt->cam.z))
				return (error_line(*line));
			next_line(list, line);
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
	return (1);
}

int				analyse_scene(t_rtv1 *rt, t_lstline *list)
{
	int		line;

	line = 1;
	if (list->line && ft_strcmp(list->line, "#Scene#") == 0)
	{
		next_line(&list, &line);
		if (!analyse_cam(rt, &list, &line))
			return (0);
		next_line(&list, &line);
		if (list->line && ft_strcmp(list->line, "\t###Objects") == 0)
		{
			next_line(&list, &line);
			if (!analyse_objects(rt, &list, &line))
				return (0);
		}
		else
			return (error_line(line));
	}
	else
		return (error_line(line));
	printf("\nCam :\n%f %f %f\n%f %f %f\n",
	rt->cam.x, rt->cam.y, rt->cam.z, rt->cam.dir.x, rt->cam.dir.y,
	rt->cam.dir.z);
	printf("spot1 :\n%f %f %f / %f\n", rt->obj.spot[0].x,
	rt->obj.spot[0].y, rt->obj.spot[0].z, rt->obj.spot[0].lux);
	printf("spot2 :\n%f %f %f / %f\n", rt->obj.spot[1].x,
	rt->obj.spot[1].y, rt->obj.spot[1].z, rt->obj.spot[1].lux);
	printf("spot3 :\n%f %f %f / %f\n", rt->obj.spot[2].x,
	rt->obj.spot[2].y, rt->obj.spot[2].z, rt->obj.spot[2].lux);
	printf("sphere 1 :\n%f %f %f / %f / %d / %f %f %f\n", rt->obj.sphere[0].x,
		rt->obj.sphere[0].y, rt->obj.sphere[0].z, rt->obj.sphere[0].radius,
		rt->obj.sphere[0].color, rt->obj.sphere[0].dir.x, rt->obj.sphere[0].dir.y,
		rt->obj.sphere[0].dir.z);
	printf("sphere 2 :\n%f %f %f / %f / %d / %f %f %f\n", rt->obj.sphere[1].x,
		rt->obj.sphere[1].y, rt->obj.sphere[1].z, rt->obj.sphere[1].radius,
		rt->obj.sphere[1].color, rt->obj.sphere[1].dir.x, rt->obj.sphere[1].dir.y,
		rt->obj.sphere[1].dir.z);


	return (1);
}

/*
	printf("x : %f y : %f z : %f\nrotx : %f roty : %f rotz : %f\n",
	rt->cam.x, rt->cam.y, rt->cam.z, rt->cam.dir.x, rt->cam.dir.y,
	rt->cam.dir.z);
	printf("spot1 :\nx : %f, y : %f, z : %f / %f\n", rt->obj.spot[0]->x,
	rt->obj.spot[0]->y, rt->obj.spot[0]->z, rt->obj.spot[0]->lux);
*/

