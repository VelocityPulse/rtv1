/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 10:33:51 by cchameyr          #+#    #+#             */
/*   Updated: 2016/07/05 11:53:40 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

t_ptd3d		ft_normalize(t_ptd3d v)
{
	float	i;

	i = 1 / sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
	return (ft_make_ptd3d(v.x * i, v.y * i, v.z * i));
}

t_vector		ft_normalizev(t_vector v)
{
	float	i;

	i = 1 / sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
	return (ft_make_vector(v.x * i, v.y * i, v.z * i));
}

int		ft_intersection_plane(t_plane plane, t_ray ray, int *t)
{
	float		D;
	double		p;
	double		t0;
	int			ret;

	ret = 0;
//	ray.o = ft_make_ptd3d(ray.o.x + plane.x, ray.o.y + plane.y, ray.o.z + plane.z);
//	plane.rot = ft_normalizev(plane.rot);

	p = (plane.rot.x * ray.d.x) + (plane.rot.y * ray.d.y) + (plane.rot.z * ray.d.z);
	if (!p)
		return (ret);
	t0 = -((plane.rot.x * ray.o.x + plane.x) + (plane.rot.y * ray.o.y + plane.y) + (plane.rot.z * ray.o.z + plane.z)) / p;
	if (t0 > 0)
	{
		*t = t0;
		ret = 1;
	}
	return (ret);

}

int		ft_intersection_cone(t_cone cone, t_ray ray, int *t)
{
	float		D;
	double		t0;
	double		t1;
	int			ret;
	double		a;
	double		b;
	double		c;
	double		z1;
	double		z2;

	ray.o = ft_make_ptd3d(ray.o.x - cone.x, ray.o.y - cone.y, ray.o.z - cone.z);
	a = (cone.ray_size / 10) * (ray.d.x * ray.d.x) - (ray.d.y * ray.d.y) + (cone.ray_size / 10) * (ray.d.z * ray.d.z);
	b = (cone.ray_size / 10) * (2 * ray.o.x * ray.d.x) - (2 * ray.o.y * ray.d.y) + (cone.ray_size / 10) * (2 * ray.o.z * ray.d.z);
	c = (cone.ray_size / 10) * (ray.o.x * ray.o.x) - (ray.o.y * ray.o.y) + (cone.ray_size / 10) * (ray.o.z * ray.o.z);

	D = (b * b) - 4 * a * c;

	if (D < 0)
		return (0);
	t0 = (-b + sqrt(D)) / (2 * a);
	t1 = (-b - sqrt(D)) / (2 * a);

	z1 = ray.o.y + t0 * ray.d.y;
	z2 = ray.o.y + t1 * ray.d.y;

	ret = 0;
	if (t0 > 0.1 && t0 < *t && z1 > -cone.height / 2 && z1 < cone.height / 2)
	{
		*t = t0;
		ret = 1;
	}
	if (t1 > 0.1 && t1 < *t && z2 > -cone.height / 2 && z2 < cone.height / 2)
	{
		*t = t1;
		ret = 1;
	}
	return (ret);
}

int		ft_intersection_cylindre(t_cylindre cyl, t_ray ray, int *t)
{
	float		D;
	double		t0;
	double		t1;
	int			ret;
	double		a;
	double		b;
	double		c;
	double		z1;
	double		z2;

	ray.o = ft_make_ptd3d(ray.o.x - cyl.x, ray.o.y - cyl.y, ray.o.z - cyl.z);
	a = (ray.d.x * ray.d.x) + (ray.d.z * ray.d.z);
	b = (2 * ray.o.x * ray.d.x) + (2 * ray.o.z * ray.d.z);
	c = (ray.o.x * ray.o.x) + (ray.o.z * ray.o.z) - (cyl.ray_size * cyl.ray_size);

	D = (b * b) - 4 * a * c;

	if (D < 0)
		return (0);
	t0 = (-b + sqrt(D)) / (2 * a);
	t1 = (-b - sqrt(D)) / (2 * a);

	z1 = ray.o.y + t0 * ray.d.y;
	z2 = ray.o.y + t1 * ray.d.y;

	ret = 0;
	if (t0 > 0.1 && t0 < *t && z1 > -cyl.height / 2 && z1 < cyl.height / 2)
	{
		*t = t0;
		ret = 1;
	}
	if (t1 > 0.1 && t1 < *t && z2 > -cyl.height / 2 && z2 < cyl.height / 2)
	{
		*t = t1;
		ret = 1;
	}
	return (ret);
}

int		ft_intersection_sphere(t_sphere sphere, t_ray ray, int *t, double radius)
{
	t_vector	dist;
	float		D;
	double		t0;
	double		t1;
	int			ret;
	double		a;
	double		b;
	double		c;

	dist = ft_make_vector(sphere.x, sphere.y, sphere.z);
	ray.o = ft_make_ptd3d(ray.o.x - sphere.x, ray.o.y - sphere.y, ray.o.z - sphere.z);
	a = (ray.d.x * ray.d.x) + (ray.d.y * ray.d.y) + (ray.d.z * ray.d.z);
	b = (2 * ray.o.x * ray.d.x) + (2 * ray.o.y * ray.d.y) + (2 * ray.o.z * ray.d.z);
	c = (ray.o.x * ray.o.x) + (ray.o.y * ray.o.y) + (ray.o.z * ray.o.z) - (radius * radius);

	D = (b * b) - 4 * a * c;

	if (D < 0)
		return (0);
	t0 = (-b + sqrt(D)) / (2 * a);
	t1 = (-b - sqrt(D)) / (2 * a);
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
	t_cylindre	cyl;
	t_cone		cone;
	t_plane		plane;
	int			coef;
	int			inter;

	sphere.x = -13;
	sphere.y = 0;
	sphere.z = 30;
	sphere.radius = 5;

	cyl.x = 20;
	cyl.y = 0;
	cyl.z = 30;
	cyl.ray_size = 3;
	cyl.height = 10;

	cone.x = 0;
	cone.y = 0;
	cone.z = 30;
	cone.ray_size = 15;
	cone.height = 20;

	plane.x = 0;
	plane.y = 0;
	plane.z = 40;
	plane.rot = ft_make_vector(M_PI / 2, M_PI / 2, M_PI / 2);

	A = ft_make_ptd3d(0, 0, 0);
	B = ft_make_ptd3d(x - (W_WIDTH / 2), y - (W_HEIGHT / 2),
			-(W_WIDTH / (2 * tan(30/2))));
	B = ft_normalize(B);
	ray_dir = ft_make_ptd3d(B.x - A.x, B.y - A.y, B.z - A.z);
	ray_dir = ft_normalize(ray_dir);
	ray.o = A;
	ray.d = ray_dir;
	int color = 0xff2200;

		coef = 4000;
	inter = ft_intersection_plane(plane, ray, &coef);
	if ((inter > -1 || inter < -1) && coef < 4000)
		ft_memcpy(env->img->pixels + x * env->img->format->BytesPerPixel +
		y * env->img->pitch, &color, env->img->format->BytesPerPixel);
	color = 435354;
	coef = 4000;
	inter = ft_intersection_sphere(sphere, ray, &coef, sphere.radius);
	if ((inter > -1 || inter < -1) && coef < 4000)
		ft_memcpy(env->img->pixels + x * env->img->format->BytesPerPixel +
		y * env->img->pitch, &color, env->img->format->BytesPerPixel);
	coef = 4000;
	color = 0x00ff00;
	inter = ft_intersection_cylindre(cyl, ray, &coef);
	if ((inter > -1 || inter < -1) && coef < 4000)
		ft_memcpy(env->img->pixels + x * env->img->format->BytesPerPixel +
		y * env->img->pitch, &color, env->img->format->BytesPerPixel);
		coef = 4000;
	color = 0x0000ff;
	inter = ft_intersection_cone(cone, ray, &coef);
	if ((inter > -1 || inter < -1) && coef < 4000)
		ft_memcpy(env->img->pixels + x * env->img->format->BytesPerPixel +
		y * env->img->pitch, &color, env->img->format->BytesPerPixel);


}
