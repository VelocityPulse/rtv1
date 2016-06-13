/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_init_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 12:17:13 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/15 12:17:18 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_matrix	ft_init_matrix(t_pt pos)
{
	t_matrix	m;

	m.x = ft_make_vector(0.0f, 0.0f, 0.0f);
	m.y = ft_make_vector(0.0f, 0.0f, 0.0f);
	m.z = ft_make_vector(0.0f, 0.0f, 0.0f);
	m.pos = pos;
	return (m);
}
