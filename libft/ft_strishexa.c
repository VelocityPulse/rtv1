/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strishexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 10:57:26 by cchameyr          #+#    #+#             */
/*   Updated: 2016/06/24 12:06:42 by cchameyr         ###   ########.fr       */
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

int				ft_strishexa(char *str)
{
	int		i;
	int		end;
	char	*pref;

	end = 0;
	i = ft_back_number(str);
	pref = ft_strstr(str, "0x");
	if (pref)
	{
		if (str[i] != *pref)
			return (0);
		i += 2;
	}
	while (str[i])
	{
		if (ft_ishexa(str[i]) && !end)
			;
		else if (str[i] == ' ')
			end = 1;
		else
		{
			ft_putstr("YOLO\n");
			return (0);
		}
		i++;
	}
	return (1);

}
