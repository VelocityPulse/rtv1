/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 12:16:14 by cchameyr          #+#    #+#             */
/*   Updated: 2016/06/14 12:49:22 by cchameyr         ###   ########.fr       */
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
# include "get_next_line.h"
# include "draw.h"
# include "libft.h"

# include "debug.h"

# define W_WIDTH 1080
# define W_HEIGHT 750

# define THREAD_SLEEP 1000

typedef struct	s_env
{
	SDL_Window		*win;
	SDL_Surface		*img;
	SDL_Event		events;
	int				width;
	int				height;
}				t_env;

typedef struct	s_ray
{
	t_ptd3d		o;
	t_ptd3d		d;
}				t_ray;

typedef struct	s_sphere
{
	int		x;
	int		y;
	int		z;
	int		radius;
}				t_sphere;

typedef struct	s_rtv1
{
	t_env	*env;
	bool	t1;
	bool	t2;
	bool	t3;
	bool	t4;
	int		scanvalue[285];
}				t_rtv1;

t_env			*ft_init_sdl(const int w, const int h, const char *name);
void			ft_destroy_sdl(t_env *env);

void			start(int ac, char **av);
void			ft_exit_rt(t_rtv1 *rt);

void			ft_open_scene(t_rtv1 *rt, int ac, char **av);

void			ft_create_thread(t_rtv1 *rt);
int				ft_thread1(void *data);
int				ft_thread2(void *data);
int				ft_thread3(void *data);
int				ft_thread4(void *data);

void			raytracing(int x, int y, t_env *env);

#endif
