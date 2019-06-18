/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft-strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warharra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:59:40 by warharra          #+#    #+#             */
/*   Updated: 2019/04/19 10:10:38 by warharra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char tmp;

	tmp = s[0];
	while (*s != '\0')
		s++;
	if (*s == '\0' && *s == (char)c)
		return ((char*)s);
	s--;
	while (*s != tmp && *s != (char)c)
		s--;
	if (*s == (char)c)
		return ((char*)s);
	else
		return (NULL);
}
