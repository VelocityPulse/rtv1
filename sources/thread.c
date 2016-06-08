/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 14:54:05 by cchameyr          #+#    #+#             */
/*   Updated: 2016/06/08 16:28:01 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int		ft_thread1(void *data)
{
	t_rtv1		*rt;

	rt = (t_rtv1 *)data;
	while ()
	return (0);
}

int		ft_thread2(void *data)
{
	t_rtv1		*rt;

	rt = (t_rtv1 *)data;
	return (0);
}

int		ft_thread3(void *data)
{
	t_rtv1		*rt;

	rt = (t_rtv1 *)data;
	return (0);
}

int		ft_thread4(void *data)
{
	t_rtv1		*rt;

	rt = (t_rtv1 *)data;
	return (0);
}

void		ft_create_thread(t_rtv1 *rt)
{
	static SDL_Thread	*thread1;
	static SDL_Thread	*thread2;
	static SDL_Thread	*thread3;
	static SDL_Thread	*thread4;

	if (!(thread1 = SDL_CreateThread(ft_thread1, "thread1", (void *)rt)) ||
	!(thread2 = SDL_CreateThread(ft_thread2, "thread2", (void *)rt)) ||
	!(thread3 = SDL_CreateThread(ft_thread3, "thread3", (void *)rt)) ||
	!(thread4 = SDL_CreateThread(ft_thread4, "thread4", (void *)rt)))
	{
		ft_putendl(SDL_GetError());
		ft_destroy_sdl()
	}
}
