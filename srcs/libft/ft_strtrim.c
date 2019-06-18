/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warharra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:20:09 by warharra          #+#    #+#             */
/*   Updated: 2019/04/19 11:22:09 by warharra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int i;
	int j;
	int k;
	char*str;

	if (s == NULL)
		return (NULL);
	i = 0;
	k = 0;
	j = ft_strlen((char*)s);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (s[i] == '\0')
		return (ft_strnew(0));
	j--;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	if (!(str = (char*)malloc(sizeof(char) * (j - i + 2))))
		return (NULL);
	while (s[i] != '\0' && i <= j)
	{
		str[k++] = s[i++];
	}
	str[k] = '\0';
	return (str);
}
