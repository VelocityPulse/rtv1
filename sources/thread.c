/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 14:54:05 by cchameyr          #+#    #+#             */
/*   Updated: 2016/06/09 11:48:48 by cchameyr         ###   ########.fr       */
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
			printf("core 1\n");
			x = -1;
			while (++x < mid_w)
			{
				y = -1;
				while (++y < mid_h)
					; /* call core */
			}
			rt->t1 = 0;
		}
		usleep(THREAD_SLEEP);
	}
	return (0);
}

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
			printf("core 2\n");
			x = mid_w;
			while (++x <= W_WIDTH)
			{
				y = -1;
				while (++y < mid_h)
					; /* call core */
			}
			rt->t2 = 0;
		}
		usleep(THREAD_SLEEP);
	}
	return (0);
}

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
			printf("core 3\n");
			x = -1;
			while (++x < mid_w)
			{
				y = mid_h;
				while (++y <= W_HEIGHT)
					; /* call core */
			}
			rt->t3 = 0;
		}
		usleep(THREAD_SLEEP);
	}
	return (0);
}

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
			printf("core 4\n");
			x = mid_w;
			while (++x <= W_WIDTH)
			{
				y = mid_h;
				while (++y <= W_HEIGHT)
					; /* call core */
			}
			rt->t4 = 0;
		}
		usleep(THREAD_SLEEP);
	}
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
		ft_destroy_sdl(rt->env);
	}
}
