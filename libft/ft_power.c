/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 14:37:08 by cchameyr          #+#    #+#             */
/*   Updated: 2016/06/15 14:39:07 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_power(int nb, int pow)
{
	int x;

	x = nb;
	while (pow > 1)
	{
		nb *= x;
		pow--;
	}
	return (nb);
}
