/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warharra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 14:33:00 by warharra          #+#    #+#             */
/*   Updated: 2019/04/18 16:28:27 by warharra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *temp;
	t_list *map;

	if (!lst)
		return (NULL);
	temp = (*f)(lst);
	if (!(map = ft_lstnew(temp->content, temp->content_size)))
		return (NULL);
	new = map;
	lst = lst->next;
	while (lst)
	{
		temp = (*f)(lst);
		if (!(new->next = ft_lstnew(temp->content, temp->content_size)))
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (map);
}
