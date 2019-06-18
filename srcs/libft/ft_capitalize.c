/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capitalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warharra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 09:45:18 by warharra          #+#    #+#             */
/*   Updated: 2019/04/19 11:26:24 by warharra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		espac(char c)
{
	if (c == ' ' || c == '+' || c == '-')
		return (1);
	return (0);
}

static char		mini(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

static char		capit(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

char			*ft_capitalize(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = mini(str[i]);
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0)
			str[i] = capit(str[i]);
		else if (espac(str[i]) == 1)
			str[i + 1] = capit(str[i + 1]);
		i++;
	}
	return (str);
}
