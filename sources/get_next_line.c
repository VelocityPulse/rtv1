/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 17:48:37 by cchameyr          #+#    #+#             */
/*   Updated: 2016/06/14 13:21:30 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"

static char		*ft_get_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = ft_strncpy(ft_strnew(i), str, i);
	line[i] = 0;
	return (line);
}

static char		*ft_end_chain(char *str)
{
	int		i;
	char	*end_chain;

	i = 0;
	end_chain = NULL;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	end_chain = ft_strdup(&str[i + 1]);
	if (i == (int)ft_strlen(str))
		ft_memdel((void **)&end_chain);
	ft_memdel((void **)&str);
	return (end_chain);
}

static int		ft_alloc_gnl(char **save, t_gnl *g)
{
	if (!(g->buff = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	if (!*save)
	{
		if (!(*save = ft_strnew(1)))
			return (-1);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*save[256] = {NULL};
	t_gnl		g;

	if (((g.ret = 42)) && (ft_alloc_gnl(&save[fd % 256], &g) == -1))
		return (-1);
	while (!(ft_strchr(save[fd % 256], '\n')) && g.ret > 0)
	{
		if ((g.ret = read(fd, g.buff, BUFF_SIZE)) == -1)
			return (-1);
		g.buff[g.ret] = 0;
		g.temp = save[fd % 256];
		save[fd % 256] = ft_strjoin(save[fd % 256], g.buff);
		ft_memdel((void **)&g.temp);
	}
	ft_memdel((void **)&g.buff);
	*line = ft_get_line(save[fd % 256]);
	save[fd % 256] = ft_end_chain(save[fd % 256]);
	if ((int)ft_strlen(*line))
		return (1);
	if (g.ret == 0 && !save[fd % 256])
	{
		ft_memdel((void **)&save[fd % 256]);
		return (0);
	}
	return (1);
}
