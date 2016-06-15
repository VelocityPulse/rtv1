/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 11:26:38 by cchameyr          #+#    #+#             */
/*   Updated: 2016/06/15 15:40:17 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int				error_line(const int line)
{
	ft_putstr("\n\033[31mERROR\033[0m line : ");
	ft_putnbr(line);
	ft_putchar('\n');
	return (0);
}

static void		open_scene(t_rtv1 *rt, char *path)
{
	t_lstline	*list;
	int			fd;
	char		*line;

	list = NULL;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		list = ft_add_lstline(list, line);
	ft_memdel((void **)&line);
	if (analyse_scene(rt, list) == 0)
	{
		list = ft_lstline_del(list);
		exit_rt(rt);
	}
	list = ft_lstline_del(list);
}

static void		init_rt(t_rtv1 *rt, char *path)
{
	rt->t1 = 0;
	rt->t2 = 0;
	rt->t3 = 0;
	rt->t4 = 0;
	open_scene(rt, path);
	if (!(rt->env = ft_init_sdl(W_WIDTH, W_HEIGHT, "rtv1")))
		exit_rt(rt);
}

/*
** rt->t1,2,3,4 are the status of threads
** 1 = calculate
** 0 = in waiting
*/

void			start(char *path)
{
	t_rtv1		rt;
	SDL_Event	events;

	init_rt(&rt, path);
	create_thread(&rt);
	SDL_PushEvent(&events);
	while (SDL_WaitEvent(&events))
	{
		printf("------ EVENT ------\n");
		if (events.type == SDL_KEYDOWN)
			rt.scanvalue[events.key.keysym.scancode] = 1;
		if (events.type == SDL_KEYUP)
			rt.scanvalue[events.key.keysym.scancode] = 0;
		if (events.type == SDL_QUIT || rt.scanvalue[SDL_SCANCODE_ESCAPE] == 1)
			exit_rt(&rt);
		rt.t1 = 1;
		rt.t2 = 1;
		rt.t3 = 1;
		rt.t4 = 1;
		while (rt.t1 != 0 && rt.t2 != 0 && rt.t3 != 0 && rt.t4 != 0)
		{
			usleep(4000);
			printf("sleep\n");
		}
		SDL_BlitSurface(rt.env->img, NULL, SDL_GetWindowSurface(rt.env->win),
				NULL);
		SDL_UpdateWindowSurface(rt.env->win);
	}
}
