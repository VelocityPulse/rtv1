/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_make_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 12:19:30 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/15 12:19:32 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_matrix	ft_rotate_matrix_x(float rot)
{
	t_matrix	m;

	m.x = ft_make_vector(1.0f, 0.0f, 0.0f);
	m.y = ft_make_vector(0.0f, cosf(rot), -sinf(rot));
	m.z = ft_make_vector(0.0f, sinf(rot), cosf(rot));
	return (m);
}

t_matrix	ft_rotate_matrix_y(float rot)
{
	t_matrix	m;

	m.x = ft_make_vector(cosf(rot), 0.0f, sinf(rot));
	m.y = ft_make_vector(0.0f, 1.0f, 0.0f);
	m.z = ft_make_vector(-sinf(rot), 0.0f, cosf(rot));
	return (m);
}

t_matrix	ft_rotate_matrix_z(float rot)
{
	t_matrix	m;

	m.x = ft_make_vector(cosf(rot), -sinf(rot), 0.0f);
	m.y = ft_make_vector(sinf(rot), cosf(rot), 0.0f);
	m.z = ft_make_vector(0.0f, 0.0f, 1.0f);
	return (m);
}
