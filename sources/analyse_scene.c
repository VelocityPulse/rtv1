/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 15:58:04 by cchameyr          #+#    #+#             */
/*   Updated: 2016/06/14 16:38:28 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static int		analyse_cam(t_rtv1 *rt, t_lstline **list, int *line)
{
	if ((*list)->line && ft_strcmp((*list)->line, "\t###cam") == 0)
	{
		(*list) = (*list)->next;
		
	}
	else
	{
		ft_putendl("Error line 2");
		return (0);
	}
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
	{
		ft_putendl("Error line 1");
		return (0);
	}
	return (1);
}
