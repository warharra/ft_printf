/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 15:12:56 by alperrin          #+#    #+#             */
/*   Updated: 2019/06/13 14:02:14 by warharra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_flag(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if(str[i] == c)
			return (1 << i);
		i = i + 1;
	}
	return (0);
}

void	get_flags(t_printf *pf)
{
	int res;
	int i;

	i = 0;
	while ((res = find_flag("#0-+ ", *pf->format)) && pf->format++)
	{
		pf->flags |= res;
		i = i + 1;
		printf(" mon petit flag %d avec i %d\n",pf->flags,i);
	}
//	((pf->flags & F_MINUS) && (pf->flags & F_ZERO)) ? pf->flags &= ~F_ZERO : 0;
//	((pf->flags & F_PLUS) && (pf->flags & F_SPACE)) ? pf->flags &= ~F_SPACE : 0;
}
void	get_flags2(t_printf *pf)
{
	int res;
	if((res = find_flag("hlLjz", *pf->format)))
	{
		res <<= 5;
		pf->format++;
		if(((res == 32) && (*pf->format == 'h')) || ((res == 128) && (*pf->format == 'l')))
		{
			res <<= 5;
			pf->format++;
		}
		pf->flags |= res;
	}
}
void	get_len(t_printf *pf)
{
	int len;
	if (*pf->format >= 48 && *pf->format <= 57)
	{
		len = ft_atoi(pf->format);
		if (len > 1)
			pf->min_len = len;
		else
			pf->min_len = 1;
	}
	if (*pf->format == '*')
	{
		pf->format++;
		if (*pf->format == 'd' || (*pf->format >= 48 && *pf->format <= 57))
		{
			pf->min_len = va_arg(pf->ap, int);
			if(*pf->format >= 48 && *pf->format <= 57)
			pf->min_len = ft_atoi(pf->format <= 57);
		}
	}
}

int		parse_args(t_printf *pf)
{
	printf("ret %d\nflags %d\n min_len %d\nprecision %d\n base %d\n neg %d\n pad %d\n buff_i %d\n buff %s\nformat %s\nconv %c\n", pf->ret, pf->flags, pf->min_len, pf->precision, pf->base, pf->neg, pf->pad, pf->buff_i, pf->buff, pf->format, pf->conv);
	get_flags(pf);
//	get_min_len(pf);
//	get_precision(pf);
	get_flags2(pf);
//	get_conversion(pf);
//	conv_to_fct(pf);
	printf("ret %d\nflags %d\n min_len %d\nprecision %d\n base %d\n neg %d\n pad %d\n buff_i %d\n buff %s\nformat %s\nconv %c\n", pf->ret, pf->flags, pf->min_len, pf->precision, pf->base, pf->neg, pf->pad, pf->buff_i, pf->buff, pf->format, pf->conv);
	return (1);
}

