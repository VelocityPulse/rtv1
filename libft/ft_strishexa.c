/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strishexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 10:57:26 by cchameyr          #+#    #+#             */
/*   Updated: 2016/06/24 14:55:02 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_back_number(char *str)
{
	int		i;

	i = -1;
	while (str[++i] == ' ')
		;
	if (str[i] == '-')
		i++;
	return (i);
}

static int		ft_strishexa_loop(char *str, int i)
{
	int		end;

	end = 0;
	while (str[i])
	{
		if (ft_ishexa(str[i]) && !end)
			;
		else if (str[i] == ' ')
			end = 1;
		else
			return (0);
		i++;
	}
	return (1);
}

int				ft_strishexa(char *str)
{
	int		i;
	char	*pref;

	i = ft_back_number(str);
	pref = ft_strstr(str, "0x");
	if (pref)
	{
		if (&str[i] != pref)
			return (0);
		i += 2;
	}
	return (ft_strishexa_loop(str, i));
}
