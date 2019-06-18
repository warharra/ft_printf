/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warharra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:15:59 by warharra          #+#    #+#             */
/*   Updated: 2019/04/15 15:54:53 by warharra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *cp_s1;
	unsigned char *cp_s2;

	cp_s1 = (unsigned char*)s1;
	cp_s2 = (unsigned char*)s2;
	while (n > 0 && *cp_s1 == *cp_s2)
	{
		cp_s1++;
		cp_s2++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return (*cp_s1 - *cp_s2);
}
