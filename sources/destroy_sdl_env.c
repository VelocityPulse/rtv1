/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_sdl_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 12:35:11 by cchameyr          #+#    #+#             */
/*   Updated: 2016/06/08 12:36:18 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/header.h"

void	ft_destroy_env(t_env *env)
{
	SDL_FreeSurface(env->img);
	SDL_Destroy_Window(env->win);
	SDL_Quit();
	ft_memdel((void **)&env);
}
