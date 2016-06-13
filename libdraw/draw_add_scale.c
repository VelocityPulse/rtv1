/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_add_scale.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 12:35:37 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/15 12:23:26 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_pt3d		**ft_add_scale(t_pt3d **tab, t_pt size, t_pt3d scale)
{
	t_pt	p;

	p.y = 0;
	while (p.y <= size.y)
	{
		p.x = 0;
		while (p.x <= size.x)
		{
			tab[p.y][p.x].x *= scale.x;
			tab[p.y][p.x].y *= scale.y;
			tab[p.y][p.x].z *= scale.z;
			p.x++;
		}
		p.y++;
	}
	return (tab);
}
