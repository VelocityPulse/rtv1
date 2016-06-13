/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 11:26:38 by cchameyr          #+#    #+#             */
/*   Updated: 2016/06/13 15:47:36 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static void		ft_init_rt(t_rtv1 *rt)
{
	rt->t1 = 0;
	rt->t2 = 0;
	rt->t3 = 0;
	rt->t4 = 0;
	if (!(rt->env = ft_init_sdl(W_WIDTH, W_HEIGHT, "rtv1")))
		ft_exit_rt(rt);
}

/*
** rt->t1,2,3,4 are the status of threads
** 1 = calculate
** 0 = in waiting
*/

void			start(void)
{
	t_rtv1		rt;
	SDL_Event	events;

	ft_init_rt(&rt);
	ft_create_thread(&rt);
	SDL_PushEvent(&events);
	while (SDL_WaitEvent(&events))
	{
		printf("------ EVENT ------\n");
		if (events.type == SDL_KEYDOWN)
			rt.scanvalue[events.key.keysym.scancode] = 1;
		if (events.type == SDL_KEYUP)
			rt.scanvalue[events.key.keysym.scancode] = 0;
		if (events.type == SDL_QUIT || rt.scanvalue[SDL_SCANCODE_ESCAPE] == 1)
			ft_exit_rt(&rt);
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
	return ;
}
