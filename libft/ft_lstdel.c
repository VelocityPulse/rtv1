/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <cchameyr@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:16:44 by cchameyr          #+#    #+#             */
/*   Updated: 2015/12/01 16:57:53 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (del)(void *, size_t))
{
	t_list	*temp1;
	t_list	*temp2;

	if (alst && *alst)
	{
		temp1 = *alst;
		while (temp1)
		{
			temp2 = temp1->next;
			del(temp1->content, temp1->content_size);
			free(temp1);
			temp1 = temp2;
		}
		*alst = NULL;
	}
}
