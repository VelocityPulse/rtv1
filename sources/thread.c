/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 14:54:05 by cchameyr          #+#    #+#             */
/*   Updated: 2016/06/13 16:15:52 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int		ft_thread1(void *data)
{
	t_rtv1		*rt;
	int			x;
	int			y;
	int			mid_w;
	int			mid_h;

	rt = (t_rtv1 *)data;
	mid_w = W_WIDTH / 2;
	mid_h = W_HEIGHT / 2;
	while (1)
	{
		if (rt->t1 == 1)
		{
			ft_putstr("core 1\n");
			x = -1;
			while (++x <= mid_w)
			{
				y = -1;
				while (++y <= mid_h)
					raytracing(x, y, rt->env);
			}
			rt->t1 = 0;
		}
		usleep(THREAD_SLEEP);
	}
	return (0);
}

/*
** THREAD1
** X O
** O O
*/

int		ft_thread2(void *data)
{
	t_rtv1		*rt;
	int			x;
	int			y;
	int			mid_w;
	int			mid_h;

	rt = (t_rtv1 *)data;
	mid_w = W_WIDTH / 2;
	mid_h = W_HEIGHT / 2;
	while (1)
	{
		if (rt->t2 == 1)
		{
			ft_putstr("core 2\n");
			x = mid_w;
			while (++x < W_WIDTH)
			{
				y = -1;
				while (++y <= mid_h)
					raytracing(x, y, rt->env);
			}
			rt->t2 = 0;
		}
		usleep(THREAD_SLEEP);
	}
	return (0);
}

/*
** THREAD2
** O X
** O O
*/

int		ft_thread3(void *data)
{
	t_rtv1		*rt;
	int			x;
	int			y;
	int			mid_w;
	int			mid_h;

	rt = (t_rtv1 *)data;
	mid_w = W_WIDTH / 2;
	mid_h = W_HEIGHT / 2;
	while (1)
	{
		if (rt->t3 == 1)
		{
			ft_putstr("core 3\n");
			x = -1;
			while (++x <= mid_w)
			{
				y = mid_h;
				while (++y < W_HEIGHT)
					raytracing(x, y, rt->env);
			}
			rt->t3 = 0;
		}
		usleep(THREAD_SLEEP);
	}
	return (0);
}

/*
** THREAD3
** O O
** X O
*/

int		ft_thread4(void *data)
{
	t_rtv1		*rt;
	int			x;
	int			y;
	int			mid_w;
	int			mid_h;

	rt = (t_rtv1 *)data;
	mid_w = W_WIDTH / 2;
	mid_h = W_HEIGHT / 2;
	while (1)
	{
		if (rt->t4 == 1)
		{
			ft_putstr("core 4\n");
			x = mid_w;
			while (++x < W_WIDTH)
			{
				y = mid_h;
				while (++y < W_HEIGHT)
					raytracing(x, y, rt->env);
			}
			rt->t4 = 0;
		}
		usleep(THREAD_SLEEP);
	}
	return (0);
}

/*
** THREAD4
** O O
** O X
*/

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
		ft_destroy_sdl(rt->env);
	}
}
