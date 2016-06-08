/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 12:16:14 by cchameyr          #+#    #+#             */
/*   Updated: 2016/06/08 12:25:03 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HEADER_H
# define _HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <math.h>
# include "../SDL2-2.0.4/include/SDL.h"
# include "libft.h"

# include "debug.h"

# define W_WIDTH 1080
# define W_HEIGHT 750

typedef struct	s_env
{
	SDL_Window		*win;
	SDL_Surface		*img;
	SDL_Event		events;
	int				width;
	int				height;
}				t_env;

typedef struct	s_rtv1
{
	t_env	*env;
	bool	t1;
	bool	t2;
	bool	t3;
	bool	t4;
	bool	refresh;
	int		scanvalue[285];
}				t_rtv1;

t_env	*ft_init_sdl(const int width, const int height, const char *name);
void	ft_destroy_env(t_env *env);

void	start(void);

#endif
