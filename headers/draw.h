/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 15:17:56 by cchameyr          #+#    #+#             */
/*   Updated: 2016/06/13 11:05:20 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DRAW_H
# define _DRAW_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "draw_structs.h"
# include "../headers/libft.h"

t_vector	ft_make_vector(float x, float y, float z);

t_matrix	ft_init_matrix(t_pt pos);
t_matrix	ft_multiply_matrix(t_matrix m1, t_matrix m2);
t_vector	ft_add_vector(t_vector v, float x, float y, float z);
t_vector	ft_multiply_vector(t_vector v, float x, float y, float z);

t_matrix	ft_rotate_matrix_x(float rot);
t_matrix	ft_rotate_matrix_y(float rot);
t_matrix	ft_rotate_matrix_z(float rot);
t_pt3d		**ft_add_scale(t_pt3d **tab, t_pt size, t_pt3d scale);
t_pt		**ft_add_pos(t_pt **tab, t_pt size, t_pt pos);

t_pt		ft_apply_matrix(t_pt3d pt, t_matrix m);
void		ft_array_layout(t_pt3d *pts, int size, t_pt *new_pt, t_matrix t);

t_rgb		ft_get_rgb(int hexa);
int			ft_get_hexa(t_rgb rgb);
int			ft_get_hexa_rgb(int r, int g, int b);
t_rgb		ft_find_color_gradient(t_dual_color c, int n, int p);
int			ft_divide_color(int color);

#endif
