/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pt_alloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:45:35 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/04 17:49:37 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unistd.h"

t_pt	**ft_pt_alloc(t_pt size)
{
	t_pt	**pt;
	int		i;

	i = 0;
	pt = (t_pt **)ft_memalloc(sizeof(t_pt *) * (size.y + 1));
	while (i <= size.y)
		pt[i++] = (t_pt *)ft_memalloc(sizeof(t_pt) * (size.x + 1));
	return (pt);
}

t_pt	**ft_free_pt(t_pt **tab_pts, int size)
{
	if (!tab_pts)
		return (NULL);
	size++;
	while (--size)
		ft_memdel((void **)&tab_pts[size]);
	ft_memdel((void **)tab_pts);
	return (tab_pts);
}
