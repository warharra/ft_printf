/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warharra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 09:55:21 by warharra          #+#    #+#             */
/*   Updated: 2019/04/19 14:08:58 by warharra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define CHAR_SET " \t\n\v"

static int		contains(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

static int		get_word_len(char *str, char *charset)
{
	int i;

	i = 0;
	while (str[i] != 0 && !contains(str[i], charset))
	{
		i++;
	}
	return (i);
}

static int		get_word_count(char *str, char *charset)
{
	int word_len;
	int n;
	int i;

	n = 0;
	i = 0;
	while (str[i] != '\0')
	{
		word_len = get_word_len(str, charset);
		if (word_len > 0)
		{
			n++;
			i += word_len;
		}
		else
		{
			i++;
		}
	}
	return (i);
}

char			**ft_split_whitespaces(char *str)
{
	int i;
	int word_count;
	int word_len;
	char**result;

	word_count = get_word_count(str, CHAR_SET);
	result = (char**)malloc(sizeof(char*) * (word_count + 1));
	i = 0;
	while (*str != '\0')
	{
		word_len = get_word_len(str, CHAR_SET);
		if (word_len > 0)
		{
			result[i] = (char*)malloc(word_len + 1);
			ft_strncpy(result[i], str, word_len);
			*(result[i] + word_len) = '\0';
			str += word_len;
			i++;
		}
		else
			str += 1;
	}
	result[i] = 0;
	return (result);
}
