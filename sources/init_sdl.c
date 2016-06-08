/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 12:25:22 by cchameyr          #+#    #+#             */
/*   Updated: 2016/06/08 12:35:00 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

t_env	*ft_init_sdl(const int width, const int height, const char *name)
{
	t_env	*env;

	if (!(env = (t_env *)ft_memalloc(sizeof(t_env))))
		return (NULL);
	env->width = width;
	env->height = height;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) ||
	!(env->win = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED,
	SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN)) ||
	!(env->img = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0)))
	{
		ft_destroy_env(env);
		return (NULL);
	}
	return (env);
}
