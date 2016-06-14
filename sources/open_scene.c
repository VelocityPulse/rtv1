/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 12:45:56 by cchameyr          #+#    #+#             */
/*   Updated: 2016/06/14 12:49:04 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_open_scene(t_rtv1 *rt, int ac, char **av)
{
	t_lstline	*list;
	int			fd;
	char		*line;

	list = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		
	}
}
