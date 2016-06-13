/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_add_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 17:11:57 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/15 12:14:34 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_pt	**ft_add_pos(t_pt **tab, t_pt size, t_pt pos)
{
	t_pt	p;

	p.y = 0;
	while (p.y <= size.y)
	{
		p.x = 0;
		while (p.x <= size.x)
		{
			tab[p.y][p.x].x += pos.x;
			tab[p.y][p.x].y += pos.y;
			p.x++;
		}
		p.y++;
	}
	return (tab);
}
