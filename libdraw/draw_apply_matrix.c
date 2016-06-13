/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_apply_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 12:22:23 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/15 12:22:24 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_pt	ft_apply_matrix(t_pt3d pt, t_matrix t)
{
	t_pt	new_pt;

	new_pt.x = (t.x.x * pt.x) + (t.x.y * pt.y) + (t.x.z * pt.z);
	new_pt.y = (t.y.x * pt.x) + (t.y.y * pt.y) + (t.y.z * pt.z);
	return (new_pt);
}
