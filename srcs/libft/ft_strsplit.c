/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warharra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:09:53 by warharra          #+#    #+#             */
/*   Updated: 2019/04/20 13:49:00 by warharra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_split(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static int			ft_word_len(char const *str, char c)
{
	int i;

	i = 0;
	if (str != NULL)
	{
		while (str[i] != '\0' && (ft_split(str[i], c) == 0))
			i++;
	}
	return (i);
}

static int			ft_word_cont(char const *str, char c)
{
	int word_len;
	int i;
	int n;

	i = 0;
	n = 0;
	if (str != NULL)
	{
		while (str[i] != '\0')
		{
			word_len = ft_word_len(&str[i], c);
			i = i + word_len + 1;
			n++;
		}
	}
	return (n);
}

char				**ft_strsplit(char const *s, char c)
{
	int i;
	int word_len;
	char**result;

	if ((result = malloc(sizeof(char*) * (ft_word_cont(s, c) + 1))) == NULL)
		return (NULL);
	i = 0;
	if (s == NULL)
		return (NULL);
	while (*s != '\0')
	{
		if ((word_len = ft_word_len(s, c)) > 0)
		{
			if ((result[i] = malloc(word_len + 1)) == NULL)
				return (NULL);
			ft_strncpy(result[i], s, word_len);
			*(result[i] + word_len) = '\0';
			s += word_len;
			i++;
		}
		else
			s += 1;
	}
	result[i] = NULL;
	return (result);
}
