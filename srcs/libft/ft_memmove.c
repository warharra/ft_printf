/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warharra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:03:18 by warharra          #+#    #+#             */
/*   Updated: 2019/04/22 11:44:11 by warharra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*cp_src;
	char	*cp_dest;

	cp_src = (char*)src;
	cp_dest = (char*)dest;
	if (cp_dest > cp_src)
	{
		cp_src = cp_src + n - 1;
		cp_dest = cp_dest + n - 1;
		while (n-- > 0)
			*cp_dest-- = *cp_src--;
	}
	else
	{
		while (n-- > 0)
			*cp_dest++ = *cp_src++;
	}
	return (dest);
}
