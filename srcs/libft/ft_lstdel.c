/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warharra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:11:20 by warharra          #+#    #+#             */
/*   Updated: 2019/04/18 16:28:03 by warharra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *dell;

	while (alst && *alst)
	{
		dell = *alst;
		(del)((*alst)->content, (*alst)->content_size);
		*alst = (*alst)->next;
		free(dell);
	}
	*alst = NULL;
}
