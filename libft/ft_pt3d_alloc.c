/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pt3d_alloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 15:00:17 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/11 15:01:51 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_pt3d		**ft_pt3d_alloc(t_pt size)
{
	t_pt3d		**pt;
	int			i;

	i = 0;
	pt = (t_pt3d **)ft_memalloc(sizeof(t_pt3d *) * (size.y + 1));
	while (i <= size.y)
		pt[i++] = (t_pt3d *)ft_memalloc(sizeof(t_pt3d) * (size.x + 1));
	return (pt);
}

t_pt3d		**ft_free_pt3d(t_pt3d **tab_pts, int size)
{
	if (!tab_pts)
		return (NULL);
	size++;
	while (--size)
		ft_memdel((void **)&tab_pts[size]);
	ft_memdel((void **)tab_pts);
	return (tab_pts);
}
