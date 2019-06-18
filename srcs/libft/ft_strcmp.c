/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warharra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:01:33 by warharra          #+#    #+#             */
/*   Updated: 2019/04/12 09:54:58 by warharra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && (j == 0))
	{
		if (s1[i] != s2[i])
		{
			j = ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (j);
}
