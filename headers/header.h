/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 12:16:14 by cchameyr          #+#    #+#             */
/*   Updated: 2016/06/21 10:31:42 by cchameyr         ###   ########.fr       */
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

typedef struct	s_cam
{
	double		x;
	double		y;
	double		z;
	t_vector	dir;
}				t_cam;

typedef struct	s_sphere
{
	double		x;
	double		y;
	double		z;
	double		radius;
	int			color;
	int			end;
}				t_sphere;

typedef struct	s_spot
{
	double	x;
	double	y;
	double	z;
	float	lux;
	int		end;
}				t_spot;

typedef struct	s_cylindre
{
	double		x;
	double		y;
	double		z;
	double		ray_size;
	double		height;
	int			color;
	t_vector	rot;
	int			end;
}				t_cylindre;

typedef struct	s_plan
{
	double		x;
	double		y;
	double		z;
	double		width;
	double		height;
	int			color;
	t_vector	rot;
	int			end;
}				t_plan;

typedef struct	s_cone
{
	double		x;
	double		y;
	double		z;
	double		ray_size;
	double		height;
	int			color;
	t_vector	rot;
	int			end;
}				t_cone;

typedef struct	s_cube
{
	double		x;
	double		y;
	double		z;
	double		size;
	int			color;
	t_vector	rot;
	int			end;

}				t_cube;

typedef struct	s_objects
{
	t_spot		*spot;
	t_sphere	*sphere;
	t_cylindre	*cylindre;
	t_plan		*plan;
	t_cone		*cone;
	t_cube		*cube;
}				t_objects;

typedef struct	s_rtv1
{
	t_env		*env;
	bool		t1;
	bool		t2;
	bool		t3;
	bool		t4;
	int			scanvalue[285];
	t_cam		cam;
	t_objects	obj;
}				t_rtv1;

t_env			*ft_init_sdl(const int w, const int h, const char *name);
void			ft_destroy_sdl(t_env *env);

int				error_line(const int line);
void			next_line(t_lstline **list, int *line);

void			start(char *path);
void			exit_rt(t_rtv1 *rt);

int				analyse_scene(t_rtv1 *rt, t_lstline *list);
int				analyse_3d_value_d(char *str, double *x, double *y, double *z);
int				analyse_3d_value_v(char *str, t_vector *v);
int				analyse_spot(t_spot **spot, t_lstline **list, int *line);
int				analyse_sphere(t_sphere **sphere, t_lstline **list, int *line);
int				analyse_cylindre(t_cylindre **cyl, t_lstline **list, int *line);
int				analyse_cone(t_cone **cone, t_lstline **list, int *line);
int				analyse_plan(t_plan **plan, t_lstline **list, int *line);

int				analyse_slash(char *str, int nb_value);
int				analyse_sphere_help(char *line, char **str, t_sphere *sphere);
int				analyse_cylindre_help(char *line, char **str, t_cylindre *cyl);
int				analyse_cone_help(char *line, char **str, t_cone *cone);
int				analyse_plan_help(char *line, char **str, t_plan *plan);

void			create_thread(t_rtv1 *rt);
int				ft_thread1(void *data);
int				ft_thread2(void *data);
int				ft_thread3(void *data);
int				ft_thread4(void *data);

void			raytracing(int x, int y, t_env *env);

#endif
