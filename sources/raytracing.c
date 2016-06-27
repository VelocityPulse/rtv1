/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 10:33:51 by cchameyr          #+#    #+#             */
/*   Updated: 2016/06/27 15:08:42 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

t_ptd3d		ft_normalize(t_ptd3d v)
{
	float	i;

	i = 1 / sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
	return (ft_make_ptd3d(v.x * i, v.y * i, v.z * i));
}

int		ft_intersection_sphere(t_sphere sphere, t_ray ray, int *t)
{
	t_vector	dist;
	float		b;
	float		d;
	double		t0;
	double		t1;
	int			ret;


	dist = ft_make_vector(sphere.x, sphere.y, sphere.z);
	b = (ray.d.x * dist.x) + (ray.d.y * dist.y) + (ray.d.z * dist.z);
	d = (b * b) - ((dist.x * dist.x) + (dist.y * dist.y) + (dist.z * dist.z)) + sphere.radius * sphere.radius;

	if (d < 0)
		return (0);
	t0 = b - sqrt(d);
	t1 = b + sqrt(d);
	ret = 0;

	if (t0 > 0.1 && t0 < *t)
	{
		*t = t0;
		ret = 1;
	}
	if (t1 > 0.1 && t1 < *t)
	{
		*t = t1;
		ret = 1;
	}
	return (ret);
}

void	raytracing(int x, int y, t_env *env)
{
	t_ptd3d		A;
	t_ptd3d		B;
	t_ptd3d		ray_dir;
	t_ray		ray;
	t_sphere	sphere;
	int			coef;
	int			inter;

	sphere.x = 0;
	sphere.y = 0;
	sphere.z = 30;
	sphere.radius = 10;
	A = ft_make_ptd3d(0, 0, 0);
	B = ft_make_ptd3d(x - (W_WIDTH / 2), y - (W_HEIGHT / 2),
			-(W_WIDTH / (2 * tan(30/2))));
	B = ft_normalize(B);
	ray_dir = ft_make_ptd3d(B.x - A.x, B.y - A.y, B.z - A.z);
	ray_dir = ft_normalize(ray_dir);
	ray.o = A;
	ray.d = ray_dir;
	coef = 4000;
	inter = ft_intersection_sphere(sphere, ray, &coef);
	int color = 0x22aa22;
	if ((inter > -1 || inter < -1) && coef < 4000)
		ft_memcpy(env->img->pixels + x * env->img->format->BytesPerPixel + y * env->img->pitch, &color, env->img->format->BytesPerPixel);
}
