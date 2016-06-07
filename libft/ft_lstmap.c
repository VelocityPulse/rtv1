/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <cchameyr@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 13:08:40 by cchameyr          #+#    #+#             */
/*   Updated: 2015/12/01 16:24:52 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *begin;
	t_list *list;

	begin = NULL;
	if (lst)
	{
		list = f(lst);
		begin = list;
		while (lst->next)
		{
			list->next = f(lst->next);
			list = list->next;
			lst = lst->next;
		}
		list = f(lst);
	}
	return (begin);
}
