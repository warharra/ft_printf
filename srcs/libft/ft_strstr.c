/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warharra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:22:57 by warharra          #+#    #+#             */
/*   Updated: 2019/04/19 10:08:29 by warharra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int len;

	len = ft_strlen(to_find);
	if (len == 0)
		return (char*)(str);
	while (*str)
	{
		if (!ft_strncmp(str, to_find, len))
			return (char*)(str);
		str++;
	}
	return (0);
}
