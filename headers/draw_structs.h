/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 12:10:37 by cchameyr          #+#    #+#             */
/*   Updated: 2016/06/13 11:21:37 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DRAW_STRUCTS_H
# define _DRAW_STRUCTS_H

# include "../headers/libft.h"

typedef struct	s_rgb
{
	int		r;
	int		g;
	int		b;
}				t_rgb;

typedef struct	s_dual_color
{
	t_rgb	c1;
	t_rgb	c2;
}				t_dual_color;

typedef struct	s_vector
{
	float		x;
	float		y;
	float		z;
}				t_vector;

typedef struct	s_matrix
{
	t_vector	x;
	t_vector	y;
	t_vector	z;
	t_pt		pos;
}				t_matrix;

typedef struct	s_matrix_rot
{
	t_matrix	mx;
	t_matrix	my;
	t_matrix	mz;
	t_matrix	m;
}				t_matrix_rot;

#endif
