/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_sdl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 14:59:38 by cchameyr          #+#    #+#             */
/*   Updated: 2016/06/15 15:41:47 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_destroy_sdl(t_env *env)
{
	if (env)
	{
		SDL_FreeSurface(env->img);
		SDL_DestroyWindow(env->win);
		SDL_Quit();
		ft_memdel((void **)&env);
	}
}
