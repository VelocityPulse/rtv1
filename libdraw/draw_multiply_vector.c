/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_multiply_vector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 12:37:33 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/15 12:20:05 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_vector	ft_multiply_vector(t_vector v, float x, float y, float z)
{
	v.x *= x;
	v.y *= y;
	v.z *= z;
	return (v);
}
