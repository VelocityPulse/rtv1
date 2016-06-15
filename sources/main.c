/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 11:22:35 by cchameyr          #+#    #+#             */
/*   Updated: 2016/06/15 15:54:10 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int		main(int argc, char **argv)
{
	if (argc == 2)
		start(argv[1]);
	else if (argc > 2)
		ft_putendl("\n\033[31mERROR\033[0m\nToo much arguments");
	else
		ft_putendl("\n\033[31mERROR\033[0m\nPrecise a scene");
	return (0);
}
