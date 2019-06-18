/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warharra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:40:28 by warharra          #+#    #+#             */
/*   Updated: 2019/04/15 15:56:15 by warharra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*cp_dest;
	const char	*cp_src;

	cp_dest = (char*)dest;
	cp_src = (char*)src;
	while (n-- > 0)
		*cp_dest++ = *cp_src++;
	return (dest);
}
