/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warharra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:01:53 by warharra          #+#    #+#             */
/*   Updated: 2019/04/20 18:32:26 by warharra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_rev(char *str)
{
	int i;
	int temp;
	int j;

	i = 0;
	j = ft_strlen((const char*)str);
	j--;
	if (str[0] == '-')
		i++;
	while (i < j)
	{
		temp = str[i];
		str[i++] = str[j];
		str[j] = temp;
		j--;
	}
	return (str);
}

char				*ft_itoa(int n)
{
	char*res;
	int i;

	i = ft_len(n);
	if ((res = (char *)malloc(sizeof(char) * i)) == NULL)
		return (NULL);
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = 0;
	if (n < 0)
	{
		res[i++] = '-';
		n = n * -1;
	}
	while (n > 0 || n < 0)
	{
		res[i++] = ((n % 10) + '0');
		n = n / 10;
	}
	res[i] = '\0';
	res = ft_rev(res);
	return (res);
}
