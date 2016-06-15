/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <cchameyr@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 12:55:51 by cchameyr          #+#    #+#             */
/*   Updated: 2016/06/15 14:40:12 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int	neg;
	int	cpt;
	int	n;

	n = 0;
	neg = 0;
	cpt = 0;
	while (str[cpt] == ' ' || str[cpt] == '\t' || str[cpt] == '\r' ||
		str[cpt] == '\n' || str[cpt] == '\v' || str[cpt] == '\f')
		cpt++;
	if (str[cpt] == '-')
		neg = 1;
	if (str[cpt] == '+' || str[cpt] == '-')
		cpt++;
	while (str[cpt] >= '0' && str[cpt] <= '9')
	{
		n = n * 10;
		n = n + (str[cpt] - 48);
		cpt++;
	}
	return (neg == 0 ? n : -n);
}

double		ft_atoid(char *str)
{
	double	result;
	int		i;
	char	*a;

	i = -1;
	a = NULL;
	result = 0;
	while (str[++i] != '.')
		if (str[i] == '\0')
			return (ft_atoi(str));
	a = &str[i + 1];
	i = -1;
	while (a[++i])
	{
		if (!ft_isdigit(a[i]))
			return (ft_atoi(str));
	}
	result = ft_atoi(str);
	result += (double)ft_atoi(a) / (double)ft_power(10, ft_strlen(a));
	return (result);
}
