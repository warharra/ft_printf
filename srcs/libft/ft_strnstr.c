/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warharra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:56:55 by warharra          #+#    #+#             */
/*   Updated: 2019/04/20 16:49:49 by warharra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t			len;
	size_t			i;
	size_t			tmp;

	len = ft_strlen((char*)to_find);
	if (len == 0)
		return ((char*)str);
	i = 0;
	while (str[i] != '\0' && (len + i) <= n)
	{
		tmp = 0;
		while (to_find[tmp] == str[tmp + i])
		{
			if (tmp == (len - 1))
				return ((char*)str + i);
			tmp++;
		}
		i++;
	}
	return (NULL);
}
